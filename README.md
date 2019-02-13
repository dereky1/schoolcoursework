CS112 Computer Graphics
-Using C++ and OpenGL
--Assignment 2 : The goal of the project is to compute all the transformation matrices with your library
instead of using OpenGL library. These functions include Matrix and Stack Manipulation Functions, Matrix Mode Function for Operations, gluLookAt Function and animation Functions.

--Assignment 3 : Implement your own lighting and compare it with OpenGL
lighting. Implement Lighting Equation, Passing Light Equation Parameters to OpenGL.

--Assignment 4 : Applying texture mapping in OpenGL

======

CS116 Computational Photography
-Using Matlab:
--Assignment 1 : MATLAB warmup and color demosaicing 
We will use MATLAB for the programming assignments so this assignment is to help you get acquainted. You will also work with image filtering.

--Assignment 2 : Mosaics 
For this assignment we will estimate homographies in order to align images and blend them into a mosaic.

--Assignment 3 : Texture Synthesis 
For this assignment we will synthesize textures by stitching together randomly sampled tiles.

--Assignment 4 : Detection 
For this assignment we will build a simple template-based object detector using orientation histograms.

--Assignment 5 : Warping and Morphing 
For this assignment we will explore image warping in order to produce a morph between two images 

======

CS143A Principles of Operating Systems
-Using C in Linux
--Assignment 1 : Write a C program, called average, that reads a series of numbers from a file, whose name is specified as an argument, then prints the average of those numbers.

--Assignment 2 : Basic Signal Handling
Write a program that can send and catch signal.

--Assignment 3 : Write a program, called my_fork, and an associated Makefile, named Makefile_my_fork, that uses fork() to create a total of 4 processes each printing one letter of the alphabet from A to D K times.  K will be a command line argument, but should default to 10.  Have each process flush the output after printing each character with fflush(stdout). For initial testing, you may want to use K of 1.

--Assignment 4 :Write a modified version of the program compute from HW1 such that the work for aggregating the input integers is split approximately evenly across 4 threads.  To do this, you’ll need to read in all the numbers into a buffer first.  Then, create 3 pthreads and have all 4 threads aggregate approximately ¼ each of all the integers.  Don’t use synchronization primitives for this part as we’ll be adding them in Part 3. 

--Assignment 5 : Write code to synchronize multiple threads. For each file, a separate thread (producer) will be created to read each line from the file and place each line in the circular buffer.  A total of 2 consumer threads will be created to read one line at a time from the buffer, search the line for the fixed word, and increment a shared counter if it has been found.  After all files have been fully read through and the circular buffer is empty, the main thread prints the final count of occurrences of the given word and then the program terminates. Note you will see errors due to race conditions.

--Assignment 6 : Write a program to implement the banker’s algorithm for avoiding deadlock.  The program should be submitted as a source file called banker.c, with a Makefile called Makefile that outputs a binary file called banker.  The program will take input from the user to set up the appropriate resource tracking tables and output whether the system is in a is a safe state (along with the safe sequence of executions) or not.

--Assignment 7 : Write a program that behaves exactly like the Unix command ls -lLR.  The C program should be submitted as a source file called myls.c, with a Makefile called Makefile_myls that outputs a binary file called myls.  You will want to use the stat system call from C and you will need to determine how to recurse into directories.

--Extra Credit Assignment : The goal of this assignment is to implement your own malloc and free functions on a simulated disk, represented by a char array named disk.

======

CS143B Operating Systems Projects 
-Using C++
--Assignment 1 : Resource Manager
Create a program that would simulate resource management by reading a specific input file to set up the different resources and ammount of resources then using another set of input to simulate process requesting resources and printing out the resource usage of the simulation.

--Assignment 2 : Process Scheduling
Create a program that would show how different process scheduling algorithms will result in different squence of process completing their jobs. The scheduling methods include First In First Out (FIFO), Shortest Job First (SJF), Shortest Remaining Time (SRT) and Round Robin (MLF).

--Assignment 3 : Memory Management
Create a program that simulates memory allocation based on specific input given.

======

