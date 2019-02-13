#Submitter: dereky1(Yang, Derek)
from goody import type_as_str
import inspect

class Check_All_OK:
    """
    Check_All_OK class implements __check_annotation__ by checking whether each
      annotation passed to its constructor is OK; the first one that
      fails (by raising AssertionError) prints its problem, with a list of all
      annotations being tried at the end of the check_history.
    """
       
    def __init__(self,*args):
        self._annotations = args
        
    def __repr__(self):
        return 'Check_All_OK('+','.join([str(i) for i in self._annotations])+')'

    def __check_annotation__(self, check, param, value,check_history):
        for annot in self._annotations:
            check(param, annot, value, check_history+'Check_All_OK check: '+str(annot)+' while trying: '+str(self)+'\n')


class Check_Any_OK:
    """
    Check_Any_OK implements __check_annotation__ by checking whether at least
      one of the annotations passed to its constructor is OK; if all fail 
      (by raising AssertionError) this classes raises AssertionError and prints
      its failure, along with a list of all annotations tried followed by the
      check_history.
    """
    
    def __init__(self,*args):
        self._annotations = args
        
    def __repr__(self):
        return 'Check_Any_OK('+','.join([str(i) for i in self._annotations])+')'

    def __check_annotation__(self, check, param, value, check_history):
        failed = 0
        for annot in self._annotations: 
            try:
                check(param, annot, value, check_history)
            except AssertionError:
                failed += 1
        if failed == len(self._annotations):
            assert False, repr(param)+' failed annotation check(Check_Any_OK): value = '+repr(value)+\
                         '\n  tried '+str(self)+'\n'+check_history                 



