#include "Shape.h"
#include "Circle.h"
#include "Square.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Picture.h"


int main()
{
	Picture picture;
	picture.add(new Triangle(0,0,5,5));
	picture.add(new Triangle(1,1,4,3));
	picture.add(new Circle(2,2,5));
	picture.add(new Circle(3,3,10));
	picture.add(new Square(4,4,5));
	picture.add(new Square(5,5,10));
	picture.add(new Rectangle(6,6,4,8));
	picture.add(new Rectangle(7,7,8,4));
	picture.drawAll();
	cout<< "Total Area: " << picture.totalArea() << endl;
	return 0;
}
