# Submitter: dereky1(Yang, Derek)

def read_fa(file : open) -> {str:{str:str}}:
    outer_dict = {}
    
    for lines in file:
        key = lines.strip().split(';')[0]
        line = lines.strip().split(';')[1:]
        inner_dict = {}
        for count in range(len(line)//2):
            inner_dict[line[2*count]] = line[(2*count)+1]
        outer_dict[key] = inner_dict

    return outer_dict

def fa_as_str(fa : {str:{str:str}}) -> str:
    return_str = ''
    
    for key in sorted(fa.keys()):
        first = 0
        return_str += ('  {} transitions: [').format(str(key)) 
        for values in sorted(fa[key]):
            if first == 0:
                return_str += ('(\'{}\', \'{}\')'.format(str(values),str(fa[key][values])))
                first = 1
            else:
                return_str += (', (\'{}\', \'{}\')'.format(str(values),str(fa[key][values])))
        return_str += ']\n'

    return return_str

def process(fa : {str:{str:str}}, state : str, inputs : [str]) -> [None]:
    return_list = []
    
    return_list.append(state)
    for states in inputs:
        next_state = ((states,fa[state][states]) if states in fa[state].keys() else (states,None))
        return_list.append(next_state)
        state = next_state[1]

    return return_list

def interpret(fa_result : [None]) -> str:
    results = iter(fa_result)
    next(results)
    return_str = "Start state = {}\n".format(fa_result[0])
    for inputs in results:
        inpu, state = inputs
        if state == None:
            return_str += "  Input = {}; illegal input: simulation terminated\n".format(inpu)
        else:
            return_str += "  Input = {}; new state = {}\n".format(inpu,state)
    return_str += 'Stop state = {}\n'.format(state)
            
    return return_str 

if __name__ == '__main__':
    # Write script here
    
    a = read_fa(open(input('Enter the name of a file with a finite automaton: ')))
    print("\nFinite Automaton")
    print(fa_as_str(a))
    b = open(input('Enter the name of a file with the start-state and input: '))
    for lines in b:
        print('Starting new simulation')
        state = lines.strip().split(';')[0]
        inputs = lines.strip().split(';')[1:]
        simulation = interpret(process(a, state, inputs))
        print(simulation)  
    
    # For running batch self-tests
    print()
    import driver
    driver.default_file_name = "bsc3.txt"
#     driver.default_show_traceback = True
#     driver.default_show_exception = True
#     driver.default_show_exception_message = True
    driver.driver()