class Check_Annotation():
    # set name to True for checking to occur
    checking_on  = True
  
    # self._checking_on must also be true for checking to occur
    def __init__(self,f):
        self._f = f
        self.checking_on = True
        
    # Check whether param's annot is correct for value, adding to check_history
    #    if recurs; defines many local function which use it parameters.  
    def check(self,param,annot,value,check_history=''):
        # Define local functions for checking, list/tuple, dict, set/frozenset,
        #   lambda/functions, and str (str for extra credit)
        # Many of these local functions called by check, call check on their
        #   elements (thus are indirectly recursive)

        def check_type(annot):
            assert isinstance(value, annot), '\'{param}\' failed annotation check(wrong type): value = \'{value}\'\n  was type {type_param} ...should be type {correct_type}'.format(param = param, value = value, type_param = type_as_str(value), correct_type = str(annot)[8:-2])
            if self._f(value) != None:
                assert type_as_str(self._f(value)) == str(inspect.signature(self._f)).split('->')[-1].strip(), 'hi'
            
            
        def check_list(list_tuple):
            check_type(list_tuple)
            type_name = str(list_tuple)[8:-2]
            count = 0
            if len(annot) == 1:
                for i in range(len(annot)):
                    for j in range(len(value)):
                        check_history + "{types}[{count}] check: {value}".format(types = type_name, count = count, value = value[j])
                        count +=1
                        self.check(param,annot[i],value[j],check_history)
            else:
                assert len(annot) == len(value), '\'{param}\' failed annotation check(wrong number of elements): value = [{value_len}]\n  annotation had {param_len} elements[{annot}]'.format(param = param, value_len = len(value), param_len = len(param), annot = annot)
                for anno, valu in zip(annot, value):
                    check_history + "{types}[{count}] check: {value}".format(types = type_name, count = count, value = valu)
                    count += 1
                    self.check(param, anno, valu, check_history)
        
        def check_dict(dic):
            check_type(dic)
            assert isinstance(value, dic),'\'{param}\' failed annotation check(wrong type): value = {value}\n  was type {value_type} ...should be type {correct_type}\n'.format(param = param, value = value, value_type = type(annot), correct_type = annot)
            assert len(annot) == 1, "AssertionError: '{param}' annotation inconsistency: dict should have 1 item but had {value}\n  annotation = {annot}\n".format(param = param, value = len(annot), annot = annot)
            for keys in annot.keys():
                for key in value.keys():
                    ch = check_history + "dict key check: {}".format(keys)
                    self.check(param, keys, key, ch)
            for values in annot.values():
                for valu in value.values():
                    ch = check_history + "dict value check: {}".format(values)
                    self.check(param, values, valu, ch)
                    
        def check_set(sett):
            check_type(sett)
            assert(isinstance(value, sett)), '\'{param}\' failed annotation check(wrong type): value = {value}\n  was type {value_type} ...should be type {correct}'.format(param = param, value = value, value_len = len(annot), annot = annot)
            assert len(annot) == 1,'\'{param}\' annotation inconsistency: set should have 1 value but had {value_len}\n  annotation = {annot}'.format(param = param, value_len = len(annot), annot = annot)
            for i in annot:
                for j in value:
                    ch = check_history + "set value check: {}".format(str(sett)[8:-2])
                    self.check(param, i, j, ch)
                    
        def check_lambda():
            assert len(annot.__code__.co_varnames) == 1, '\'{param}\' annotation inconsistency: predicate should have 1 parameter but had {leng} predicate = {annot}'.format(param = param, leng = len(annot.__code__.co_varnames), annot = annot)
            try:
                annot(value)
            except Exception as e:
                raise AssertionError('\'{param}\' annotation predicate({Lambda}) raised exception\n  exception = TypeError: {error}'.format(param = param, Lambda = annot, error = e))
            assert annot(value),'\'{param}\' failed annotation check: value = {value}\n  predicate = {Lambda}'.format(param = param, value = value, Lambda = annot)

        def check_else(none):
            if self._f(value) != None:
                    assert type_as_str(self._f(value)) == str(inspect.signature(self._f)).split('->')[-1].strip(), '\'{param}\' annotation predicate does not match return annotation\n  value is {value_type}, should be {return_type}'.format(param = param, value_type = type_as_str(value), return_type = str(inspect.signature(self._f)).split('->')[-1].strip())
                    
            if none == None:
                return
            
            try:
                annot.__check_annotation__()
            except:
                raise AssertionError('Class does not have a __check_annotation__() method')
            
            
        # Decode the annotation here and check it 
        if type_as_str(annot) == 'type': check_type(annot)
        elif type_as_str(annot) == 'list': check_list(list)
        elif type_as_str(annot) == 'tuple': check_list(tuple)
        elif type_as_str(annot) == 'dict': check_dict(dict)
        elif type_as_str(annot) == 'set': check_set(set)
        elif type_as_str(annot) == 'frozenset': check_set(frozenset)
        elif type_as_str(annot) == 'function': check_lambda()
        else: check_else(annot)
        
    # Return result of calling decorated function call, checking present
    #   parameter/return annotations if required
    def __call__(self, *args, **kargs):
        if self.checking_on:

            # Return a dictionary of the parameter/argument bindings (actually an
            #    ordereddict, in the order parameters occur in the function's header)
            def param_arg_bindings():
                f_signature  = inspect.signature(self._f)
                bound_f_signature = f_signature.bind(*args,**kargs)
                for param in f_signature.parameters.values():
                    if param.name not in bound_f_signature.arguments:
                        bound_f_signature.arguments[param.name] = param.default
                return bound_f_signature.arguments
    
            # If annotation checking is turned off at the class or function level
            #   just return the result of calling the decorated function
            # Otherwise do all the annotation checking
            #print(dict(param_arg_bindings()))
            try:
                # Check the annotation for every parameter (if there is one)
                        
                # Compute/remember the value of the decorated function
                
                # If 'return' is in the annotation, check it
                
                # Return the decorated answer
                for param, value in param_arg_bindings().items():
                    self.check(param, self._f.__annotations__[param], value)
                #remove after adding real code in try/except
                
            # On first AssertionError, print the source lines of the function and reraise 
            except AssertionError:
                #print(80*'-')
                #for l in inspect.getsourcelines(self._f)[0]: # ignore starting line #
                #    print(l.rstrip())
                #print(80*'-')
                raise 
    
        else: self._f(*args, **kargs)


  
if __name__ == '__main__':     
    #an example of testing a simple annotation  
    '''
    def f(x:None)->int: return x
    f = Check_Annotation(f)
    f('abc')
    '''
    
           
    import driver
    driver.driver()
