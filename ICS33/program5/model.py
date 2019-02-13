import controller, sys
import model   #strange, but we need a reference to this module to pass this module to update

from ball      import Ball
from floater   import Floater
from blackhole import Black_Hole
from pulsator  import Pulsator
from hunter    import Hunter
from special   import Special


# Global variables: declare them global in functions that assign to them: e.g., ... = or +=
running = False
cycle_count = 0
balls = set()
state = ''

#return a 2-tuple of the width and height of the canvas (defined in the controller)
def world():
    return (controller.the_canvas.winfo_width(),controller.the_canvas.winfo_height())

#reset all module variables to represent an empty/stopped simulation
def reset ():
    global running, cycle_count, balls
    running = False
    cycle_count = 0
    balls = set()


#start running the simulation
def start ():
    global running
    running = True


#stop running the simulation (freezing it)
def stop ():
    global running
    running = False


#tep just one update in the simulation
def step ():
    global running
    if not running:
        start()
    update_all()
    stop()


#remember the kind of object to add to the simulation when an (x,y) coordinate in the canvas
#  is clicked next (or remember to remove an object by such a click)   
def select_object(kind):
    global state
    state = kind


#add the kind of remembered object to the simulation (or remove any objects that contain the
#  clicked (x,y) coordinate
def mouse_click(x,y):
    global balls
    if state == 'Remove':
        for i in balls.copy():
            if i.contains((x,y)):
                remove(i)
    elif state == '':
        pass
    else:
        add(eval(state + '(x,y)'))

#add simulton s to the simulation
def add(s):
    global balls
    s.display(controller.the_canvas)
    balls.add(s)
    

# remove simulton s from the simulation    
def remove(s):
    global balls
    controller.the_canvas.delete(s)
    balls.remove(s)
    

#find/return a set of simultons that each satisfy predicate p    
def find(p):
    global balls
    return_set = set()
    for i in balls:
        if p(i):
            return_set.add(i)
    return return_set


#call update for every simulton in the simulation
def update_all():
    global cycle_count
    if running:
        cycle_count += 1
        for i in balls.copy():
            i.update()


#delete from the canvas every simulton in the simulation, and then call display for every
#  simulton in the simulation to add it back to the canvas possibly in a new location: to
#  animate it; also, update the progress label defined in the controller
def display_all():
    global balls
    for i in controller.the_canvas.find_all():
        controller.the_canvas.delete(i)
    for j in balls:
        j.display(controller.the_canvas)
    controller.the_progress.config(text = '{balls} items/{count} cycles'.format(balls = len(balls), count = cycle_count))