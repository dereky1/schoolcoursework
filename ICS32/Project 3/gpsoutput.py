#Project 3: Ride Across the River
#Derek Yang
#63118832
#GPS Output Module

import gpsapi
import gpsui


#the following classes are for each type of output of the program
class StepsOutput:
    def __init__(self):
        self.value = []
        
    def printout(self):
        print('\nDIRECTIONS')
        for step in self.value:
            print(step)


class DistanceOutput:
    def __init__(self):
        self.value = []
        
    def printout(self):
        print('\nTOTAL DISTANCE: ' + self.value + ' Miles')


class TimeOutput:
    def __init__(self):
        self.value = []
        
    def printout(self):
        print('\nTOTAL TIME: ' + self.value + ' Minutes')


class LatLongOutput:
    def __init__(self):
        self.value = []
        
    def printout(self):
        print('\nLATLONGS')
        for lat in self.value:
            print(lat)


class ElevationOutput:
    def __init__(self):
        self.value = []
        
    def printout(self):
        print('\nELEVATIONS')
        for elev in self.value:
            print(elev)


class CopyrightsOutput:
    def __init__(self):
        self.value = '\nDirections Courtesy of MapQuest; Map Data Copyright OpenStreetMap Contributors.'

    def printout(self):
        print(self.value)


#runs prints the values of the classes inputed        
def Execute_Outputs(outputs):
    
    for output in outputs:
        current_output = output.printout()

    return current_output




    




