#hw6.py
#Student Health Record System
#Derek Yang
#63118832


import math
from graphics import *


def checkClickPosition(click):
# TODO: click is the Point from the user mouse click
# The function should return the button number selected
    x=click.getX()
    y=click.getY()
    if x>=44 and x<=56 and y<=37 and y>=33:
        op=1
        return op
    elif x>=44 and x<=56 and y<=32 and y>=28:
        op=2
        return op
    elif x>=44 and x<=56 and y<=27 and y>=23:
        op=3
        return op
    elif x>=44 and x<=56 and y<=22 and y>=18:
        op=4
        return op
    elif x>=44 and x<=56 and y<=17 and y>=13:
        op=5
        return op
    elif x>=44 and x<=56 and y<=7 and y>=3:
        op=6
        return op
    else:
        op=7
        return op

def convertToBMI(weight, height):
    bmi = int(weight) / (int(height) *int(height)) * 703
    return bmi

def bmiResult(bmi):
#TODO: Check what BMI category the student is using bmi
    if bmi<=18.5:
        bmiresult="Underweight"
    elif bmi>=18.5 and bmi<=24.9:
        bmiresult="Normalweight"
    elif bmi>=25 and bmi<=29.9:
        bmiresult="Overweight"
    else:
        bmiresult="Obese"
    return bmiresult

def targetWeight(bmi, weight, height):
    optimalweight =0
    if bmi<= 18.5 or bmi>25:
        optimalbmi = (18.5+24.9)/2
        #TODO:
        #Calculate the optimal weight using optimalbmi, height and weight
        optimalweight=(optimalbmi*height*height)/703
        return int(optimalweight)
    else:
        return weight


