# A Hunter is both a Mobile_Simulton and a Pulsator: it updates
#   like a Pulsator, but it also moves (either in a straight line
#   or in pursuit of Prey), and displays as a Pulsator.


from pulsator import Pulsator
from mobilesimulton import Mobile_Simulton
from prey import Prey
from math import atan2
import model


class Hunter(Pulsator,Mobile_Simulton):
    locate_distance = 200
    def __init__(self,x,y):
        Mobile_Simulton.__init__(self, x, y, 10, 10, None, 5)
        Pulsator.__init__(self, x, y)
        self.randomize_angle()
        
    def update(self):
        self.move()
        black_holed = Pulsator.update(self)
        prey_list = {}
        for i in model.balls:
            if isinstance(i, Prey) and Hunter.distance(self, i.get_location()) <= Hunter.locate_distance:
                prey_list[self.distance(i.get_location())] = i.get_location()
        if len(prey_list) > 0:
            self._angle = atan2(prey_list[min(prey_list.keys())][1] - self._y, prey_list[min(prey_list.keys())][0] - self._x)  
        return black_holed
