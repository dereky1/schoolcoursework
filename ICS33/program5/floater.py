# A Floater is Prey; it updates by moving mostly in
#   a straight line, but with random changes to its
#   angle and speed, and displays as ufo.gif (whose
#   dimensions (width and height) are computed by
#   calling .width()/.height() on the PhotoImage

#from PIL.ImageTk import PhotoImage
from prey import Prey
import random


class Floater(Prey):
    radius = 5
    def __init__(self,x,y):
        Prey.__init__(self, x, y, 10, 10, None, 5)
        self.randomize_angle()
        
    def update(self):
        if random.randint(1,100) <= 30:
            speed = (self.get_speed() + random.uniform(-.5,.5) if self.get_speed() + random.uniform(-.5,.5) > 3 else 3)
            angle = (self.get_angle() + random.uniform(-.5,.5) if self.get_angle() + random.uniform(-.5,.5) < 7 else 7)
            self.set_velocity(speed, angle)
        self.move()
    
    def display(self, canvas):
        canvas.create_oval(self._x-Floater.radius, self._y-Floater.radius, self._x+Floater.radius, self._y+Floater.radius, fill='red')