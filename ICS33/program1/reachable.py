# Submitter: dereky1(Yang, Derek)

def read_graph(file : open) -> {str:{str}}:
    return_dict = {}
    for line in file:
        source, reach = line.strip().split(';')
        if source in return_dict.keys():
            return_dict[source].add(reach)
        else:
            return_dict[source] = {reach}  
            
    return return_dict

def graph_as_str(graph : {str:{str}}) -> str:
    
    return_str = ''
    for key in sorted(graph.keys()): 
        return_str += '  ' + str(key) + ' -> ' + str(sorted(graph[key])) + '\n'
        
    return return_str
        
def reachable(graph : {str:{str}}, start : str) -> {str}:
    return_set = set()
    search_list = [start]
    
    while len(search_list) > 0:
        for search in search_list:
            if search not in return_set:
                return_set.add(search)
            elif search in return_set:
                search_list.remove(search) 
                continue
            if search in graph.keys():
                for items in graph[search]:
                    search_list.append(items)
            search_list.remove(search)                   
            
    return return_set

if __name__ == '__main__':
    # Write script here
    file_input = input("Enter the name of file with a graph: ")
    graph = read_graph(open(file_input))
    print(('Graph: source -> {destination} edges\n')+graph_as_str(graph))

    while True:
        node_input = input('\nEnter the name of a starting node: ')
        if node_input == 'quit':
            break
        if node_input in graph.keys():
            print('From',node_input,'the reachable nodes are',reachable(graph, node_input))
        else:
            print('  Entry Error: \'' + str(node_input) + '\'; Illegal: not a source node\n  Please enter a legal String')
            
    # For running batch self-tests
    print()
    import driver
    driver.default_file_name = "bsc1.txt"
#     driver.default_show_traceback = True
#     driver.default_show_exception = True
#     driver.default_show_exception_message = True
    driver.driver()
