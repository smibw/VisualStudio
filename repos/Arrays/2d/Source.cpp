#include <iostream>

using namespace std;
using std::cout;
using std::cin;
using std::endl;

#define tab "\t"
#define delimiter "\n------------------\n"
//#define BASICS
//#define MATRIX_ADD

void main()
{
	setlocale(LC_ALL, "");
#ifdef BASICS
	const int x = 8;//сроки
	const int y = 5;//элементы строки(столбцы)
	int arr[x][y] =
	{
		{1,2,3},
		{4,5,6},
		{7,8,9},
	};
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			std::cout << arr[i][j] << tab;
		}
		std::cout << endl;
	}
#endif // BASICS

	const int x = 3;
	const int y = 3;
	int A[x][y];
	int B[x][y];
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			A[i][j] = rand() % 10;
			B[i][j] = rand() % 10;
		}
	}
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			std::cout << A[i][j] << tab;
		}
		std::cout << endl;
	}
	std::cout << delimiter;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			std::cout << B[i][j] << tab;
		}
		std::cout << endl;
	}
	std::cout << delimiter;
	int C[x][y] = {};
	
	/*C[0][0] = A[0][0] * B[0][0] + A[0][1] * B[1][0] + A[0][2] * B[2][0];
	C[0][1] = A[0][0] * B[0][1] + A[0][1] * B[1][1] + A[0][2] * B[2][1];
	C[0][2] = A[0][0] * B[0][2] + A[0][1] * B[1][2] + A[0][2] * B[2][2];
	C[1][0] = A[1][0] * B[0][0] + A[1][1] * B[1][0] + A[1][2] * B[2][0];
	C[1][1] = A[1][0] * B[0][1] + A[1][1] * B[1][1] + A[1][2] * B[2][1];
	C[1][2] = A[1][0] * B[0][2] + A[1][1] * B[1][2] + A[1][2] * B[2][2];
	C[2][0] = A[2][0] * B[0][0] + A[2][1] * B[1][0] + A[2][2] * B[2][0];
	C[2][1] = A[2][0] * B[0][1] + A[2][1] * B[1][1] + A[2][2] * B[2][1];
	C[2][2] = A[2][0] * B[0][0] + A[2][1] * B[1][2] + A[2][2] * B[2][2];*/
	/*
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			C[i][j] = A[i][0] * B[0][j] + A[i][1] * B[1][j] + A[i][2] * B[2][j];
		}
	}*/
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			for (int k = 0; k < y; k++) 
			{
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			std::cout << C[i][j] << tab;
		}
		std::cout << endl;
	}
#ifdef MATTRIX_ADD
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			C[i][j] = A[i][j] + B[i][j];
		}
	}
	std::cout << delimiter;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			std::cout << C[i][j] << tab;
		}
		std::cout << endl;
	}
#endif // MATTRIX_ADD

}