#include <iostream>
using namespace std;
double convert(int knot)
{
	double answer = knot * (6076.0/5280.0) / 60.0;
	return answer;
}

int main()
{
	int input;
	cin >> 	input;
	cout << convert(input) << endl;
	return 0;	
}
