#include "string.h"
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
	cout << a << " is " << a.size() << " characters long." << endl;
	cout << s << " is " << s.size() << " characters long." << endl;
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

void test_reverse()
{
	cout << "\nTESTING REVERSE()" << endl << endl;
	String r("Reverse");
	String v("esreveR");
	String vv("Boston");
	String rv, vr, vvv;
	rv = r.reverse();
	vr = v.reverse();
	vvv = vv.reverse();
	cout << r << " reversed is " << rv << endl;
	cout << v << " reversed is " << vr << endl;
	cout << vv << " reversed is " << vvv << endl;
}

void test_equality()
{
	cout << "\nTESTING == and !=" << endl << endl;
	String a("Albalone");
	String b("Barista");
	bool ab = a==b;
	bool aa = a==a;
	bool ba = b!=a;
	bool aaa = a!=a;
	cout << "a == b : " << ab << " should be false" << endl;
	cout << "a == a : " << aa << " should be true" << endl;	
	cout << "a != b : " << ba << " should be true" << endl;
	cout << "a != a : " << aaa << " should be false" << endl;
}

void test_gt_lt()
{
	cout << "\nTESTING <, >, <=, >= " << endl << endl;
	String a("abcde");
	String b("bcdef");
	bool ab = a > b;
	bool ba = b > a;
	bool bb = b < b;
	bool aa = a > a;
	bool ageb = a >= b;
	bool aleb = a <= b;
	bool alea = a <= a;
	bool agea = a >= a;
	cout << "a>b : " << ab << " should be false" << endl;
	cout << "b>a : " << ba << " should be true" << endl;
	cout << "a>a : " << aa << " should be false" << endl;
	cout << "b<b : " << bb << " should be false" << endl;
	cout << "a>=b : " << ageb << " should be false" << endl;
	cout << "a<=b : " << aleb << " should be true" << endl;
	cout << "a<=a : " << alea << " should be true" << endl;
	cout << "a>=a : " << agea << " should be true" << endl;	
}

void test_plus_eq()
{
	cout << "\nTESTING +, +=" << endl << endl;
	String a("abcdef");
	String b("ghijklm");
	String c;
	String d;
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
	int bb = a.indexOf("bcd");
	int ee = a.indexOf('e');
	cout << "The index of a is " << aa << ", should be 0" << endl;
	cout << "The index of bcd is " << bb << ", should be 1" << endl;
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
	test_reverse();
	test_equality();
	test_gt_lt();
	test_plus_eq();
	test_indexOf();
	test_read();
	cout << "\nTESTING MEMORY LEAKS" << endl << endl;
	String::final_report_on_allocations();
	cout << "\n==================================" << endl;
	cout << "TESTING HAS FINISHED..." << endl;
	cout << "==================================" << endl;
	return 0;
}


























