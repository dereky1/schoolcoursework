#Submitter: dereky1(Yang,Derek)
import re, traceback, keyword

def pnamedtuple(type_name, field_names, mutable=False):
    def show_listing(s):
        for i, l in enumerate(s.split('\n'), 1):
            print('{num: >3} {txt}'.format(num=i, txt=l.rstrip()))

    # put your code here
    # bind class_definition (used below) to the string constructed for the class
    
    pattern = re.compile('(?<!\W_)([a-zA-Z]+[\d_]*)')
    if type(type_name) != str:
        raise SyntaxError('pnamedtuple({}): type_name argument is not legal'.format(type_name))
    name_match = pattern.match(type_name)
    if name_match == None:
        raise SyntaxError('pnamedtuple({}): type_name argument is not legal'.format(type_name))
    if type(field_names) == str:
        if ',' in field_names:
            spl = field_names.strip().split(',')
        else:
            spl = field_names.strip().split(' ')
        field_list = [i.strip() for i in spl if i not in (None,'')]
        for i in field_list:
            if i[0].lower() not in 'abcdefghijklmnopqrstuvwxyz' or str(i) in keyword.kwlist:
                raise SyntaxError('pnamedtuple({}): field_names argument is not legal'.format(field_names))
    elif type(field_names) == list:
        for i in field_names:
            if i[0].lower() not in 'abcdefghijklmnopqrstuvwxyz' or str(i) in keyword.kwlist:
                raise SyntaxError('pnamedtuple({}): field_names argument is not legal'.format(field_names))
            field_list = [i.strip() for i in field_names]
    else:
        raise SyntaxError('pnamedtuple({}): field_names argument is not legal'.format(field_names))
    
    
    def init(field_names, mutable):
        return_str = '    def __init__(self, {_names}):\n        self._mutable = True\n'.format(_names = ', '.join([i for i in field_names]))
        for names in field_names:
            return_str += '        self.{name} = {names}\n'.format(name = str(names),names = str(names))
        return_str += '        self._fields = {field}\n        self._mutable = {mutable}\n'.format(field = [str(i) for i in field_names], mutable = mutable)    
        
        return return_str
     
     
    def repr(type_name, field_names):
        self = ''
        name = ''
        for names in field_names:
            if self == '': self += '{names}=self.{names}'.format(names = names)
            else: self += ',{names}=self.{names}'.format(names = names)
            if name == '': name += str(names)+ '={' + str(names) + '}'
            else: name += ',' + str(names)+ '={' + str(names) + '}'
        set_str = '{name})".format({self}'.format(name = name, self = self)
    
        return '    def __repr__(self):\n        return "{type_name}({set_str})\n'.format(type_name = type_name, set_str = set_str)
    
    
    def get_(field_names):
        return_str = ''
        for names in field_names:
            return_str += '    def get_{names}(self):\n        return self.{names}\n'.format(names = names)

        return return_str
    
    
    def getitem():
        return '    def __getitem__(self, item):\n        if type(item) == int: return self.__dict__[self._fields[item]]\n        elif type(item) == str and item in self.__dict__.keys(): return self.__dict__[self._fields[self._fields.index(item)]]\n        else: raise IndexError(\'type_name.__getitem__(): index not legal\')\n' 
    
    
    def equals():
        return '    def __eq__(self, right):\n        if type(self) == type(right):\n            for keys in self.__dict__.keys():\n                if keys[0] == \'_\': continue\n                if keys not in right.__dict__.keys(): return False\n                if self[keys] != right[keys]: return False\n        else: return False\n        return True\n'
    
    
    def _replace():
        return '    def _replace(self, **kargs):\n        var_list = []\n        for args in kargs.items():\n            left, right = args[0], args[1]\n            var_list.append((left,right))\n            if left not in self.__dict__.keys(): raise TypeError (\'type_name._replace(): illegal arguments provided\')\n        if self._mutable:\n            for items in var_list:\n                exec(\'self.{left} = {right}\'.format(left=items[0],right=items[1]))\n        else:\n            new_object = copy.copy(self)\n            for items in var_list:\n                exec(\'new_object.{left} = {right}\'.format(left=items[0],right=items[1]))\n            return new_object\n'
    
    
    return_class = 'import copy\nclass {type_name}:\n{init}\n{repr}\n{get_}\n{getitem}\n{equal}\n{replace}\n'
    class_definition = return_class.format(type_name = type_name, init = init(field_list,mutable),repr = repr(type_name, field_list), get_= get_(field_list), getitem = getitem(), equal = equals(), replace = _replace())
    
    # For initial debugging, always show the source code of the class
    #show_listing(class_definition)

    # Execute the class_definition string in a local namespace and bind the
    #   name source_code in its dictionary to the class_defintion; return the
    #   class object created; if there is a syntax error, list the class and
    #   also show the error
    
    name_space = dict(__name__='pnamedtuple_{type_name}'.format(type_name=type_name))
    try:
        exec(class_definition, name_space)
        name_space[type_name].source_code = class_definition
    except(SyntaxError, TypeError):
        show_listing(class_definition)
        traceback.print_exc()
    return name_space[type_name]
    

    
if __name__ == '__main__':
    Triple1 = pnamedtuple('Triple1', 'a b c')
    t1 = Triple1(1,2,3)
    
    import driver
    driver.driver()
