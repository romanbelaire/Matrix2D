#include <iostream>
#include "Matrix2D.h"
#include <string>


void test1()
{
	//test 1: asymmetrical float array with ascending values
	Matrix2D<float> floatTest = Matrix2D<float>(3, 5);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			floatTest[i][j] = float(i + j);//assignment operator and indexing operator test (get/set)
		}
	}
	Matrix2D<float> t2 = floatTest;
	std::cout << "Test Matrix 1:" << std::endl;
	floatTest.print();
	std::cout << "Add Matrix*2 to Matrix:" << std::endl;
	floatTest += floatTest * 2;//addition and scalar multiplication test
	floatTest.print();//print results
	std::cout << "Transpose Matrix:" << std::endl;
	floatTest.transpose();//transpose test
	floatTest.print();
	std::cout << "Multiply transpose by original matrix value:" << std::endl;
	floatTest *= t2;//matrix, matrix multiplication test on transpose, will have resulting 5x5 matrix
	floatTest.print();
}

void test2()
{
	//test 2: symmetrical integer array with zeros
	Matrix2D<int> intTest = Matrix2D<int>(3, 3);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			intTest[i][j] = 0;//assignment operator and indexing operator test (get/set)
		}
	}

	std::cout << "Test Matrix 2:" << std::endl;
	intTest.print();
	std::cout << "Add Matrix*1 to Matrix:" << std::endl;
	intTest += intTest * 1;//addition and scalar multiplication test
	intTest.print();//print results
	std::cout << "Transpose Matrix:" << std::endl;
	intTest.transpose();//transpose test
	intTest.print();
	std::cout << "Multiply transpose by original matrix value:" << std::endl;
	intTest *= intTest;//matrix, matrix multiplication test on transpose
	intTest.print();//resultant matrix will be the same, because all zeros
}

void test3()
{
	//test 3: string matrix with string-friendly operations (testing template ability)
	Matrix2D<std::string> strTest = Matrix2D<std::string>(2, 2);
	strTest[0][0] = "a";
	strTest[0][1] = "b";
	strTest[1][0] = "c";
	strTest[1][1] = "d";

	std::cout << "Test Matrix 3:" << std::endl;
	strTest.print();
	std::cout << "Add Matrix to Matrix:" << std::endl;
	strTest += strTest;//addition test
	strTest.print();//print results
	std::cout << "Transpose Matrix:" << std::endl;
	strTest.transpose();//transpose test
	strTest.print();
}

int main()
{
	std::cout << std::endl << "TEST 1" << std::endl;
	test1();
	std::cout << std::endl << "TEST 2" << std::endl;
	test2();
	std::cout << std::endl << "TEST 3" << std::endl;
	test3();
	system("pause");
}



