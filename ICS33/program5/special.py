'''
Created on Mar 7, 2016

@author: Derek
'''
'''
a rainbow bouncy ball. bounces off all other balls. every bounce, this ball will speed up and change colors. dies in 500 cycles.
'''
from prey import Prey
import controller
import model
import random

class Special(Prey):
    radius = 3
    life_span = 500
    colors = ['red', 'orange', 'yellow', 'blue', 'green', 'indigo', 'violet', 'black', 'grey', 'brown', 'pink', 'cyan']
    def __init__(self,x,y):
        Prey.__init__(self, x, y, 6, 6, None, 6)
        self.randomize_angle()
        self.age = 0
        self.color = 'white'
        
    def update(self):
        for i in model.balls:
            if self.age == Special.life_span:
                model.remove(self)
                break
            if self.distance(i.get_location()) <= (Special.radius + self.find_radius(i)) and i != self:
                self.set_velocity(self._speed*1.5, -self._angle)
                self.change_colors()
                controller.the_canvas.itemconfigure(self, fill = self.color)
        self.move()
        self.age += 1
            
    def find_radius(self, ball):
        return ball.radius
     
    def distance(self,xy):
        return ((self._x -xy[0])**2  + (self._y -xy[1])**2)**.5    
    
    def change_colors(self):
        self.color = Special.colors[random.randint(0,11)]
    
    def display(self, canvas):
        canvas.create_oval(self._x-Special.radius, self._y-Special.radius, self._x+Special.radius, self._y+Special.radius, fill=self.color)
