#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape.h"
#include "Square.h"

class Rectangle 
	:public Square 
{
protected:
	double width;
public:
	Rectangle(int new_centerX, int new_centerY, double new_length, double new_width)
		:Square(new_centerX,new_centerY,new_length), width(new_width)
	{
		string_name = "Rectangle";
	}
	virtual double area()
	{
		return length*width;
	}
	virtual void draw()
	{
		cout << "Shape: " << string_name << endl;
		cout << "Length: " << length << "  Width: " << width<< endl;
		for(int i=0; i<length; ++i)
		{
			for(int j=0; j<width; ++j)
				cout << "||";
			cout<<endl;
		}
		cout<<endl;
	}
	~Rectangle()
	{	
	}
};

#endif
