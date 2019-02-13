# A Pulsator is a Black_Hole; it updates as a Black_Hole
#   does, but also by growing/shrinking depending on
#   whether or not it eats Prey (and removing itself from
#   the simulation if its dimension becomes 0), and displays
#   as a Black_Hole but with varying dimensions


from blackhole import Black_Hole
import model

class Pulsator(Black_Hole):
    counter = 30
    def __init__(self,x,y):
        Black_Hole.__init__(self, x, y)
        self.count = 0 
        
    def update(self):
        black_holed = Black_Hole.update(self)
        self.count += 1
        if self.get_dimension() == (0,0):
            model.remove(self)
        elif len(black_holed) != 0:
            self.change_dimension(2, 2)
            self.count = 0
            self.radius += 1
        elif self.count == Pulsator.counter:
            self.change_dimension(-2, -2)
            self.count = 0
            self.radius -= 1
        return black_holed