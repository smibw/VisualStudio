#include <iostream>
#include <ctime>

using namespace std;
using std::cout;
using std::cin;
using std::endl;

#define tab "\t"
#define determination "\n-----------------------\n"

void main()
{
	setlocale(LC_ALL, "");
	int max = 0;
	const int x = 4;
	const int y = 6;
	int A[x][y]{};

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			A[i][j] = rand() % 10;
		}
	}

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			std::cout<<A[i][j]<<tab;
		}
		std::cout << endl;
	}
	std::cout << determination;
	 int min = A[0][0];
	 int buffer = A[0][0];
	 int buffer_1 = 0;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			if (A[i][j] < min) min = A[i][j];
			if (A[i][j] > max) max = A[i][j];
			buffer = A[0][0];
			buffer_1 = A[3][5];
			A[0][0] = min;
			A[3][5] = max;
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
	std::cout << min << tab << max;
}