#Submitter: dereky1(Yang, Derek)
from collections import defaultdict
from goody import type_as_str

class Bag:
    def __init__(self, *items):
        self.bag_space = defaultdict(int)
        for loop in range(len(items)):
            for item in items[loop]:
                self.bag_space[item] += 1
            
    
    def __repr__(self):
        item_list = []
        for keys in self.bag_space.keys():
            for items in range(self.bag_space[keys]):
                item_list.append(keys)       
  
        return 'Bag(' + str(item_list) + ')'
    
    
    def __str__(self):
        return_str = 'Bag('
        for keys in self.bag_space.keys():
            if return_str == 'Bag(' : return_str += '{}[{}]'.format(keys,self.bag_space[keys])
            else: return_str += ',{}[{}]'.format(keys,self.bag_space[keys])

        return return_str + ')'


    def __len__(self):
        return_len = 0
        for keys in self.bag_space.keys():
            return_len += self.bag_space[keys]
            
        return return_len
        
    
    def unique(self):
        return len(self.bag_space.keys())
        
        
    def __contains__(self, item):
        return (True if item in self.bag_space.keys() else False)
        
        
    def count(self, item):
        return (self.bag_space[item] if item in self.bag_space.keys() else 0)
        
        
    def add(self, item):
        self.bag_space[item] += 1   
        
        return None
        
    
    def __add__(self, right):
        if type_as_str(self) != type_as_str(right): raise TypeError('Bag.__add__(' + str(right) + ') should be another bag object')
        return_bag = Bag()
        for keys in self.bag_space.keys(): return_bag.bag_space[keys] += self.bag_space[keys]
        for key in right.bag_space.keys(): return_bag.bag_space[key] += right.bag_space[key]
        
        return return_bag
        
        
    def remove(self, item):
        if item not in self.bag_space.keys(): raise ValueError('Bag.remove(' + str(item) + ') does not exist in Bag to remove')
        self.bag_space[item] = self.bag_space[item] - 1
        if self.bag_space[item] == 0: del self.bag_space[item]
        
        return None
        
        
    def __eq__(self, right):
        if type_as_str(right) != type_as_str(self): return False
        elif self.bag_space.items() == right.bag_space.items(): return True
        else: return False
        
        
    def __iter__(self):
        copy_list = []
        for keys in self.bag_space.keys():
            for times in range(self.bag_space[keys]):
                copy_list.append(keys)
  
        def gen(items):
            for i in range(len(items)):
                yield items[i]

        return gen(copy_list)

            
if __name__ == '__main__':
    # You can put your own code to test Bags here

    #print(eval(repr(b4)))
    
    #print(t)
    print()
    import driver
    driver.default_file_name = 'bsc1.txt'
#     driver.default_show_exception=True
#     driver.default_show_exception_message=True
#     driver.default_show_traceback=True
    driver.driver()