EECS12 Intro to Python
-Using Python
--Assignment 1 : Simple program that calculates future value of investments given user imput of time, principal and interest rate. Outputs results of year 0 to 10 under simple and compound interest.

--Assignment 2 : Simple program that calculates the angle and the x,y coordinates of a ball at an interval of time given the inputs of starting velocity and angle.

--Assignment 3 : Simple program that uses the GUI library to create a new window canvas that allows the user to draw a Christmas tree by clicking the position to draw shapes on the new window.

--Assignment 4 : Simple program that takes in a year and a month and the first day to generate a formated text based calendar.

--Assignment 5 : Simple program that asks user for a integer input n and it will create a matrix of nxn that is filled with 1-n where all numbers in a row and column will always add up to the same number.

--Assignment 6 :  Simple program that reads from an input file for student health records and has a GUI that allows user to modify or add new records and save them by exporting back to the input file.

======

EECS20 Intro to Assembly
-Using x86 Assembly Code

======

EECS22 Adv C Programming
-Using C in Linux
--Assignment : Using Linked-Lists as an array to hold image RGB information and create functions to manipulate images.

=====

EECS31L Introduction to Digital Logic Design Laboratory
-Using VHDL
--Assignment 1 : Implement basic Gate-Level blocks.

--Assignment 2 : Implement a 1-but ALU.

--Assignment 3 : Implement a 32-bit ALU.

--Assignment 4 : Implement a Register Block, Counter Block and Register File Block.

--Assignment 5 : Implementing Simple Memory Block.

--Final Assignment : Implement a single-cycle processor.

======

ICS32 Python II
-Using Python
--Assignment 1 : Simple file manager that searches for a file by name, extension or size and allows the user to choose what to so to the file such as print the path, open the file, duplicate or touch it.

--Assignment 2 : Create the game logic for Connect 4 game checking whether or not a move is legal and whether a player has won the game.

--Assignment 3 : Simple GPS program that uses MapQuest API to get diretions for navigation. The API spits JSON and the program reads it to get turn by turn directions, the distance, the time, the latitude and longitude and the elevation.

--Assignment 4 : Create a playable Othello game. Implemented game logic and later on added a GUI on top of the game logic.

======

ICS 33 Python Intermediate Programming
-Using Python in Eclipse
--Assignment 1 : This programming assignment is designed to ensure that you know how to use combinations of Python's most important data types to model and compactly write code that solves a wide variety of different programming problems.

--Assignment 2 : This programming assignment is designed first to ensure that you know how to write classes that overload many of the standard Python operators by defining various double-underscore methods. It also ensures that you know how to write classes that implement iterators, by defining an __iter__ method that returns an object that we/Python can call __next__ on.

--Assignment 3 : This programming assignment is designed to show how Python functions can define other Python code (in this case, a class) in an unexpected way: the function can build a huge string that represents the definition of a Python class and then call exec on it, which causes Python to define that class just as if it were written in a file and imported (in which case Python reads the file as a big string and does the same thing). 

--Assignment 4 : A series of assignments that explore Mutual Recursion

--Assignment 5 : A little simulation/game that allows the user to add ball objects that interact with other ball objects in an external window using the Tkinter library. They balls are animated and bounce within the frame of the window. This project explores on the topic of inheritance of classes as each type of ball is implemented by expanding on another.

======

ICS45C Programming in C++
-Using C++
--Assignment 1 : Write a class, called  Stack, in a file called stack.h, that implements a stack of up to 1000 characters. Write a main function that repeatedly reads a line into a std:: string character string variable, str, from  cin and then outputs the reverse of that line by pushing the characters onto an instance of your stack class, then printing them as they are removed from the stack. Do this for each line in the input. 

--Assignment 2 : Write a class, called Coins, that is a holder for a variety of coins. This has no way to split coins or to receive change back from a transaction, so it must pay with exact change. Write a third main, that presents a menu interface to your program that allows the user to deposit change, extract change, and to print balance in a single coins object called myCoins.

--Assignment 3 : Write a String class which will be a wrapper class to the C style strings. Your String class must implement all the appropriate methods including constructors, assignment, equality operators, the index operator [], reverse, indexOf, print, and read. Write a main function, in a file called  string_test.cpp, which tests each public method defined in your class String.

