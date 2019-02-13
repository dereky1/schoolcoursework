#ifndef SHAPE_H
#define SHAPE_H
#include <string>
#include <iostream>
using namespace std;

class Shape
{
protected:
	std::string string_name;
	int centerX;
	int centerY;
public:
	Shape(std::string new_string_name, int new_centerX, int new_centerY)
		:string_name(new_string_name), centerX(new_centerX), centerY(new_centerY)
	{
	}
	virtual double area()=0;
	virtual void draw()=0;
	virtual ~Shape()
	{	
	}
};

#endif
