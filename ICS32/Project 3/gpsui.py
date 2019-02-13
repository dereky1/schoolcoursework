#Project 3: Ride Across the River
#Derek Yang
#63118832
#GPS User Interface Module


import gpsapi
import gpsoutput


#main user interface function
def start_gps():

    execution_list = []
    parameter_inputs = []

    location_inputs = get_user_input() 
    parameter_input = get_user_input()
    
    json_text = gpsapi.get_results(gpsapi.build_url(location_inputs))

    if gpsapi.check_json(json_text) == False:
        print("\n")
        print("NO ROUTE FOUND")
        raise SystemExit

    for param in parameter_input:
        parameter_inputs.append(param.upper())

    if 'ELEVATION' in parameter_inputs or 'LATLONG' in parameter_inputs:
        latlong_list = gpsapi.build_latlong(json_text)
        latlong_str = latlong_list[0]
        latlong_sep = latlong_list[1]
               
    for parameters in range(len(parameter_inputs)):   
                        
        if parameter_inputs[parameters] == 'STEPS':
            STEPS = gpsoutput.StepsOutput()
            STEPS.value = gpsapi.build_directions(json_text)
            execution_list.append(STEPS)
                        
        elif parameter_inputs[parameters] =='TOTALDISTANCE':
            TOTALDISTANCE = gpsoutput.DistanceOutput()
            TOTALDISTANCE.value = gpsapi.build_distance(json_text)
            execution_list.append(TOTALDISTANCE)
            
        elif parameter_inputs[parameters] =='TOTALTIME':
            TOTALTIME = gpsoutput.TimeOutput()
            TOTALTIME.value = gpsapi.build_time(json_text)
            execution_list.append(TOTALTIME)
                        
        elif parameter_inputs[parameters] =='LATLONG':
            LATLONG = gpsoutput.LatLongOutput()
            LATLONG.value = latlong_str
            execution_list.append(LATLONG)
                        
        elif parameter_inputs[parameters] =='ELEVATION':
            ELEVATION = gpsoutput.ElevationOutput()
            elevations_list = []
            temp_list = []

            for locations in range(len(location_inputs)):
                sep_elevation_json = gpsapi.get_results(gpsapi.build_elevation_url(latlong_sep[locations]))
                temp_list.append(gpsapi.build_elevation(sep_elevation_json))
        
            for elements in temp_list:
                for element in elements:
                    elevations_list.append(element)
                    
            ELEVATION.value = elevations_list
            execution_list.append(ELEVATION)
            
    COPYRIGHTS = gpsoutput.CopyrightsOutput()
    execution_list.append(COPYRIGHTS)        
    gpsoutput.Execute_Outputs(execution_list)


#gets user imputs 
def get_user_input():

    num_of_inputs = int(input(""))
    
    list_of_imputs = []
    
    for inputs in range(num_of_inputs):
        list_of_imputs.append(input(""))
        
    return list_of_imputs
    













if __name__ == '__main__':
    start_gps()
