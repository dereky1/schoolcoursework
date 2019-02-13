#hw3.py
#Derek Yang
#63118832
#10/18/13
#EECS 12 - Introduction to Programming
#This program draws a festive tree using GUI interfaces

from math import*
from graphics import*

def main():

    win = GraphWin("Festival Tree", 800, 600)
    win.setCoords(0, 0, 40, 30)
    startingtxt = Text(Point(20, 29), "Please enter the number of layers and click anywhere")
    startingtxt.setOutline("red")
    startingtxt.draw(win)
    layerentrytxt = Text(Point(4,28),"Number of Layers:")
    layerentrytxt.draw(win)
    layerentry = Entry(Point(10, 28),10)
    layerentry.setText(4)
    layerentry.draw(win)
    introclick = win.getMouse()
    startingtxt.setText("Please click a point the top of the tree body")
    tipoftree = win.getMouse()
    tipoftree.draw(win)
    startingtxt.setText("Please click for the bottom corner of the tree body")
    bottomoftree = win.getMouse()
    bottomoftree.draw(win)
    tipx = tipoftree.getX()
    botx = bottomoftree.getX()
    tipy = tipoftree.getY()
    boty = bottomoftree.getY()
    mathx = tipx - botx
    thirdx = 2 * mathx
    xbottomoftree = bottomoftree.clone()
    xbottomoftree.move(thirdx,0)
    xbotx = xbottomoftree.getX()
    xboty = xbottomoftree.getY()
    treebody = Polygon(tipoftree, bottomoftree, xbottomoftree)
    treebody.setFill("darkgreen")
    treebody.setOutline("darkgreen")
    treebody.draw(win)
    for i in range(1,eval(layerentry.getText())):
        midpoint = (tipy - boty)/2
        tipy = tipy - midpoint 
        botx = botx - 2
        xbotx = xbotx + 2
        boty = boty - midpoint - 1
        xboty = xboty - midpoint - 1
        xtipoftree = Point(tipx, tipy)
        ybottomoftree = Point(botx, boty)
        yxbottomoftree = Point(xbotx, xboty)
        xtreebody = Polygon(xtipoftree, ybottomoftree, yxbottomoftree)
        xtreebody.setFill("darkgreen")
        xtreebody.draw(win) 
    startingtxt.setText("Please click for the bottom corner of the tree trunk")
    treetrunkcorner = win.getMouse()
    trunkx = treetrunkcorner.getX()
    trunky = treetrunkcorner.getY()
    mid = trunkx - tipx
    if trunkx <= fabs(mid):
        math2 = fabs(mid) * 2
    if trunkx >= fabs(mid):
        math2 = mid * -2
    xxtrunk = ybottomoftree.getY()
    heightof = xxtrunk - trunky
    treetrunkcornerclone = treetrunkcorner.clone()
    treetrunkcornerclone.move(math2, fabs(heightof))
    treetrunk = Rectangle(treetrunkcorner, treetrunkcornerclone)
    treetrunk.setFill("brown")
    treetrunk.draw(win)
    startingtxt.setText("Please click two points to set the center and radius of the ornament")
    ornament1center = win.getMouse()
    ornament1radius = win.getMouse()
    or1x = ornament1center.getX()
    or1y = ornament1center.getY()
    or1rx = ornament1radius.getX()
    or1ry = ornament1radius.getY()
    radius1 = sqrt(((or1x - or1rx)**2) + ((or1y - or1ry)**2))
    ornament1 = Circle(ornament1center, radius1)
    ornament1.setFill("yellow")
    ornament1.draw(win)
    startingtxt.setText("Please click again for another ornament")
    ornament2center = win.getMouse()
    ornament2radius = win.getMouse()
    or2x = ornament2center.getX()
    or2y = ornament2center.getY()
    or2rx = ornament2radius.getX()
    or2ry = ornament2radius.getY()
    radius2 = sqrt(((or2x - or2rx)**2) + ((or2y - or2ry)**2))
    ornament2 = Circle(ornament2center, radius2)
    ornament2.setFill("yellow")
    ornament2.draw(win)
    ornament3center = win.getMouse()
    ornament3radius = win.getMouse()
    or3x = ornament3center.getX()
    or3y = ornament3center.getY()
    or3rx = ornament3radius.getX()
    or3ry = ornament3radius.getY()
    radius3 = sqrt(((or3x - or3rx)**2) + ((or3y - or3ry)**2))
    ornament3 = Circle(ornament3center, radius3)
    ornament3.setFill("yellow")
    ornament3.draw(win)
    startingtxt.setText("Please enter the color of ornaments and click Update, or click Exit")
    ornament1text = Text(Point(6,5),"Color of Ornament 1:")
    ornament1text.draw(win)
    ornament1entry = Entry(Point(12,5),10)
    ornament1entry.setText("yellow")
    ornament1entry.draw(win)
    ornament2text = Text(Point(6,4),"Color of Ornament 2:")
    ornament2text.draw(win)
    ornament2entry = Entry(Point(12,4),10)
    ornament2entry.setText("red")
    ornament2entry.draw(win)
    ornament3text = Text(Point(6,3),"Color of Ornament 3:")
    ornament3text.draw(win)
    ornament3entry = Entry(Point(12,3),10)
    ornament3entry.setText("blue")
    ornament3entry.draw(win)
    trunktext = Text(Point(6,2),"Color of Tree Trunk :")
    trunktext.draw(win)
    trunkentry = Entry(Point(12,2),10)
    trunkentry.setText("purple")
    trunkentry.draw(win)
    updatebut = Rectangle(Point(16,3), Point(20,5))
    updatebut.setFill("skyblue")
    updatebut.draw(win)
    updatebuttext = Text(Point(18,4), "Update")
    updatebuttext.draw(win)
    exitbut = Rectangle(Point(22,3), Point(26,5))
    exitbut.setFill("red")
    exitbut.draw(win)
    exitbuttext = Text(Point(24,4), "Exit")
    exitbuttext.draw(win)
    updatemouse = win.getMouse()
    upx = updatemouse.getX()
    upy = updatemouse.getY()
    while upx >= 16 and upx <= 20 and upy >= 3 and upy <= 5:
        ornament1.setFill(ornament1entry.getText())
        ornament2.setFill(ornament2entry.getText())
        ornament3.setFill(ornament3entry.getText())
        treetrunk.setFill(trunkentry.getText())
        updatemouse = win.getMouse()
        upx = updatemouse.getX()
        upy = updatemouse.getY()
    else:
        if upx >= 22 and upx <= 26 and upy >= 3 and upy <= 5:
                win.close()
        
main()
