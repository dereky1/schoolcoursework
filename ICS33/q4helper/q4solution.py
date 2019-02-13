#Submitter: dereky1(Yang, Derek)
# Generators must be able to iterate through any iterable.
# hide is present and called to ensure that your generator code works on
#   general iterable parameters (not just a string, list, etc.)
# For example, although we can call len(string) we cannot call
#   len(hide(string)), so the generator functions you write should not
#   call len on their parameters
# Leave hide in this file and add code for the other generators.

def hide(iterable):
    for v in iterable:
        yield v


def start_when(iterable,p):
    p_true = False
    for v in iterable:
        if p(v): p_true = True
        if p_true:
            yield v
            
                    
def differences(iterable1,iterable2):
    
    hi = enumerate(zip((x for x in iterable1), (y for y in iterable2)),start = 1)
    for items in hi:
        if items[1][0] != items[1][1]:
            yield (items[0],items[1][0],items[1][1])

                       
def once_in_a_row(iterable):
    prev_value = None
    for v in iterable:
        if v == prev_value:
            continue
        prev_value = v
        yield v
            

def alternate(*args):
    out = True
    iter_list = [iter(x) for x in args]
    while out:
        for index in range(len(iter_list)):
            value = next((iter_list[index]))
            if value == None: out = False
            yield value
            
                
def windows(iterable,n,m=1):
    iter_list =[]
    for v in iterable: 
        if len(iter_list) == n:
            yield iter_list
            for pop in range(m):
                iter_list.pop(0)   
        iter_list.append(v)
           
         
def ascending(n,iterable):
    assert n >= 2, 'ascending({}, iterable): first parameter should be at least 2'.format(n)
    return_list = []
    iterables = iter(iterable)
    prev, start, up, item = 0,None,0,None
    try:
        while True:
            curr = next(iterables)
            if start == None: start = curr
            elif curr > prev:
                up += 1
                if up >= n-1: item = (start, curr)
            elif curr <= prev:
                if item: return_list.append(item)
                item, up, start = None, 0, curr
            prev = curr
    except StopIteration:
        if item: return_list.append(item)
    
    return return_list


if __name__ == '__main__':
    
    # Test start_when; you can add your own test cases
    print('Testing start_when')
    for i in start_when('combustible', lambda x : x >= 'q'):
        print(i,end='')
    print('\n')

    print('Testing start_when on hidden')
    for i in start_when(hide('combustible'), lambda x : x >= 'q'):
        print(i,end='')
    print('\n\n')
    
    
    # Test differences; you can add your own test cases
    print('Testing differences')
    for i in differences('3.14159265', '3x14129285'):
        print(i,end=' ')    
    print('\n')

    print('Testing differences on hidden')
    for i in differences(hide('3.14159265'), hide('3x14129285')):
        print(i,end=' ')    
    print('\n\n')

              
    # Test once_in_a_row; you can add your own test cases
    print('Testing once_in_a_row')
    for i in once_in_a_row('abcccaaabddeee'):
        print(i,end='')    
    print('\n')

    print('Testing once_in_a_row on hidden')
    for i in once_in_a_row(hide('abcccaaabddeee')):
        print(i,end='')    
    print('\n\n')

              
    # Test alternate; you can add your own test cases
    print('Testing alternate')
    for i in alternate('abcde','fg','hijk'):
        print(i,end='')
    print('\n')
    
    print('Testing alternate on hidden')
    for i in alternate(hide('abcde'), hide('fg'),hide('hijk')):
        print(i,end='')
    print('\n\n')
       
         
    # Test windows; you can add your own test cases
    print('Testing windows')
    for i in windows('abcdefghijk',4,2):
        print(i,end=' ')
    print('\n')
    
    print('Testing windows on hidden')
    for i in windows(hide('abcdefghijk'),4,2):
        print(i,end=' ')
    print('\n\n')
       
    
    # Test ascending; add your own test cases
    print('Testing ascending')
    print('  on [5,5,2,4,6,2,4]')
    print('n=2:',ascending(2,[5,5,2,4,6,2,4]))
    print('n=3:',ascending(3,[5,5,2,4,6,2,4]))
    print('n=4:',ascending(4,[5,5,2,4,6,2,4]))
    print()

    print('  on [2,3,1,4,6,7,2,0,2,4,3]')
    print('n=2:',ascending(2,[2,3,1,4,6,7,2,0,2,4,3]))
    print('n=3:',ascending(3,[2,3,1,4,6,7,2,0,2,4,3]))
    print('n=4:',ascending(4,[2,3,1,4,6,7,2,0,2,4,3]))
    print('n=5:',ascending(5,[2,3,1,4,6,7,2,0,2,4,3]))
    print()

    print('  on [1,2,1,2,3]')
    print('n=2:',ascending(2,[1,2,1,2,3]) )
    print('n=3:',ascending(3,[1,2,1,2,3]) )
    print('n=4:',ascending(4,[1,2,1,2,3]) )
    print()

    print('  hidden testing')
    print(ascending(2,hide([5,5,2,4,6,2,4])))
    print(ascending(3,hide([2,3,1,4,6,7,2,0,2,4,3])))
    print(ascending(2,hide([1,2,1,2,3])))
    print('\n')
         
         
    import driver
#     driver.default_show_exception=True
#     driver.default_show_exception_message=True
#     driver.default_show_traceback=True
    driver.driver()
    
