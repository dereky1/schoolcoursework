#Submitter: dereky1(Yang, Derek)

class Time:
    def __init__(self, *args):
        self.hour = args[0] if len(args) > 0 else 0
        assert self.hour >= 0 and self.hour < 24 and type(self.hour) is int, 'Time.__init__: x('+str(self.hour)+') should be an int between 0 and 23'
        self.minute = args[1] if len(args) > 1 else 0
        assert self.minute >= 0 and self.minute < 60 and type(self.minute) is int, 'Time.__init__: x('+str(self.minute)+') should be an int between 0 and 59'
        self.second = args[2] if len(args) > 2 else 0
        assert self.second >= 0 and self.second < 60 and type(self.second) is int, 'Time.__init__: x('+str(self.second)+') should be an int between 0 and 59'
    
    
    def __getitem__(self, *args):
        return_value = ()

        if type(args[0]) is int:
            if args[0] == 1: ret_val = self.hour
            elif args[0] == 2: ret_val = self.minute
            elif args[0] == 3: ret_val = self.second
            else:raise IndexError("Time.__getitem__: x(" + str(args) + ") is suppose to be either 1, 2 or 3")
            return ret_val
        
        for arg in args[0]:
            if arg == 1: return_value += (self.hour,)
            elif arg == 2: return_value += (self.minute,)
            elif arg == 3: return_value += (self.second,)
            else:raise IndexError("Time.__getitem__: x(" + str(args[0]) + ") is suppose to be either 1, 2 or 3")
        
        return return_value


    def __repr__(self):
        return 'Time(' + str(self.hour) + ',' + str(self.minute) + ',' + str(self.second) + ')'
    

    def __str__(self):
        hour = str(self.hour - 12) if self.hour > 12 else str(self.hour)
        minute = '0'+str(self.minute) if self.minute < 10 else str(self.minute)
        second = '0'+str(self.second) if self.second < 10 else str(self.second)
        suffix = 'am' if self.hour < 12 else 'pm'
        if self.hour == 0: hour = '12'
        
        return hour + ':' + minute + ':' + second + suffix
        
    
    def __bool__(self):
        if self.hour == 0 and self.minute == 0 and self.second == 0:
            return False
        return True
    
    
    def __len__(self):
        return (3600*self.hour) + (60*self.minute) + self.second
        
 
    def __eq__(self,right):
        if type(self) == type(right) and self.hour == right.hour and self.minute == right.minute and self.second == right.second: return True
        return False
        
        
    def __lt__(self,right): 
        if type(self) == type(right):
            if len(self) < len(right): return True
        elif type(right) == int:
            if len(self) < right: return True
        else:
            raise TypeError("Time.__lt__: t < (" + str(right) + ") is suppose to be either a Time object or int")
        return False
    
    
    def __add__(self, right):
        if type(right) != int:
            raise TypeError("Time.__add__: t + (" + str(right) + ") is suppose to be an int")
        
        t = Time()
        t.hour = self.hour
        t.minute = self.minute
        t.second = self.second
        
        for x in range(right):
            t.second += 1
            if t.second > 59:
                t.second = 0
                t.minute += 1
                if t.minute > 59:
                    t.minute = 0
                    t.hour += 1
                    if t.hour > 23:
                        t.hour = 0

        return str(t)
        
        
    def __radd__(self, left):
        return self.__add__(left)


    def __call__(self, hour, minute, second):
        assert hour >= 0 and hour < 24 and type(hour) is int, 'Time.__call__: x('+str(hour)+') should be an int between 0 and 23'
        assert minute >= 0 and minute < 60 and type(minute) is int, 'Time.__call__: x('+str(minute)+') should be an int between 0 and 59'
        assert second >= 0 and second < 60 and type(second) is int, 'Time.__call__: x('+str(second)+') should be an int between 0 and 59'
        self.hour = hour 
        self.minute = minute
        self.second = second
       
        return None
    
    
if __name__ == '__main__':
    # Put in simple tests for Time before allowing driver to run

    #print(str(t))
    import driver
    driver.default_file_name = 'bsc1.txt'
#     driver.default_show_traceback = True
#     driver.default_show_exception = True
#     driver.default_show_exception_message = True
    driver.driver()
    



        
        
        
        
        
