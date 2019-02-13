#Submitter: dereky1(Yang, Derek)
import re

# Before running the driver on the bsc.txt file, ensure you have put a regular
#   expression pattern in the files repattern1a.txt, repattern1b.txt, and
#   repattern2a.txt. 

# Use days_in and is_leap_year in your advance_to function

day_dict ={ 1 : 31,
            2 : 28,
            3 : 31,
            4 : 30,
            5 : 31,
            6 : 30,
            7 : 31,
            8 : 31,
            9 : 30,
           10 : 31, 
           11 : 30,
           12 : 31} 

def is_leap_year(month:int)->bool:
    return (month%4 == 0 and month%100 != 0) or month%400==0

def days_in(month:int, year:int)->int:
    return (29 if month==2 and is_leap_year(year) else day_dict[month])


def future_date(date:str, advance:int, year_now:int) -> str:
    pattern = '^(1[0-2]|[1-9](?!\d))/(?!$|/)(\s|[0-3])(?!$|\s)\d($|/\d\d)$'
    search = re.compile(pattern)
    result = search.match(date)
    no_year = False
    assert result is not None, "illegal date entered"
    try:
        month,day,year = [int(x) for x in result.group(0).strip().split('/')]
    except:
        month,day = [int(x) for x in result.group(0).strip().split('/')]
        year = year_now
        no_year = True
    assert day <= days_in(month,year), "day is illegal for month and year"
    assert advance >= 0, "Cannot time travel back in time... yet"

    for days in range(advance):
        day += 1
        if int(day) > days_in(int(month),year):
            month += 1
            day = 1
            if month > 12:
                year += 1
                month = 1
    
    return ('{}/{}'.format(month, day) if no_year else '{}/{}/{}'.format(month,day,year))
    

def compare_files(f1 : open, f2 : open) -> [(int,str,str)]:
    return_list = []

    count = 0
    for lines in f1:
        count += 1
        for lines_2 in f2:
            if lines != lines_2:
                return_list.append((count,lines.strip(),lines_2.strip()))
            break
                
    return return_list
    
if __name__ == '__main__':
    # Put your own function calls here to test the regular expressions
    #   or functions
    import driver
#     driver.default_show_traceback = True
#     driver.default_show_exception = True
#     driver.default_show_exception_message = True
    driver.driver()
