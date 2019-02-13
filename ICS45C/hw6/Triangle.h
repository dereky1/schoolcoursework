#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Shape.h"

class Triangle 
	:public Shape 
{
protected:
	double height;
	double base;
public:
	Triangle(int new_centerX, int new_centerY,double new_height,double new_base)
		:Shape("Triangle",new_centerX,new_centerY), height(new_height),base(new_base)
	{
	}
	virtual double area()
	{
		return (base*height)/2;
	}
	virtual void draw()
	{
		cout << "Shape: " << string_name<< endl;
		cout << "Base: " << base << "  Height: " << height << endl;
		for(int i=0; i<height; ++i)
		{
			for(int j=0; j<height-i; ++j)
				cout<<' ';	
			for(int k=0; k<i+1; ++k)
				cout<<"/";
			for(int l=0; l<i+1; ++l)
				cout<<"\\";
			cout<<endl;
		}
		cout<< endl;
	}
	~Triangle()
	{	
	}
};

#endif
