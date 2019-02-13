#include "string.h"

int main()
{
	String firstString("First");
	String secondString("Second");
	String thirdString(firstString);
	String fourthString("Fourth");
	String fifthString = String();

	cout << "+: " << firstString + secondString << endl; 		
	cout << "+=: " << (firstString += secondString) << endl;
	cout << "indexOf(String): " << firstString.indexOf(secondString) << endl;
	cout << "indexOf(char): " << firstString.indexOf('t') << endl;		
	cout << "LT: " << (secondString < firstString) << endl;		
	cout << "GT: " << (secondString > firstString) << endl;		 
	cout << "LE: "<< (secondString <= firstString) << endl;		 
	cout <<"GE: "<< (secondString >= firstString) << endl;		
	cout << "<<: "<< fifthString << endl;						
	cout << "<<: "<< fourthString << endl;						
	cout << "==: " << (fifthString == fourthString) << endl;		
	cout << "indexOf(String): "<< fourthString.indexOf(fifthString) << endl;
	cout << "size(): "<< fifthString.size() << endl;					
	cout << "size(): "<< fourthString.size() << endl;				
	cout << "[]: "<< thirdString[1] << endl;						
	cout << "reverse(): "<< fourthString.reverse() << endl;				
	fifthString = thirdString;						
	cout << "<<: " << fifthString << " " << thirdString << endl;	
	cout << "[]: "<< fifthString[1] << endl;						
	cout << "[]: "<< fifthString[10] << endl;					
	cout <<"!=: " << (fifthString != thirdString) << endl;		

	cout << "Enter a test string: ";
	cin >> firstString;
	cout << firstString << endl;

	cout << (firstString < secondString) << endl;
	cout << (firstString <= thirdString) << endl;
	cout << (firstString > fourthString) << endl;
	cout << (firstString >= fifthString) << endl;

	return 0;
}

