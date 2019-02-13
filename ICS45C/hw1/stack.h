#define STACK_CAPACITY 1000
#include <iostream>
using namespace std;
class Stack
{
private:
	char stacked[STACK_CAPACITY];
	int count;
	void error(char *msg)
	{
		cerr << "ERROR: " << msg << endl;
	}	
public:
	Stack()
	{
		count = 0;	 
	}
	void push(char c)
	{	
		char msg[] = "push() on full stack";
		if(isFull())
			error(msg);
		stacked[count++] = c;	
	}
	char pop()
	{	
		char msg[] = "pop() on empty stack";
		if(isEmpty())
			error(msg);
		return stacked[--count];
	}
	char top()
	{
		char msg[] = "top() on empty stack";
		if(isEmpty())
			error(msg);
		return stacked[count--];	
	}
	bool isEmpty()
	{
		return count == 0;
	}
	bool isFull()
	{
		return count  >= STACK_CAPACITY;
	}
	~Stack()
	{
	}

};
