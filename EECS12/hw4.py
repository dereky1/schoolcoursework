#hw4.py
#Calendar from years 1800-2099
#Derek Yang
#63118832

from math import*

def main():

#Constant Data
    month_names = ['January','February','March','April','May','June','July','August','September','October','November','December']
    week_names = ['Su','Mo','Tu','We','Th','Fr','Sa']
    Week_Names = ['Sunday','Monday','Tuesday','Wednesday','Thursday','Friday','Saturday']
    days_in_month = ['31','28','31','30','31','30','31','31','30','31','30','31']
    days = ['1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30','31']
    janu = 31
    febu = 28
    marc = 31 
    apri = 30 
    mayy = 31 
    june = 30
    july = 31  
    augu = 31  
    sept = 30 
    octob = 31 
    nove = 30 
    dece = 31
    print("This Program will display a calendar for a given year and month")
#Checking Year
    time = 1
    while time == 1:
        year = int(input("Enter year (YYYY 1800 - 2099)(-1 to quit): "))
        if year == -1:
            break
            quit()
        while year < 1800 or year > 2099:
            print("'invalid' number entered")
            year = int(input("Enter year (YYYY 1800 - 2099)(-1 to quit): "))
#Checking Month
        month = int(input("Enter Month (1-12): "))        
        while month < 1 or month > 12:
            print("'invalid' number entered")
            month = int(input("Enter Month (1-12): "))
#Check for Leap Year   
        if year % 4 == 0 and year % 100 !=0:
            leapyear = year
            febu = 29
            days_in_month[1] = '29'
        else:
            leapyear = 0
#Checking For First Day of Year
        cent_digits = floor(year/100)
        if year >= 2000:
            year_digits = year - 2000
        elif 1900 >= year < 2000:
            year_digits = year - 1900
        else:
            year_digits = year - 1800
        value = year_digits + floor(year_digits/4)
        if cent_digits == 18:
            value = value + 2
        else:
            value = value + 6
        if leapyear == year:
            value = value
        else:
            value = value + 1
        value = (value + 1)%7
        if value != 0:
            value = value - 1
        else:
            value = value + 6   
#Checking For First Day of Month
        if month == 1:
            print("First day is: ", Week_Names[value])
        if month == 2:
            if value == 0 or value == 1 or value == 2 or value == 3:
                value = value + (janu%7)
            else:
                value = value + (janu%7) - 7
            print("First day is: ", Week_Names[value])
        if month == 3:
            value = value + ((janu+febu)%7)
            if value > 6:
                value = value - 7
            if febu == 29:
                value = value 
            print("First day is: ", Week_Names[value])
        if month == 4:
            value = value + ((janu+febu+marc)%7)
            if value > 6:
                value = value - 7
            if febu == 29:
                value = value 
            print("First day is: ", Week_Names[value])
        if month == 5:
            value = value + ((janu+febu+marc+apri)%7)
            if value > 6:
                value = value - 7
            if febu == 29:
                value = value
            print("First day is: ", Week_Names[value])
        if month == 6:
            value = value + ((janu+febu+marc+apri+mayy)%7)
            if value > 6:
                value = value - 7
            if febu == 29:
                value = value  
            print("First day is: ", Week_Names[value])
        if month == 7:
            value = value + ((janu+febu+marc+apri+mayy+june)%7)
            if value > 6:
                value = value - 7
            if febu == 29:
                value = value 
            print("First day is: ", Week_Names[value])
        if month == 8:
            value = value + ((janu+febu+marc+apri+mayy+june+july)%7)
            if value > 6:
                value = value - 7
            if febu == 29:
                value = value 
            print("First day is: ", Week_Names[value])
        if month == 9:
            value = value + ((janu+febu+marc+apri+mayy+june+july+augu)%7)
            if value > 6:
                value = value - 7
            if febu == 29:
                value = value 
            print("First day is: ", Week_Names[value])
        if month == 10: 
            value = value + ((janu+febu+marc+apri+mayy+june+july+augu+sept)%7)
            if value > 6:
                value = value - 7
            if febu == 29:
                value = value 
            print("First day is: ", Week_Names[value])
        if month == 11:
            value = value + ((janu+febu+marc+apri+mayy+june+july+augu+sept+octob)%7)
            if value > 6:
                value = value - 7
            if febu == 29:
                value = value 
            print("First day is: ", Week_Names[value])
        if month == 12:
            value = value + ((janu+febu+marc+apri+mayy+june+july+augu+sept+octob+nove)%7)
            if value > 6:
                value = value - 7
            if febu == 29:
                value = value 
            print("First day is: ", week_names[value]) 
#Print Calendar
        print(month_names[month-1],year)
        print('',week_names[0],week_names[1],week_names[2],week_names[3],week_names[4],week_names[5],week_names[6])
        days = (days_in_month[month-1])
        days = int(days)
        x = 0
        count = value - 1
        if value < 0:
            value = value + 7
            count = count + 7
            for i in range (value):
                print(format('','3'), end='')
        else:
            for i in range (value):
                print(format('','3'), end='')
        for i in range (days):
            x = x + 1
            sx = str(x)
            count = count + 1
            if count == 7:
                count = 0
                print("")
            print(sx.rjust(3), end='')
        print()
main()
        
    

        
    

    

