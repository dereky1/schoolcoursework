#Project 3: Ride Across the River
#Derek Yang
#63118832
#GPS API Module

import json
import urllib.parse
import urllib.request
import gpsoutput
import gpsui


EXISTS = 'EXISTS'
MAPQUEST_API_KEY = 'WKuWQnUQQSX4no2TPI1LyGhdwWwJGJBD'
BASE_MAPQUEST_URL = 'http://open.mapquestapi.com/directions/v2/route?key='
MAPQUEST_ELEVATION_URL = 'http://open.mapquestapi.com/elevation/v1/profile?key='
ELEVATION_TO_FEET = '&unit=f&'


#function to build basic mapquest url
def build_url(locations_list):
    
    
    first_parameter = None

    for locations in locations_list:
        if first_parameter == None:
            location_parameters = [('from', locations)]
            first_parameter = EXISTS
        else:
            location_parameters += [('to', locations)]
    

    return BASE_MAPQUEST_URL + MAPQUEST_API_KEY + '&' + urllib.parse.urlencode(location_parameters)


#function to build mapquest elevation url
def build_elevation_url(latlongs):


    return MAPQUEST_ELEVATION_URL + MAPQUEST_API_KEY + ELEVATION_TO_FEET + '&latLngCollection=' + latlongs

    
#get json text from url
def get_results(url):


    response = None

    try:
        response = urllib.request.urlopen(url)
        json_text = response.read().decode(encoding = 'utf-8')
        return json.loads(json_text)

    except:
        print("\n")
        print("MAPQUEST ERROR")
        raise SystemExit
        
    finally:
        if response != None:
            response.close()


#checks whether route was found or not
def check_json(json_text):


    error_code = json_text["route"]["routeError"]["errorCode"]

    if error_code == 0:
        return False
    else:
        return True
    

#makes the list of directions
def build_directions(json_text):


    directions_list = []
    temp_list = (json_text["route"]["legs"])
    for narrative in range(len(temp_list)):
        for elements in temp_list[narrative]["maneuvers"]:
            directions_list.append(elements["narrative"])
    return directions_list

        
#finds the total distance
def build_distance(json_text):


    distance = json_text["route"]["distance"]
    return str(round(distance))


#finds the total time
def build_time(json_text):


    time = json_text["route"]["time"]
    return str(round(time/60))


#create a latlong list for output and building elevation urls
def build_latlong(json_text):

    
    latlong_list = []
    latlong_str = []
    latlong_sep = []
    temp_list = []
    NS = None
    WE = None
    temp_var = ''
    
    for num in range(len(json_text["route"]["locations"])):
        lat = json_text["route"]["locations"][num]["latLng"]["lat"]
        long = json_text["route"]["locations"][num]["latLng"]["lng"]
            
        if lat > 0:
            new_lat = lat
            NS = 'N '
        else:
            new_lat = abs(lat)
            NS = 'S '

        if long < 0:
            new_long = abs(long)
            WE = 'W'
        else:
            new_long = long
            WE = 'E'
            
        latlong = str("%.2f" % round(new_lat,2)) + NS + str("%.2f" % round(new_long,2)) + WE
        latlong_str.append(latlong)
        
        sep_longlat = str(lat) + ',' + str(long)
        latlong_sep.append(sep_longlat)
  
    latlong_list.extend((latlong_str, latlong_sep))
    
    return latlong_list

    
#finds the elevation    
def build_elevation(json_text):


    elevation_list = []
                
    for num in range(len(json_text["elevationProfile"])):
        elevation = json_text["elevationProfile"][num]["height"]
        elevation_list.append(round(elevation))

    return elevation_list
    

