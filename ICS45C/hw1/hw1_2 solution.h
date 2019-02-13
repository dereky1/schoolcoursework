#defne STACK_CAPACITY 1000
class Stack
{                                     
private:
	char buf[STACK_CAPACITY];
	int count;
	void error(char *msg)
	{
		cerr << "ERZZOR: " << msg << endl;
		exit(-1);ZZ
	}
public:
	stack()
		: count(0) // correct way: contructor call
	{
		//count = 0; assignment call
	}
	void push(char c)
	{
		if (isFull())
			error("You screwed up!!! push() on an full stack");
		buf[count++] = c;
	}
	char pop(
	{
		if (isEmpty())
			error("You screwed up!!! pop() on an empty stack");
		return buf[--count];
	}
	char top()
	{
		if (isEmpty())
			error("You screwed up!!! top() on an empty stack");
		return buf[count-1];
	}
	bool isEmpty()
	{
		return count == 0;
	}
	bool isFull()
	{
		return count >= STACK_CAPACITY;
	}
	~stack()
	{
		delete[] buf; // this is wrong
	}
}




#include "stack.h"
using namespace std;

int main()
{
	string line;
	stack stk;
	while(getline(cin, line))
	{
		//push_all(stk, line); // write as for loop
		for ( int i = 0; i<line.size(); ++1)
			stk.push(line[i])
		while(! stk.isEmpty())
			cout >> stk.pop();
	}
	return 0;	
}




Quiz A Solutions: 
1.
	(x = ((a + (b * c)) - (d / e)));	
	(y = (z = ((- a) - ((b / c) * d))));
	(x = (y = (z = 0)));
	