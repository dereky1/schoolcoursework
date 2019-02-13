#ifndef SQUARE_H
#define SQUARE_H
#include "Shape.h"

class Square 
	:public Shape 
{
protected:
	double length;
public:
	Square(int new_centerX, int new_centerY, double new_length)
		:Shape("Square",new_centerX,new_centerY), length(new_length)
	{
	}
	virtual double area()
	{
		return length*length;
	}
	virtual void draw()
	{
		cout << "Shape: " << string_name << endl;
		cout << "Side: " << length << endl;
		for(int i=0; i<length; ++i)
		{
			for(int j=0; j<length; ++j)
				cout << "||";
			cout<<endl;
		}
	}
	~Square()
	{	
	}
};

#endif
