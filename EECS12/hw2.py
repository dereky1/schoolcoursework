#hw2.py
#Parabolic Trajectory
#Derek Yang 63119932
#Incomplete

from math import*

def main():

    print("This program produces the parabolic trajectory of a ball.")
    V0 = eval(input("Enter the initial velocity : "))
    A0 = eval(input("Enter the initial angle, between 0 and 90:"))
    A = A0 * (pi / 180)
    Vx = V0 * cos(A)
    Vy = V0 * sin(A)
    t = 2 * (Vy / 10)
    lp = ceil(t)
    ai = .5
    g = 10
    Py = Vy
    Sx = Vx
    print("\t")
    print("Time         Angle                  Px                     Py ")
    print(0,"   ", float(round((A * (180 / pi)))),  "                 ", float(0), "                  ", float(0))
    for i in range(1, lp):
        ai = 3.9 * ai * (1 - ai)
        Vx = Vx - 0.1 * ai * Vx
        Vy = Vy - g 
        V = sqrt((Vx**2) + (Vy**2))
        A = asin(Vy /V)
        Px = Vx * i
        Py = Vy * i
        Sy = Vy * t - 5 * t**2
        Sx = Sx + Vx
        print(i ,"   ", A * (180 / pi) ,  "   ", Px, "   ", Py)
    print(" The ball totally travels: ", Sx)
    
main()
