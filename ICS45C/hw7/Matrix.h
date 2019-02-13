#ifndef MATRIX_H
#define MATRIX_H
#include "Array.h"

template
	<typename Type>
class Matrix
{
private:
	int rows, cols;
	Array <Array<Type>*> m;
public:
	Matrix(int newRows, int newCols)
		:rows(newRows), cols(newCols), m(rows)
	{
		for(int i=0;i<rows;i++)
			m[i] = new Array <Type>(cols);
	}
	int numRows()
	{
		return rows;
	}
	int numCols()
	{
		return cols;
	}
	class IndexOutOfBoundsException
	{
	};
	Array <Type> & operator [] (int row)
		throw(IndexOutOfBoundsException)
	{
		if(row < 0 || row >= rows)
			throw IndexOutOfBoundsException();
		return * m[row];
	}
	void print(ostream & out)
	{
		for(int i=0; i<m.length(); i++)
			out << m[i];
		out<<endl;
	}
	friend ostream & operator << (ostream & out, Matrix & m)
	{
		m.print(out);
		return out;
	}
	~Matrix()
	{
		for(int i=0;i<rows;++i)
			delete  m[i];
	}	
};


#endif
