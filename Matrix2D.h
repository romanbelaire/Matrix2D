#pragma once
#include <iostream>
#include <string.h>

//Header file for 2D Matrix class
//Author: ROMAN BELAIRE
//Written for OPTO-KNOWLEDGE SYSTEMS INC.

template <typename T> class Matrix2D;

template <typename T>
class Matrix2D
{
public:
	Matrix2D(int, int);
	Matrix2D(const Matrix2D<T>& obj);
	~Matrix2D();
	T* operator[](int idx)
	{
		//indexing operator overload for assignment/retrieval of values
		//Takes: integer idx, the index which we will access
		//Returns: row @idx from values
		if (idx >= numRows)
		{
			std::cout << "Array index out of bounds: " << idx;
			exit(0);
		}
		return values[idx];
	}

	void print()
	{
		//This function prints a formatted string containing the matrix.
		for (int i = 0; i < numRows; i++)
		{
			for (int j = 0; j < numCols; j++)
			{
				std::cout << values[i][j];
				std::cout << '\t';
			}
			std::cout << '\n';
		}
		std::cout << "\n ============= \n";
	}

	Matrix2D& operator+=(Matrix2D &rhs)
	{
		//addition operator overload function
		//Takes:  Matrix2D rhs (right hand side), performs matrix addition (adds rhs to lhs)
		//Returns: Matrix2D containing new summed values

		return *this + rhs;
	}

	Matrix2D& operator+(Matrix2D &rhs)
	{
		//addition operator overload function
		//Takes: Matrix2D lhs and Matrix2D rhs (left hand side and right hand side), performs matrix addition (adds rhs to lhs)
		//Returns: Matrix2D containing new summed values
		if (rows() != rhs.rows() || cols() != rhs.cols())
		{
			std::cout << "Matrices do not have matching shape.";
			exit(0);
		}

		for (int i = 0; i < rows(); i++)
		{
			for (int j = 0; j < cols(); j++)
			{
				values[i][j] += rhs[i][j];
			}
		}

		return *this;
	}

	Matrix2D& operator-=(Matrix2D &rhs)
	{
		//subtraction operator overload function
		//Takes: Matrix2D rhs (right hand side), performs matrix subtraction (subs rhs from lhs)
		//Returns: Matrix2D containing new values

		return this - rhs;
	}

	Matrix2D& operator-(Matrix2D &rhs)
	{
		//subtraction operator overload function
		//Takes: Matrix2D rhs (right hand side), performs matrix subtraction (subs rhs from lhs)
		//Returns: Matrix2D containing new values
		if (rows() != rhs.rows() || cols() != rhs.cols())
		{
			std::cout << "Matrices do not have matching shape.";
			exit(0);
		}

		return this + (rhs * -1);
	}

	Matrix2D& operator*(Matrix2D &rhs)
	{
		//multiplication operator overload for matrix,matrix multiplication
		//Matrix2D product = Matrix2D(lhs.rows(), rhs.cols());
		*this *= rhs;
		return *this;
	}

	Matrix2D& operator*=(Matrix2D &rhs)
	{
		//multiplication operator overload for matrix multiplication
		//Takes: Matris2D rhs, the other multiplicand for the operation
		//Returns: this matrix with value as new product
		if (numCols != rhs.rows())
		{
			std::cout << "Shape mismatch: matrices are not m,n and n,p";
			exit(0);
		}

		//make a temporary structure to copy product into
		T **product = new T*[numRows];
		for (int i = 0; i < numRows; i++)
		{
			product[i] = new T[rhs.cols()];
		}

		for (int i = 0; i < numRows; i++)
		{
			for (int j = 0; j < rhs.cols(); j++)
			{
				T sum = NULL;
				for (int n = 0; n < numCols; n++)
				{
					if (n == 0)
					{
						sum = values[i][n] * rhs[n][j];//equation for matrix multiplication
					}
					else
					{
						sum += values[i][n] * rhs[n][j];
					}
				}
				product[i][j] = sum;
			}
		}

		//clear values, allocate new memory, copy product into values
		deleteValues();
		makeValues(numRows, rhs.cols());
		for (int i = 0; i < numRows; i++)
		{
			for (int j = 0; j < rhs.cols(); j++)
			{
				values[i][j] = product[i][j];
			}
		}

		//delete our temporary product holder
		for (int i = 0; i < numRows; i++)
		{
			delete[] product[i];
		}
		delete[] product;

		return *this;
	}

	Matrix2D& operator*(T scalar)
	{
		//multiplication overload from matrix,scalar multiplication
		//Takes: Scalar value, performs scalar multiplication
		//Returns: Matrix2D containing scaled values
		for (int i = 0; i < rows(); i++)
		{
			for (int j = 0; j < cols(); j++)
			{
				values[i][j] *= scalar;
			}
		}
		return *this;
	}

	Matrix2D& transpose();
	int rows();
	int cols();

private:
	T **values;
	int numRows, numCols;
	void deleteValues();
	void makeValues(int, int);
	void copyVals(Matrix2D<T>& target);
};


template <typename T>
Matrix2D<T>::Matrix2D(int m, int n)//constructor
{
	//initialize matrix with m rows and n columns
	makeValues(m, n);
}

template <typename T>
Matrix2D<T>::Matrix2D(const Matrix2D<T> &obj)
{
	//copy constructor
	makeValues(const_cast<Matrix2D<T>&>(obj).rows(), const_cast<Matrix2D<T>&>(obj).cols());
	copyVals(const_cast<Matrix2D<T>&>(obj));
}

template <typename T>
void Matrix2D<T>::copyVals(Matrix2D<T> &target)
{
	//copy values from target into this.values
	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; j < numCols; j++)
		{
			values[i][j] = target[i][j];
		}
	}
}

template <typename T>
void Matrix2D<T>::makeValues(int m, int n)
{
	//this function allocates memory for our matrix values
	//Takes: parameters m (num rows) and n (num cols)
	values = new T*[m];
	for (int i = 0; i < m; i++)
	{
		values[i] = new T[n];
	}

	//store size information for faster access
	numRows = m;
	numCols = n;
}

template <typename T>
Matrix2D<T>& Matrix2D<T>::transpose()
{
	//method for matrix transpose
	//Takes: no argument
	//returns: Matrix2D containing transposition of matrix. This function alters the values of the object that calls it, as well as returns the matrix.
	Matrix2D<T> transposeMatrix = Matrix2D(numCols, numRows);

	for (int i = 0; i < numCols; i++)
	{
		for (int j = 0; j < numRows; j++)
		{
			transposeMatrix[i][j] = values[j][i];
		}
	}

	//clear values, allocate new memory, copy transpose into values
	deleteValues();
	makeValues(numCols, numRows);
	copyVals(transposeMatrix);

	return *this;
}

template <typename T>
int Matrix2D<T>::rows()
{
	//method to return number of rows
	return numRows;
}

template <typename T>
int Matrix2D<T>::cols()
{
	//method to return number of columns
	return numCols;
}

template <typename T>
void Matrix2D<T>::deleteValues()
{
	//this function clears memory where values are stored
	for (int i = 0; i < numRows; i++)
	{
		delete[] values[i];
	}
	delete[] values;
}

template <typename T>
Matrix2D<T>::~Matrix2D()//deconstructor
{
	deleteValues();
}