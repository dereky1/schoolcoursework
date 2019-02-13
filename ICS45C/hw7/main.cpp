#include "Matrix.h"

template
	<typename T>
void fillMatrix(Matrix <T> & m)
{
	int i, j;
	for(i=0;i<m.numRows();i++)
		m[i][0] = T();
	for(j=0;j<m.numCols();j++)
		m[0][j] = T();
	for(i=1;i<m.numRows();i++)
		for(j=1;j<m.numCols();j++)
		{
			m[i][j] = T(i*j);
		}
}

void test_int_matrix()
{
	Matrix <int> m(10,5);
	fillMatrix(m);
	cout<<m;
	for(int i=5; i>-3; --i)
	{
		try
		{
			cout<<"Accessing Matrix Index of [5][" <<i<<"]: ";
			cout<<m[5][i]<<endl;
		}
		catch(Array<int>::IndexOutOfBoundsException)
		{
			cout<<"Array Index is out of bounds"<<endl;
		}
		catch(Matrix<int>::IndexOutOfBoundsException)
		{
			cout<<"Matrix Index Out of Bounds"<<endl;
		}
		catch(...)
		{
			cout<<"Unknown Error Caught"<<endl;
		}
	}
	cout<<endl;
}

void test_double_matrix()
{
	Matrix<double>M(8,10);
	fillMatrix(M);
	cout<<M;
	for(int j=10; j>-3; --j)
	{
		try
		{			
			cout<<"Accessing Matrix Index of [5][" <<j<<"]: ";
			cout<<M[5][j]<<endl;	
		}
		catch(Array<double>::IndexOutOfBoundsException)
		{
			cout<<"Array Index is out of bounds"<<endl;
		}
		catch(Matrix<double>::IndexOutOfBoundsException)
		{
			cout<<"Matrix Index Out of Bounds"<<endl;
		}
		catch(...)
		{
			cout<<"Unknown Error Caught"<<endl;
		}
	}
	cout<<endl;
}

int main()
{
	test_int_matrix();
	test_double_matrix();
	return 0;
}
