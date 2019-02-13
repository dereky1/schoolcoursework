# Submitter: dereky1(Yang, Derek)

def read_ndfa(file : open) -> {str:{str:{str}}}:
    outer_dict = {}
    
    for lines in file:
        key = lines.strip().split(';')[0]
        line = lines.strip().split(';')[1:]
        inner_dict = {}
        for count in range(len(line)//2):
            temp_set = set()
            if line[2*count] in inner_dict.keys():
                temp_key = inner_dict[line[2*count]]
                temp_set = set(temp_key)
                temp_set.add(line[(2*count)+1])
                inner_dict[line[2*count]] = temp_set
            else:
                temp_set.add(line[(2*count)+1])
                inner_dict[line[2*count]] = temp_set
        outer_dict[key] = inner_dict

    return outer_dict

def ndfa_as_str(ndfa : {str:{str:{str}}}) -> str:
    return_str = ''
   
    for keys in sorted(ndfa.keys()):
        temp_list = []
        for sec_keys in sorted(ndfa[keys]):
            temp_list.append((sec_keys, sorted(list(ndfa[keys][sec_keys]))))
        return_str += "  {} transitions: {}\n".format(keys, temp_list)
                
    return return_str        

def process(ndfa : {str:{str:{str}}}, state : str, inputs : [str]) -> [None]:
    
    return_list = []
    return_list.append(state)
    
    next_state = [state]
    for states in inputs:
        if len(next_state) == 0:
            return return_list
        temp_set = set()
        for item in next_state:
            if states in ndfa[item].keys():
                for items in ndfa[item][states]:
                    temp_set.add(items)
        return_list.append((states,temp_set))
        next_state = []
        for items in temp_set:
            next_state.append(items)   
    return return_list

def interpret(result : [None]) -> str:
   
    results = iter(result)
    next(results)
    return_str = "Start state = {}\n".format(result[0])
    for inputs in results:
        inpu, state = inputs
        return_str += "  Input = {}; new possible states = {}\n".format(inpu,sorted(list(state)))
    return_str += 'Stop state(s) = {}\n'.format(sorted(list(state)))
            
    return return_str

if __name__ == '__main__':
    # Write script here

    a = read_ndfa(open(input("Enter the name of a file with a non-seterministic finite automaton: ")))
    print(ndfa_as_str(a))
    b = open(input('Enter the name of a file with the start-state and input: '))
    print('')
    for lines in b:
        print('Starting new simulation')
        state = lines.strip().split(';')[0]
        inputs = lines.strip().split(';')[1:]
        print(interpret(process(a,state, inputs)))   
        #simulation = interpret(process(a, state, inputs))
        #print(simulation)  
    # For running batch self-tests
    print()
    import driver
    driver.default_file_name = "bsc4.txt"
#     driver.default_show_traceback = True
#     driver.default_show_exception = True
#     driver.default_show_exception_message = True
    driver.driver()
