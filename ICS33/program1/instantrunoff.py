# Submitter: dereky1(Yang, Derek)
from goody import irange

file_name = 'votepref1.txt'
def read_voter_preferences(file : open):
    return_dict = {}
    
    for lines in file:
        temp_list = []
        for letter in lines.strip().split(';'):
            if letter == lines.strip().split(';')[0]:
                voter = letter
            else:
                temp_list.append(letter)
        return_dict[voter] = temp_list

    return return_dict

def dict_as_str(d : {None:None}, key : callable=None, reverse : bool=False) -> str:
    return_str = ''
    
    for key in sorted(d, key = key, reverse = reverse): 
        return_str += '  ' + key + ' -> ' + str(d[key]) + '\n'
    
    return return_str 

def evaluate_ballot(vp : {str:[str]}, cie : {str}) -> {str:int}:
    return_dict = {}
    
    for key in vp.keys():
        for vote in vp[key]:
            if vote in cie:
                if vote not in return_dict.keys():
                    return_dict[vote] = 1
                else:
                    return_dict[vote] += 1
                break

    return return_dict


def remaining_candidates(vd : {str:int}) -> {str}:
    return_set = set()
    key, value =  min(vd.items(), key=lambda x: x[1]) 
    del vd[key]
    if value in vd.values():
        return set()
    else:
        for key in vd.keys():
            return_set.add(key)
        return return_set
    

def run_election(vp_file : open) -> {str}:
    
    ballots = read_voter_preferences(vp_file)
    for key in ballots.keys():
        cie = set(ballots[key])
        break
    print(dict_as_str(ballots))
    
    for count in irange(len(cie)-1):
        print('Vote count on ballot #{} with candidates (alphabetical order): remaining candidates = {}'.format(count,cie))
        election = evaluate_ballot(ballots, cie)
        print(dict_as_str(election))
        print('Vote count on ballot #{} with candidates (numerical order): remaining candidates = {}'.format(count,cie))
        print(dict_as_str(election, key = lambda key: election[key], reverse = True))
        cie = remaining_candidates(election)
    
    return cie
    
if __name__ == '__main__':
    # Write script here
    input_file = input('Enter the name of a file with voter preferences: ')
    result = run_election(open(input_file))
    print('Winner is {}'.format(result))

    # For running batch self-tests
    print()
    import driver
    driver.default_file_name = "bsc2.txt"
#     driver.default_show_traceback = True
#     driver.default_show_exception = True
#     driver.default_show_exception_message = True
    driver.driver()