--Assignment 4 : You will rewrite a String class which will be a wrapper class to the C style strings. However, the strings will be of varying lengths and the arrays which hold them must grow and shrink as necessary. Your String class must implement all the appropriate methods including constructors/destructor, assignment, equality operators, the index operator, reverse, indexOf, print, and read. You will use dynamic allocation and deallocate the dynamically created arrays when you no longer need them. A new private static method, strdup(), will allocate the right amount of storage and make an exact copy of the string passed in as argument, then return the address of that new storage.

--Assignment 5 : Re-write the String class but use a singly-linked list of character as the representation. Like last week, these strings will be of varying lengths and must grow and shrink as necessary. Implement all the appropriate methods given below. Use memory storage proportional to the number of characters in the string.

--Assignment 6 : Define an abstract base class, called Shape, with two pure virtual functions:  double area() and void draw(). Derive a total of four classes from Shape: derive three classes (Circle, Rectangle, and Triangle) directly from your abstract base class and make them concrete by providing implementations for the pure virtual functions introduced in your abstract base class Shape. Derive the fourth class, Square, from Rectangle. Write a class Picture that holds a list of Shapes.

--Assignment 7 : Define a template class Matrix that behaves like a two dimensional array. Define an exception class, IndexOutOfBoundsException, and have your Array and Matrix class throw an instance of it if any index is out of bounds. Add another function, test_double_matrix_exceptions(), which will catch this exception and do something appropriate, like print an error message and continue processing.

--Assignment 8 : Use STL containers, iterators, algorithms, and lambdas, functions or function objects to write the two programs described below. Write a program called mapset.cpp that counts the frequency of occurrence of each word in the file sample_doc.txt while excluding certain common words. Ignore letter case differences. Write another program called process_numbers.cpp that reads a sequence of integers from the file rand_numbers.txt. Your program should put the integers in a vector, sort them in ascending order, and output them into two different files depending on if they are odd or even.

--Assignment 9 : You will define a class called SetList to use instead of Set or Vector for holding the excluded stop words.  You will define a class called MapArray to use instead of Map for the data structure that keeps counts of frequency of words. Write a class SetList and a class iterator inside class SetList that allows forward iteration through it.

======

ICS51 Introduction to Computer Organization
-Using x86 Assembly/C
--Assignment 2 : Use Assembly code to flip an image vertically and modifying an image based on a threshold of a pixel.

--Assignment 3 : Use Assembly to implement selection sort, preform recursive factorial, use vector operations, change the upper and lower case of strings and fibonacci function.

======

ICS53 Principles in System Design
-Using C in Linux
--Assignment 1 : You will write a very simple text adventure game. When the game is started, a “$” prompt is printed on the screen to let the player know that he/she can type in a new command. To start playing, the player will need to load a dungeon file which describes the rooms in your dungeon and how they are connected. The player begins in an initial room which is specified in the dungeon file. When the dungeon file is loaded, the description of the initial room is printed on the screen, followed by a prompt on the next line. Then the player can issue commands to move in a direction, either north, south, east, or west. When a player moves, a description of the new room that he moves into is printed on the screen and the player is prompted to enter a new move.

--Assignment 2 : Uses forks to make a new process that allows parallel processing of data and then waiting for all new processes to stop when they they send their signal of completion.

--Assignment 3 : Implement a program that simulates memory allocation. The user can input commands to allocate memory, free memory, print the memory header, print out the heap, write heap and print blocks of memory.

--Assignment 4: Implement a simple client and server that allows them to communicate through text input.

======

ICS161 Game Engine Lab
-Using C# in Unity
--Game 1 : Simple launch a ball game. Launch the ball to knock building blocks into the water.

--Game 2 : Play as Unity-chan to escape the map. Run around finding whatever is necessary to escape.

--Game 3 : Two-player top down shooter survival game. Defend your vehicle from spiders while looking for tools to repair it. 

======

STATS67 Introduction to Probability and Statistics
-Using R in RStudio
--Assignments : Printing visuals from R using statistical data.
