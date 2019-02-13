# A Black_Hole is a Simulton; it updates by removing
#   any Prey whose center is contained within its radius
#  (returning a set of all eaten simultons), and
#   displays as a black circle with a radius of 10
#   (width/height 20).
# Calling get_dimension for the width/height (for
#   containment and displaying) will facilitate
#   inheritance in Pulsator and Hunter

from simulton import Simulton
from prey import Prey
import model

class Black_Hole(Simulton):
    radius = 10
    def __init__(self, x, y):
        Simulton.__init__(self, x, y, 20, 20)
        
    def update(self):
        black_holed = set()
        for i in model.find(lambda x: isinstance(x, Prey)):
            if self.contains(i.get_location()):
                black_holed.add(i)
                model.remove(i)
        return black_holed
        
        
    def display(self, canvas):
        x,y = self.get_dimension()
        canvas.create_oval(self._x-x/2, self._y-y/2, self._x+x/2, self._y+y/2, fill='black')
    
    def contains(self, xy):
        return Simulton.distance(self, xy) < self.radius