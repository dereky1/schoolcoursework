#Derek Yang
#63118832
#ICS 33 Quiz 1

#from collections import defaultdict

# Associates grades (str) with grade points (float)
UCI = {'A+': 4.0, 'A': 4.0, 'A-': 3.7,
       'B+': 3.3, 'B': 3.0, 'B-': 2.7,
       'C+': 2.3, 'C': 2.0, 'C-': 1.7,
       'D+': 1.3, 'D': 1.0, 'D-': 0.7,
       'F': 0.0}


def  derivative(f : callable, delta : float) -> callable:
    if delta <= 0:
        raise AssertionError
    
    def derive(x : int) -> 'derivative':
        return (f(x+delta)-f(x))/delta
    
    return derive

def keys_with (d : {str:int}) -> callable:   
    def find(parameter) -> 'dictionary':
        return_set = set()
        keys = list(d.keys())
        value = list(d.values())

        if type(parameter) == str:
            return d[parameter]
        else:
            for x in range(len(keys)):
                if value[x] == int(parameter):
                    return_set.add(keys[x])
        return  return_set
    
    return find

def flatten (db : {str:{(str,str)}}) -> [(str,str,str)]:
    return_set = set()
    
    for keys in db.keys():
        for items in db[keys]:
            x = keys
            y,z = items
            item = (x,y,z)
            return_set.add(item) 
    
    return return_set


def roster (db : {str:{(str,str)}}) -> {str:[str]}:
    return_dict = {}
    
    for key in sorted(db.keys()):
        name_list = []
        for name in sorted(db[key]):
            x = name[0]
            name_list.append(x)
            
        return_dict[key] = name_list   
    return return_dict


def averages (db : {str:{(str,str)}}) -> {str:float}:
    return_dict = {}
    
    for key in db.keys():
        total = 0
        count = 0
        for grade in db[key]:
            x = grade[1]
            total += UCI[x]
            count += 1  
        return_dict[key] = total/count
    
    return return_dict


def grades1 (db : {str:{(str,str)}}) -> {str:[(str,float)]}:
    return_dict = {}
    
    for key in sorted(db.keys()):
        temp_list = []
        for x,y in sorted(db[key], key=lambda t: (-UCI[t[1]],t[0])):
            item = (x, UCI[y])
            temp_list.append(item)
        return_dict[key] = temp_list
    return return_dict

def grades2 (db : {str:{(str,str)}}) -> {str:[str]}:
    return_dict = {}
    
    for key in sorted(db.keys(),reverse = True):
        temp_list = []
        for item in sorted(db[key], key=lambda t: (-UCI[t[1]],t[0])):
            x = item[0]
            temp_list.append(x)
        return_dict[key] = temp_list
    
    return return_dict

def student_view (db : {str:{(str,str)}}) -> {str:{(str,str)}}:
    return_dict = {}
    
    for key in db.keys():
        for name,grade in db[key]:
            if name in return_dict.keys():
                temp_set = return_dict[name]
                temp_set.add((key,grade))
                return_dict[name] = temp_set
            else:
                return_dict[name]={(key,grade)}     
                
    return return_dict
            
def student_averages (db : {str:{(str,str)}}) -> {str:float}:
    return_dict = {}
    temp_dict = {}
    
    for key in db.keys():
        for name,grade in db[key]:
            if name in temp_dict.keys():
                temp_list = [temp_dict[name]]
                temp_list.append(grade)
                temp_dict[name] = temp_list
            else:
                temp_dict[name]=(grade)   

            total = 0
            count = 0  
            if type(temp_dict[name]) == list:      
                for grades in temp_dict[name]:
                    total += UCI[grades]
                    count += 1
                    return_dict[name] = total/count
            else:
                total += UCI[temp_dict[name]]
                count += 1
                return_dict[name] = total/count
        
    return return_dict
 
if __name__ == '__main__':
    from goody import irange
    from math import log
    # Feel free to test other cases as well
    
    print('Testing derivative')
    d = derivative (lambda x : 3*x**2 + 2*x - 2, .000001)
    print( [(a,d(a)) for a in irange(0,10)] )
    d = derivative (lambda x : log(x), .000001) # derivative of log(x) is 1/x
    print( [(a,d(a)) for a in irange(1,10)] )
    
    print('\nTesting keys_with')
    d = {'A':3,'B':2,'C':3,'D':2,'E':2,'F':4,'G':1,'H':4}
    kw = keys_with(d)
    print([(x,kw(x)) for x in sorted(set(d.values()))])
    d = {'A':1,'B':4,'C':2,'D':3,'E':1,'F':8,'G':3,'H':6,'I':4,'J':1}
    kw = keys_with(d)
    print([(x,kw(x)) for x in sorted(set(d.values()))])
         
    print('\nTesting flatten')
    db = {'ICS-31': {('Bob', 'A'), ('David', 'C'), ('Carol', 'B')},
          'Math-3A': {('Bob', 'B'), ('Alice', 'A')}} 
    print(flatten(db))
 
    print('\nTesting roster')
    db = {'ICS-31': {('Bob', 'A'), ('David', 'C'), ('Carol', 'B')},
          'Math-3A': {('Bob', 'B'), ('Alice', 'A')}} 
    print(roster(db))
 
    print('\nTesting averages')
    db = {'ICS-31': {('Bob', 'A'), ('David', 'C'), ('Carol', 'B')},
          'Math-3A': {('Bob', 'B'), ('Alice', 'A')}} 
    print(averages(db))
 
    print('\nTesting grades1')
    db = {'ICS-31': {('Bob', 'A'), ('David', 'C'), ('Carol', 'B')},
          'Math-3A': {('Bob', 'B'), ('Alice', 'A')}} 
    print(grades1(db))
 
    print('\nTesting grades2')
    db = {'ICS-31': {('Bob', 'A'), ('David', 'C'), ('Carol', 'B'), ('Zeke','B')},
          'Math-3A': {('Bob', 'B'), ('Alice', 'A')}} 
    print(grades2(db))
 
    print('\nTesting student_view')
    db = {'ICS-31': {('Bob', 'A'), ('David', 'C'), ('Carol', 'B')},
          'Math-3A': {('Bob', 'B'), ('Alice', 'A')}} 
    print(student_view(db))
     
    
    print('\nTesting student_averages')
    db = {'ICS-31': {('Bob', 'A'), ('David', 'C'), ('Carol', 'B')},
          'Math-3A': {('Bob', 'B'), ('Alice', 'A')}} 
    print(student_averages(db))
     
    print('\ndriver testing with batch_self_check:')
    import driver
#     driver.default_show_traceback = True
#     driver.default_show_exception = True
#     driver.default_show_exception_message = True
    driver.driver()           
