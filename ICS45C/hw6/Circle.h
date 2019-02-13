#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"
#define PI 3.14159265358979323846

class Circle 
	:public Shape 
{
protected:
	double radius;
public:
	Circle(int new_centerX, int new_centerY, double new_radius)
		:Shape("Circle",new_centerX,new_centerY), radius(new_radius)
	{
	}
	virtual double area()
	{
		return PI*(radius*radius);
	}
	virtual void draw()
	{
		cout << "Shape: "<< string_name<< endl;
		cout << "Radius: "<< radius << endl; 
                for(int j=0; j<radius/2-radius/3; ++j)
                        cout<<' ';
		for(int a=0; a< radius-radius/2; ++a)
			cout<< 'o';
		cout<<endl;
                for(int k=0; k<((int)radius/2); ++k)
		{
                        for(int m=0;m<radius; ++m)
				cout<<'o';
			cout<<endl;
        	}
	        for(int l=0; l<radius/2-radius/3; ++l)
			cout<<' ';
		for(int b=0; b<radius-radius/2; ++b)
			cout<< 'o';
                cout<<endl;
	}
	~Circle()
	{	
	}
};

#endif
