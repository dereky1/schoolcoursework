#Submitter: dereky1(Yang, Derek)
from functools import reduce # for use in peaks

def separate(p,l):
    if len(l) == 0: return [],[]
    truth_list,false_list = separate(p, l[1:])
    if p(l[0]):truth_list.append(l[0])
    else:false_list.append(l[0])
        
    return truth_list,false_list


def is_sorted(s):
    try:
        if s[1] < s[0]: return False
    except: return True
    
    return is_sorted(s[1:])


def sort(l):
    if len(l) == 0: return []
    else:
        x,y = separate(lambda x: x < l[0], l[1:])
        return sort(x) + [l[0]] + sort(y)
 
    
def compare(a,b):
    if len(a) != 0 and len(b) != 0:
        if a[0] == b[0]: return compare(a[1:], b[1:])
        elif a[0] < b[0]: return '<'
        elif a[0] > b[0]: return '>'
    if len(a) != 0: return '>'
    elif len(b) != 0: return '<'
    else: return '='
 
 
def triple(x,y): 

    if x == None: 
        x = [[y]]
        return x
    elif len(x[0]) < 3:
        x[0].append(y)
        return x
    elif len(x[0]) == 3:
        x.append([x[len(x)-1][-2],x[len(x)-1][-1],y])
        return x


def peaks(alist):
    reduced = reduce(triple, alist, [[]])
    filtered = filter(lambda x: (x[1] > x[0] and x[1] > x[-1]) , reduced)
    mapped = map(lambda x: x[1], filtered)
    return list(mapped)
    

if __name__=="__main__":
    import predicate,random,driver
    from goody import irange
    
    print('Testing separate')
    print(separate(predicate.is_positive,[]))
    print(separate(predicate.is_positive,[1, -3, -2, 4, 0, -1, 8]))
    print(separate(predicate.is_prime,[i for i in irange(2,20)]))
    print(separate(lambda x : len(x) <= 3,'to be or not to be that is the question'.split(' ')))
     
    print('\nTesting is_sorted')
    print(is_sorted([]))
    print(is_sorted([1,2,3,4,5,6,7]))
    print(is_sorted([1,2,3,7,4,5,6]))
    print(is_sorted([1,2,3,4,5,6,5]))
    print(is_sorted([7,6,5,4,3,2,1]))
    
    print('\nTesting sort')
    print(sort([1,2,3,4,5,6,7]))
    print(sort([7,6,5,4,3,2,1]))
    print(sort([4,5,3,1,2,7,6]))
    print(sort([1,7,2,6,3,5,4]))
    l = [i+1 for i in range(30)]
    random.shuffle(l)
    print(l)
    print(sort(l))
    
    print('\nTesting compare')
    print(compare('','abc'))
    print(compare('abc',''))
    print(compare('',''))
    print(compare('abc','abc'))
    print(compare('bc','abc'))
    print(compare('abc','bc'))
    print(compare('aaaxc','aaabc'))
    print(compare('aaabc','aaaxc'))
    
    print('\nTesting triple and peaks')
    print(triple([[]],'a'))
    print(triple([['a']],'b'))
    print(triple([['a','b']],'c'))
    print(triple([['a','b','c']],'d'))
    print(triple([['a','b','c'],['b','c','d']],'e'))
    print(triple([['a','b','c'],['b','c','d'],['c','d','e']],'f'))
    
    print(peaks([0,1,-1,3,8,4,3,5,4,3,8]))
    print(peaks([5,2,4,9,6,1,3,8,0,7]))
    print(peaks([1,2,3,4,5]))
    print(peaks(int(predicate.is_prime(p)) for p in irange(1,20)))
    
    driver.default_file_name = 'bsc.txt'
#     driver.default_show_traceback         = True
#     driver.default_show_exception         = True
#     driver.default_show_exception_message = True
    driver.driver()
    
