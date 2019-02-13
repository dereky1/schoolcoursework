#include "stack.h"
#include <iostream>
using namespace std;

int main()
{
	string line;
	Stack stk;
	while(getline(cin,line))
	{
		for(int x=0; x<line.size(); ++x)
			stk.push(line[x]);
		while( ! stk.isEmpty())
			cout << stk.pop();
	} 
	cout << endl;
	return 0;
}
