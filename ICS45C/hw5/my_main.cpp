#include "String.h"
#include <iostream>
using namespace std;
/////////////////////////////////////////////////////////////////////////
////////////////////TEST FUNCTIONS STARTS HERE///////////////////////////
/////////////////////////////////////////////////////////////////////////

void test_constructor_and_print()
{	
	cout << "\nTESTING CONSTRUCTOR AND PRINT()" << endl << endl;
	String s("hello");
	String w("world");
	cout << s << " is the string object" << endl;
	cout << w << " is the next string object" << endl;
	cout << "together: " << s << w << endl;
}	

void test_size()
{
	cout << "\nTESTING SIZE()" << endl << endl;
	String a("African");
	String s("Savannah");
	cout << a << " is " << a.length() << " characters long." << endl;
	cout << s << " is " << s.length() << " characters long." << endl;
}

void test_assignment()
{
	cout << "\nTESTING ASSIGNMENT" << endl << endl;
	String e("Empty");
	cout << "e is now " << e << endl;
	e = "Full";
	cout << "After assignment, e is now " << e << endl;
	e = "Half Full";
	cout << "After another assignment, e is now " << e << endl;
}	

void test_indexing()
{
	cout << "\nTESTING INDEXING" << endl << endl;
	String i("Iguanna");
	cout << "The second letter of Iguanna is " << i[1] << endl;
	cout << "The last letter of Iguanna is " << i[6] << endl;
}

void test_equality()
{
	cout << "\nTESTING ==" << endl << endl;
	String a("Albalone");
	String b("Barista");
	bool ab = a==b;
	bool aa = a==a;
	cout << "a == b : " << ab << " should be false" << endl;
	cout << "a == a : " << aa << " should be true" << endl;	
}

void test_gt_lt()
{
	cout << "\nTESTING <" << endl << endl;
	String a("abcde");
	String b("bcdef");
	bool bb = b < b;
	bool ab = a < b;
	cout << "b<b : " << bb << " should be false" << endl;
	cout << "a<b : " << ab << " should be true" << endl;
}

void test_plus_eq()
{
	cout << "\nTESTING +, +=" << endl << endl;
	String a("abcdef");
	String b("ghijklm");
	String c;
	String d;
	cout<<"made my strings" << endl;
	d = a + a;
	c = a + b;
	a += b;
	cout << "c=a+b: c=" << c << ", should be abcdefghijklm" << endl;
	cout << "a+=b: a=" << a << ", should be abcdefghijklm" << endl;
	cout << "d=a+a: d=" << d << ", should be adcdefabcdef" << endl; 
	d+= a;
	cout << "d+=a: d=" << d << ", should be abcdefabcdefabcdefghijklm" << endl;
}

void test_indexOf()
{
	cout << "\nTESTING indexOf()" << endl << endl;
	String a("abcde");
	int aa = a.indexOf('a');
	int ee = a.indexOf('e');
	cout << "The index of a is " << aa << ", should be 0" << endl;
	cout << "The index of e is " << ee << ", should be 4" << endl;

}

void test_read()
{
	cout << "\nTESTING read()" << endl << endl;
	cout << "Type in a string you would like to store into This" << endl;
	String This;
	cin >> This;
	cout << "This is inside This: " << This << endl;
}



/////////////////////////////////////////////////////////////////////////
////////////////////////MAIN STARTS HERE/////////////////////////////////
/////////////////////////////////////////////////////////////////////////

int main()
{
	cout << "=================================" << endl;
	cout << "COMMENCING THE TESTING PROCESS..." << endl;
	cout << "=================================" << endl;
	test_constructor_and_print();
	test_size();	
	test_assignment();
	test_indexing();
	test_equality();
	test_gt_lt();
	test_plus_eq();
	test_indexOf();
	test_read();
	cout << "\n==================================" << endl;
	cout << "TESTING HAS FINISHED..." << endl;
	cout << "==================================" << endl;
	return 0;
}


























