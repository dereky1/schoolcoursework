#hw5.py
#Magic Square
#Derek Yang
#63118832

from graphics import*
from time import*
from math import*

#Flying Numbers Starting from (x,y) to (x,y)
def move(obj, startX, startY, endX, endY):
    moveX = endX - startX
    moveY = endY - startY
    obj.move(moveX,moveY)
    return 

#Calculating Actual (x,y) Coordinate Given (column,row,width)
def calculateCoordinates (column,row,linespace):
    xcolumn = 8 + (linespace * column)
    xmidcol = xcolumn - (linespace / 2)
    x = xmidcol
    yrow = 12 + (linespace * row)
    ymidrow = yrow - (linespace / 2)
    y = ymidrow
    return x,y

def findrow(ycoord,linespace,numoflines):
    gridheight = numoflines*linespace
    xrow =((ycoord-12)/linespace)
    remain = xrow - (int(xrow)*linespace)
    if xrow > ((int(xrow)*linespace)+(linespace/2)):
        row = floor(xrow)
        return row
    elif xrow < ((int(xrow)*linespace)+(linespace/2)):
        row = ceil(xrow) 
        return row

def findvertical(xcoord,linespace,numoflines):
    gridheight = numoflines*linespace
    ycolumn =((xcoord-8)/linespace)
    if ycolumn > ((int(ycolumn)*linespace)+(linespace/2)):
        column = floor(ycolumn)
        return column
    elif ycolumn < ((int(ycolumn)*linespace)+(linespace/2)):
        column = ceil(ycolumn) 
        return column

def main():
    win = GraphWin("Magic Square", 500, 500)
    win.setCoords(0,0,100,100) 
    
    #Initialization
    entrytxt = Text(Point(8,95),"Square Size:")
    entrytxt.setSize(9)
    entrytxt.draw(win)
    squareentry = Entry(Point(21,95),6)
    squareentry.draw(win) 
    starttxt = Text(Point(60,95),"Please enter the square size and click the Draw button")
    starttxt.setSize(9)
    starttxt.draw(win)

    #Buttons
    drawbut = Rectangle(Point(6,6),Point(14,10.5))
    drawbut.draw(win)
    drawtxt = Text(Point(9.75,8.5),"Draw")
    drawtxt.setSize(9)
    drawtxt.draw(win)
    exitbut = drawbut.clone()
    exitbut.move(15,0)
    exitbut.draw(win)
    exittxt = Text(Point(24.75,8.5),"Exit")
    exittxt.setSize(9)
    exittxt.draw(win)
    
    
    line_list = []
    clear_flag = False
    once = True
    first=0
   
    while(once):
        click0 = win.getMouse()
        clickx = click0.getX()
        clicky = click0.getY()
        
        #Clicking the exit button
        if clickx >= 21 and clickx <= 29 and clicky <= 10.5 and clicky >= 6:
            starttxt.setText("Good-Bye!!!")
            sleep(0.5)
            win.close()
            break

        while squareentry.getText() == "": #Doesn't cause error for misclicks
            starttxt.setText("Square Size invalid. Please enter Square Size and click Draw")
            starttxt.setOutline("red")
            click0 = win.getMouse()
            clickx = click0.getX()
            clicky = click0.getY()  
        
        #Clicking the draw buttom
        if clickx >= 6 and clickx <= 14 and clicky <= 10.5 and clicky >= 6: #clicked on the Draw Button, then redraw everythi    
            while squareentry.getText() == "": #Doesn't cause error for misclicks
                starttxt.setText("Square Size not entered. Please enter Square Size")
                starttxt.setOutline("red")
                click0 = win.getMouse()
                clickx = click0.getX()
                clicky = click0.getY()
            squaresize = int(squareentry.getText())
            linespace = floor(80/squaresize)
            graphsize = linespace * squaresize
            numoflines = graphsize / linespace
            if first >= 1:
                grid.undraw()
                for i in line_list:
                    i.undraw()
                for i in nums:
                    i.undraw()
            bottom = Point(8,12)
            top = Point(8 + graphsize,12 + graphsize)    
            grid = Rectangle(bottom,top)
            grid.draw(win)
            gline = 0
            xline = 0
            for a in range(int(numoflines)):
                gline = gline + linespace
                ggline = Line(Point(8+gline,12),Point(8+gline,12+graphsize))
                ggline.draw(win)
                line_list.append(ggline)
            for b in range(int(numoflines)):
                xline = xline + linespace
                xxline = Line(Point(8,12+xline),Point(8+graphsize,12+xline))
                xxline.draw(win)
                line_list.append(xxline)
            first=first+1

        #list for the numbers in the grid
        numLst=[]            
        for i in range(int(numoflines)):
            numLst.append([])
            for j in range(int(numoflines)):
                numLst[i].append(0)
        
        nums = [] 
        starttxt.setText("Please enter which cell to start 1:")
        starttxt.setOutline("black")
        click2 = win.getMouse()
        ccx = click2.getX()
        ccy = click2.getY()

        #Checking for clicks outside the grid
        while ccx < 8 or ccx > (8+(numoflines*linespace)) or ccy < 12 or ccy > (12+(linespace*numoflines)):
            starttxt.setText("You have clicked an invalid box, Please click again inside.")
            starttxt.setOutline("red")
            click2 = win.getMouse()
            ccx = click2.getX()
            ccy = click2.getY() 
        cy = findrow(ccy,linespace,numoflines)
        cx = findvertical(ccx,linespace,numoflines)
        starttxt.setText("Please wait for the numbers to finish their flight...")
        starttxt.setOutline("black")

        #Checking if space is filled or not
        for k in range(int(numoflines)*int(numoflines)): # loop thru all numbers
            if numLst[cx-1][cy-1] == 0:
                numLst[cx-1][cy-1] = 1
            else: 
                cx = cx-1
                if cx < 1:
                    cx = int(numoflines)-cx
                cy = cy+2
                if cy > int(numoflines):
                    cy = cy - int(numoflines)
                numLst[cx-1][cy-1] = 1

            #Making the numbers fly    
            x, y = calculateCoordinates(cx,cy,linespace) 
            number = Text(Point(5, 85),str(k+1))
            number.draw(win)
            for d in range(10):
                sleep(0.1)
                move(number, 5/10, 85/10, x/10, y/10)
            nums.append(number) 
            cx = cx+1
            cy = cy-1
            if cx > int(numoflines):
                cx = int(numoflines)-(cx-2)
            if cy < 1:
                cy = int(numoflines)+(cy)
                if cy > int(numoflines):
                    cy = cy - int(numoflines)
        starttxt.setText("Please enter the square size and click the Draw button")                

    #Friendly goodbye message after exiting
    print("Thankyou for using the Magic Square!")
    print("Have a nice day!")
    
main()
