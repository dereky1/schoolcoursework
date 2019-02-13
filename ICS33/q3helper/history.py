#Submitter: dereky1(Yang,Derek)
from collections import defaultdict

class History:
    def __init__(self):
        self.__dict__ = defaultdict(list)
    
    
    def __getattr__(self,name):
        attr = name.split('_prev',1)[0]
        if attr not in self.__dict__.keys(): raise NameError("History.__getattr__(" + str(attr) + ") is not a valid key")
        num = name.count('_prev')

        try:
            value = self.__dict__[attr][num]
        except IndexError:
            value = None
        
        return value


    def __getitem__(self,index):
        return_dict = {}
        if index > 0: raise IndexError("History.__getitem__(" + str(index) + ") should be 0 or a negative int")
        ind = index if index < 0 else 1
        for num in range(abs(ind)):
            for key in self.__dict__.keys():
                if key != '__dict__':
                    try:
                        if index == 0: return_dict[key] = self.__dict__[key][0]
                        else: return_dict[key] = self.__dict__[key][num+1]
                    except IndexError:
                        return_dict[key] = None
              
        return return_dict
    
    def __setattr__(self,name,value):
        if '_prev' in name: raise NameError('History.__setattr__(' + str(name) + ') cannot be \'_prev\'')
        if name in self.__dict__.keys(): self.__dict__[name].insert(0,value)
        else: self.__dict__[name] = [value]
        
        return None
      
       
if __name__ == '__main__':
    # Put in simple tests for History before allowing driver to run

    print()
    import driver
    
    driver.default_file_name = 'bsc2.txt'
#     driver.default_show_traceback = True
#     driver.default_show_exception = True
#     driver.default_show_exception_message = True
    driver.driver()