def main():
    win = GraphWin("Student Health Record System", 600, 400)
    win.setCoords(0.0, 0.0, 60, 40)
    textFn = Text(Point(6, 35), "File Name:")
    textFn.draw(win)
    textId = Text(Point(6, 31), "Student ID:")
    textId.draw(win)
    textName = Text(Point(6, 27), "Student Name:")
    textName.draw(win)
    textWeight = Text(Point(6, 23), "Weight(Lbs):")
    textWeight.draw(win)
    textHeight = Text(Point(6, 19), "Height(Inches):")
    textHeight.draw(win)
    bmiLetter = Text(Point(6, 15), "BMI Category:")
    bmiLetter.draw(win)

    
    textButtonOpen = Text(Point(50, 35), "Open")
    textButtonOpen.draw(win)
    textButtonAdd = Text(Point(50, 30), "Find Student")
    textButtonAdd.draw(win)
    textButtonFind = Text(Point(50, 25), "Add Student")
    textButtonFind.draw(win)
    textButtonSave = Text(Point(50, 20), "Change Weight")
    textButtonSave.draw(win)
    textButtonTarget = Text(Point(50, 15), "Advise Weight")
    textButtonTarget.draw(win)
    textButtonQuit = Text(Point(50, 5), "Quit")
    textButtonQuit.draw(win)
    textMessage = Text(Point(20, 5), "Enter the health record file name and click Open.")
    textMessage.setTextColor("Blue")
    textMessage.draw(win)
    
    buttonOpen = Rectangle(Point(56,33),Point(44,37))
    buttonOpen.draw(win)
    buttonFind = Rectangle(Point(56,28),Point(44,32))
    buttonFind.draw(win)
    buttonAdd = Rectangle(Point(56,27), Point(44,23))
    buttonAdd.draw(win)
    buttonSave = Rectangle(Point(56,22), Point(44,18))
    buttonSave.draw(win)
    buttonTarget = Rectangle(Point(56,17), Point(44,13))
    buttonTarget.draw(win)
    buttonQuit = Rectangle(Point(56,7), Point(44,3))
    buttonQuit.draw(win)
                          
    fnInput = Entry(Point(24, 35), 25)
    fnInput.draw(win)
    idInput = Entry(Point(24, 31),25)
    idInput.draw(win)
    nameInput = Entry(Point(24,27),25)
    nameInput.draw(win)
    weightInput = Entry(Point(24,23),25)
    weightInput.draw(win)
    heightInput = Entry(Point(24,19),25)
    heightInput.draw(win)
    bmiTextInput = Entry(Point(24, 15), 25)
    bmiTextInput.draw(win)

    #TODO: create all lists to be used in the program
    id_lst=[]
    name_lst=[]
    weight_lst=[]
    height_lst=[]
    opened=0
   
    while True: # This is the main loop
        click = win.getMouse()
        op = checkClickPosition(click)
        if op == 1: #click on Open
        #Operations for opening a file, read info into lists and close the file
            fn=fnInput.getText()
            filein=open(fn,'r')
            read=filein.readlines()
            length=len(read)
            filein.seek(0)
            for i in range(length):
                lines=filein.readline()
                if lines=="\n":
                    pass
                else:
                    linesplit=lines.split("\t")
                    id_lst.append(linesplit[0])
                    name_lst.append(linesplit[1])
                    weight_lst.append(linesplit[2])
                    height_lst.append(linesplit[3])
            opened=1    
            textMessage.setText("File {0} opened".format(fn))            
                
        elif op == 2: #click on Find
        #Operations for Finding a Student
            idnum=idInput.getText()
            tf=idnum in id_lst
            if opened==1:
                if tf==True: #If there exists a student with the Student ID
                    pos=id_lst.index(idnum)
                    nameInput.setText(name_lst[pos])
                    weightInput.setText(weight_lst[pos])
                    heightInput.setText(height_lst[pos])
                    bmi=convertToBMI(int(weight_lst[pos]),int(height_lst[pos]))
                    bmiresult=bmiResult(bmi)
                    bmiTextInput.setText(bmiresult)
                    textMessage.setText("Student with ID{0} found in the system".format(idnum))
                else: #If there is no student with the student ID
                    textMessage.setText("Student with ID{0} does not exist".format(idnum))
                    nameInput.setText("")
                    weightInput.setText("")
                    heightInput.setText("")
                    bmiTextInput.setText("")
            else:
                textMessage.setText("You have not opened a file yet")
                pass
                
        elif op == 3: #click on Add
        #Operations for Adding a Student
            name=nameInput.getText()
            idnum=idInput.getText()
            weight=weightInput.getText()
            height=heightInput.getText()
            if opened==1:
                if idnum in id_lst: #If there exists a student with the student ID 
                    textMessage.setText("Student ID already exist in the system")
                else: #If there is no student with the student ID
                    if name=="" or weight=="" or height=="":
                        textMessage.setText("Information for Student{0} is missing".format(idnum))
                    else:    
                        id_lst.append(idnum)
                        name_lst.append(name)
                        weight_lst.append(weight)
                        height_lst.append(height)
                        textMessage.setText("Student Information has been added")
            else:
                textMessage.setText("You have not opened a file yet")
                pass
                
        elif op == 4: #click on Change Weight
        #Operations for changing the weight of a student
            idnum=idInput.getText()
            tf=idnum in id_lst
            weight=weightInput.getText()
            if opened==1:
                if tf==True : #If there exists a student with the student ID, change weight
                    pos=id_lst.index(idnum)
                    weight_lst[pos]=weight
                    textMessage.setText("Student's Weight has been changed")
                else: #If there is no student with the student ID
                    textMessage.setText("Student with ID{0} does not exist".format(idnum))
            else:
                textMessage.setText("You have not opened a file yet")
                pass
               
        elif op == 5: #click on Advise Weight
        #Operations for checking a Student's weight
            idnum=idInput.getText()
            tf=idnum in id_lst
            if opened==1:
                if tf==True: # There exists a student with the given student ID
                    pos=id_lst.index(idnum)
                    bmi=convertToBMI(weight_lst[pos],height_lst[pos])
                    bmiresult=bmiResult(bmi)
                    if bmiresult=="Normalweight": #If the student is in the right weight range
                        textMessage.setText("Student's target weight is {0}lbs".format(weight_lst[pos]))
                    else: #If the student is underweight or overweight or obese
                        weightx=eval(weight_lst[pos])
                        heightx=eval(height_lst[pos])
                        targetweight=targetWeight(bmi,weightx,heightx)
                        textMessage.setText("Student{0}'s target weight is {1}lbs".format(id_lst[pos],targetweight))
                else: #If there is no student with the student ID
                    textMessage.setText("Student with ID{0} does not exist".format(idnum))
            else:
                textMessage.setText("You have not opened a file yet")
                pass
                    
        elif op == 6: #click on Quit
            #Writing the lists to the file and get out of the main loop
            if opened==1:
                filein.close()
                outfile=open(fn,'w')
                lp=len(id_lst)
                for i in range(lp):
                    outfile.write(id_lst[i])
                    outfile.write("\t")
                    outfile.write(name_lst[i])
                    outfile.write("\t")
                    outfile.write(weight_lst[i])
                    outfile.write("\t")
                    outfile.write(height_lst[i])
                    outfile.write("\n")
                outfile.close()
                break
            else:
                break
        else:
            # possible error conditions
            pass
            
    win.close()

main()
