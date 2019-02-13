#Submitter: dereky1(Yang, Derek)
from goody import type_as_str

class Sparse_Matrix:
    def __init__(self, rows, cols, *args):
        assert type(rows) == int and type(cols) == int, 'Sparse_Matrix.__init__: rows and cols must be integers'
        assert rows > 0 and cols > 0, 'Sparse_Matrix.__init__: rows and cols must be greater than 0'
        self.matrix = {}
        self.rows = rows
        self.cols = cols
        
        prev_arg = []
        for arg in args:
            for items in arg:
                assert type(items) == int or type(items) == float, 'Sparse_Matrix:__init__: arguments should non-negative integers'
            assert arg not in prev_arg, 'Sparse_Matrix.__init__: repeated index ({})'.format((arg[0],arg[1]))
            assert arg[0] < self.rows and arg[1] < self.cols and arg[0] <= self.rows and arg[1] <= self.cols, 'Sparse.__init__: triple\'s rows or cols is out of range'
            if arg[2] != 0:
                self.matrix[(arg[0],arg[1])] = arg[2]
            prev_arg.append(arg)
            
    
    def size(self):
        return (self.rows, self.cols)
    
    
    def __len__(self):
        return self.rows * self.cols
    
    
    def __bool__(self):
        if self.matrix.keys(): return True
        
        return False
            
            
            
    def __repr__(self):
        return_str = 'Sparse_Matrix({}, {}'.format(self.rows,self.cols)
        for row in range(self.rows):
            for col in range(self.cols):
                if (row,col) in self.matrix.keys():
                    return_str += ', ({}, {}, {})'.format(row,col,str(self.matrix[(row,col)]))
                    
        return return_str + ')'
    
    
    def __getitem__(self, items):
        if len(items) != 2 or type(items) != tuple : raise TypeError('Sparse_Matrix.__getitem__: parameter is not a 2-tuple')
        if type(items[0]) != int or type(items[1]) != int: raise TypeError('Sparse_Matrix.__getitem__: 2-tuple do not contain integers')
        if items[0] < 0 or items[0] >= self.rows or items[1] <0 or items[1] >= self.cols: raise TypeError('Sparse_Matrix.__getitem__: 2-tuple are out of bounds')
        if items in self.matrix.keys():
            return self.matrix[(items[0],items[1])]
        
        return 0
    
    def __setitem__(self, rowcol, value):
        if type(rowcol) != tuple or len(rowcol) != 2 or rowcol[0] >= self.rows or rowcol[1] >= self.cols or rowcol[0] < 0 or rowcol[1] < 0:
            raise TypeError('Sparse_Matrix.__setitem__: argument is not a non negative non zero 2-tuple')
        if type(rowcol[0]) != int or type(rowcol[1]) != int:
            raise TypeError('Sparse_Matrix.__setitem__: argument inside 2-tuple is not int or float')
        if type(value) != int and type(value) != float: raise TypeError('Sparse_Matrix.__setitem__: value argument is not int or float')
        if value == 0:
            if rowcol in self.matrix.keys():
                del(self.matrix[rowcol])
        else:
            self.matrix[rowcol] = value
            
        return None
    
    
    def __delitem__(self, rowcol):
        if type(rowcol) != tuple or len(rowcol) != 2 or rowcol[0] >= self.rows or rowcol[1] >= self.cols or rowcol[0] < 0 or rowcol[1] < 0:
            raise TypeError('Sparse_Matrix.__setitem__: argument is not a non negative non zero 2-tuple')
        if type(rowcol[0]) != int or type(rowcol[1]) != int:
            raise TypeError('Sparse_Matrix.__setitem__: argument inside 2-tuple is not int or float')
        if rowcol in self.matrix.keys(): del(self.matrix[rowcol])
        
        return None
    
    
    def row(self, row):
        assert type(row) == int, 'Sparse_Matrix.row(): parameter given is not a valid integer'
        assert row >= 0 and row < self.rows, 'Sparse_Matrix.row(): parameter given is not a valid row'
        return_tuple = ()
        for col in range(self.cols):
            if (row,col) in self.matrix.keys():
                return_tuple += (self.matrix[(row,col)],)
            else: return_tuple += (0,)
        
        return return_tuple
    
    
    def col(self, col): 
        assert type(col) == int, 'Sparse_Matrix.row(): parameter given is not a valid integer'
        assert col >= 0 and col < self.cols, 'Sparse_Matrix.row(): parameter given is not a valid row'
        return_tuple = ()
        for row in range(self.rows):
            if (row,col) in self.matrix.keys():
                return_tuple += (self.matrix[(row,col)],)
            else: return_tuple += (0,)
        
        return return_tuple
    
            
    def details(self):   
        return_str = '3x3 -> {} -> ('.format(self.matrix)
        for x in range(self.rows):
            if x == 0: return_str += '{}'.format(self.row(x))
            else: return_str += ',{}'.format(self.row(x))
        return return_str + ')'
    
    
    def __call__(self, row, col):
        assert row > 0 and col > 0 and type(row) == int and type(col) == int, 'Sparse_Matrix.__call__: row or col is not a valid parameter'
        for rows in range(self.rows):
            for cols in range(self.cols):
                if rows >= row or cols >= col: 
                    if (rows,cols) in self.matrix.keys():
                        del self.matrix[(rows,cols)]
        self.__dict__['rows'] = row               
        self.__dict__['cols'] = col
        
        return None        
                
        
    def __iter__(self):
        copy_list = []
        for keys in self.matrix.keys():
            copy_list.append(keys+(self.matrix[keys],))
  
        def gen(items):
            for i in range(len(items)):
                yield items[i]

        return gen(sorted(copy_list,key = lambda x: x[2]))
 
    
    def __neg__(self):
        new_object = Sparse_Matrix(self.rows, self.cols)
        for keys in self.matrix.keys():
            var = self.matrix[keys]
            new_object.matrix[keys] = -var if var != 0 else 0
                
        return new_object
                
    
    def __pos__(self):
        new_object = Sparse_Matrix(self.rows, self.cols)
        for keys in self.matrix.keys():
            new_object.matrix[keys] = self.matrix[keys]
            
        return new_object
    
    
    def __abs__(self):
        new_object = Sparse_Matrix(self.rows, self.cols)
        for keys in self.matrix.keys():
            var = self.matrix[keys]
            new_object.matrix[keys] = abs(var) if var != 0 else 0
    
        return new_object
    
    
    def __add__(self, right):
        if type_as_str(right) != type_as_str(self) and type(right) != int and type(right) != float: raise TypeError('SparseMatrix.__add__: argument given is not valid for addition')
        if type_as_str(right) == type_as_str(self):
            assert len(self) == len(right),('SparseMatrix.__add__: length of matrices are not the same, cannot add')
        new_object = Sparse_Matrix(self.rows, self.cols)
        for rows in range(self.rows):
            for cols in range(self.cols):
                if (rows,cols) in self.matrix.keys():
                    if type_as_str(right) == type_as_str(self) and (rows,cols) in right.matrix.keys():
                        new_object.matrix[(rows,cols)] = self.matrix[(rows,cols)] + right.matrix[(rows,cols)]
                    else: 
                        new_object.matrix[(rows,cols)] = self.matrix[(rows,cols)] + right
                    if new_object.matrix[(rows,cols)] == 0:
                        del new_object.matrix[(rows,cols)]
                    
        return new_object
    
    
    def __radd__(self, left):
        return self.__add__(left)
    
    def __sub__(self, right):
        if type_as_str(right) != type_as_str(self) and type(right) != int and type(right) != float: raise TypeError('SparseMatrix.__add__: argument given is not valid for addition')
        if type_as_str(right) == type_as_str(self):
            assert len(self) == len(right),('SparseMatrix.__add__: length of matrices are not the same, cannot add')
        new_object = Sparse_Matrix(self.rows, self.cols)
        for rows in range(self.rows):
            for cols in range(self.cols):
                if (rows,cols) in self.matrix.keys() or (rows,cols) in right.matrix.keys():
                    if type_as_str(right) == type_as_str(self):
                        new_object.matrix[(rows,cols)] = self.matrix[(rows,cols)] - right.matrix[(rows,cols)]
                    else: 
                        new_object.matrix[(rows,cols)] = self.matrix[(rows,cols)] - right
                    if new_object.matrix[(rows,cols)] == 0:
                        del new_object.matrix[(rows,cols)]
                
        return new_object
       
        
    def __rsub__(self, left):
        if type_as_str(left) != type_as_str(self) and type(left) != int and type(left) != float: raise TypeError('SparseMatrix.__add__: argument given is not valid for addition')
        if type_as_str(left) == type_as_str(self):
            assert len(self) == len(left),('SparseMatrix.__add__: length of matrices are not the same, cannot add')
        new_object = Sparse_Matrix(self.rows, self.cols)
        for rows in range(self.rows):
            for cols in range(self.cols):
                if type_as_str(left) == type_as_str(self):
                    new_object.matrix[(rows,cols)] = left.matrix[(rows,cols)] - self.matrix[(rows,cols)] 
                else: 
                    new_object.matrix[(rows,cols)] = left - self.matrix[(rows,cols)]
                if new_object.matrix[(rows,cols)] == 0:
                    del new_object.matrix[(rows,cols)]
                
        return new_object
    
    
    def __mul__(self, right): 
        if type_as_str(right) != type_as_str(self) and type(right) != int and type(right) != float: raise TypeError('SparseMatrix.__add__: argument given is not valid for addition')
        if type_as_str(self)== type_as_str(right):
            assert (self.rows == right.cols and self.cols == right.rows) or (self.rows != right.rows and self.cols != right.cols),'SparseMatrix.__add__: length of matrices are not the same, cannot add'
        new_object = Sparse_Matrix(self.rows, right.cols) if type_as_str(self) == type_as_str(right) else Sparse_Matrix(self.rows, self.cols)
        for rows in range(self.rows):
            row = self.row(rows) 
            if type_as_str(self) == type_as_str(right):
                for cols in range(self.rows):
                    col = right.col(cols) 
                    new_value = 0
                    for x in range(len(row)):
                        new_value += row[x]*col[x]
                    if new_value != 0: new_object.matrix[(rows,cols)] = new_value
            else:
                for cols in range(self.cols):
                    if (rows,cols) in self.matrix.keys():
                        if right != 0:
                            new_object.matrix[(rows,cols)] = self.matrix[(rows,cols)] * right
                    
        return new_object
    
    
    def __rmul__(self, left):
        return self.__mul__(left)
    
    
    def __pow__(self, right):
        if type(right) != int: raise TypeError('Sparse_Matrix.__pow__: parameter should be a non-negative integer')
        assert right > 0 and self.rows == self.cols, 'Sparse_Matrix.__pow__: parameter should be a greater than zero and matrix should be square'
        new_object = Sparse_Matrix(self.rows, self.cols)
        for rows in range(self.rows):
            for cols in range(self.cols):
                if (rows,cols) in self.matrix.keys():
                    value = self.matrix[(rows,cols)]
                    for times in range(right-1):
                        value *= self.matrix[(rows,cols)]
                    new_object.matrix[(rows,cols)] = value
        
        return new_object
                        
                        
    def __eq__(self, right):
        if type_as_str(self) == type_as_str(right):
            for keys in self.matrix.keys():
                if keys not in right.matrix.keys(): return False
                if self.matrix[keys] != right.matrix[keys]: return False
            for key in right.matrix.keys():
                if key not in self.matrix.keys(): return False
                if right.matrix[key] != self.matrix[key]: return False
                
        elif type(right) == int:
            for rows in range(self.rows):
                for cols in range(self.cols):
                    if (rows,cols) not in self.matrix.keys() and right != 0: return False
                    elif (rows,cols) in self.matrix.keys(): 
                        if self.matrix[(rows,cols)] != right: return False  
        else: return False     
        
        return True
    
    
    def __req__(self, left):
        return self.__eq__(left)
    

    def __ne__(self,right):
        if self.__eq__(right): return False
        
        return True
    
    
    def __setattr__(self, name, value):
        assert name == 'matrix' or name == 'rows' or name == 'cols', 'Sparse_Matrix.__setattr__: Cannot add new attribute to Sparse Matrix Class Object'
        if name in self.__dict__:
            assert value == None, 'Sparse_Matrix.__setattr__: Cannot modify existing attributes in Sparse Matrix Class Object'
        self.__dict__[name] = value
        
        return None
        
        
    # I've written str(...) because it is used in the bsc.txt file and
    #   it is a bit subtle to get correct. This function does not depend
    #   on any other method in this class being written correctly, although
    #   it could be simplified by writing self[...] which calls __getitem__.   
    def __str__(self):
        size = str(self.rows) + 'x' + str(self.cols)
        width = max(len(str(self.matrix.get((r,c),0))) for c in range(self.cols) for r in range(self.rows))
        return size+':['+('\n'+(2+len(size))*' ').join ('  '.join('{num: >{width}}'.format(num=self.matrix.get((r,c),0),width=width) for c in range(self.cols))\
                                                                                             for r in range(self.rows))+']'





if __name__ == '__main__':
    
    #Simple tests before running driver
    print('Printing')
    m = Sparse_Matrix(3,3, (0,0,1),(1,1,3),(2,2,1))
    print(m)
    print(repr(m))
    print(m.details())
  
    print('\nsize and len')
    print(m.size(),len(m))
    
    print('\ngetitem and setitem')
    print(m[1,1])
    m[1,1] = 0
    m[0,1] = 2
    print(m.details())

    print('\niterator')
    for r,c,v in m:
        print((r,c),v)
    
    print('\nm, m+m, m+1, m==m, m==1')
    print(m)
    print(m+m)
    print(m+1)
    print(m==m)
    print(m==1)
    print()
    
    #driver tests
    import driver
    driver.default_file_name = 'bsc2.txt'
#     driver.default_show_exception=True
#     driver.default_show_exception_message=True
#     driver.default_show_traceback=True
    driver.driver()
