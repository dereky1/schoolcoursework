# Submitter: dereky1(Yang, Derek)
from collections import defaultdict # Use defaultdict for prefix and query

def all_prefixes(fq : (str,)) -> {(str,)}:
    
    return_set = set()
    temp_str = ()
    for strings in range(len(fq)):
        temp_str += (fq[strings], )
        return_set.add(temp_str)

    return set(sorted(return_set))


def add_query(prefix : {(str,):{(str,)}}, query : {(str,):int}, new_query : (str,)) -> None:
    
    query[new_query] += 1
    for elements in all_prefixes(new_query):        
        prefix[elements].add(new_query)        

def read_queries(open_file : open) -> ({(str,):{(str,)}}, {(str,):int}):
    prefix_dict = defaultdict(set)
    query_dict = defaultdict(int)
    temp_list = []
    for lines in open_file:
        line = lines.strip().split(' ')
        query_dict[tuple(line)] += 1
        
    for keys in query_dict.keys():
        for elements in sorted(all_prefixes(keys)):
            if elements not in temp_list:
                temp_list.append(elements)  
    this = ()
    for element in temp_list:
        for keys in query_dict.keys():
            if len(element) <= len(keys) and list(element)[len(element)-1] == list(keys)[len(element)-1]:
                this += (keys,)
        prefix_dict[element] = set(this)
        this = ()
                    
    return (dict(prefix_dict), dict(query_dict))

def dict_as_str(d : {None:None}, key : callable=None, reverse : bool=False) -> str:
    return_str = ''
    for keys in sorted(d.keys(), key = key, reverse = reverse): 
        return_str += '  ' + str(keys) + ' -> ' + str(d[keys]) + '\n'
    
    return return_str

def top_n(a_prefix : (str,), n : int, prefix : {(str,):{(str,)}}, query : {(str,):int}) -> [(str,)]:
    return_list = []
    
    for num in range(n):
        item = sorted(query, key = lambda x: x[-1])[num]
        if a_prefix == item[:len(a_prefix)]:
            return_list.append(item)

    return return_list

# Script

if __name__ == '__main__':
    #Write script here
    
    a = read_queries(open(input('Enter the name of a file with the full queries:')))
    print(a)
    b = read_queries(a)
    prefix, query = b
    print('Prefix dictionary:\n')
    print(dict_as_str(prefix))
    print('Query dictionary:\n')
    print(dict_as_str(query))
    
   
    # For running batch self-tests
    print()
    import driver
    driver.default_file_name = "bsc5.txt"
#     driver.default_show_traceback = True
#     driver.default_show_exception = True
#     driver.default_show_exception_message = True
    driver.driver()
