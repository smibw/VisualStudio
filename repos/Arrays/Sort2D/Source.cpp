#include <iostream>
#include <ctime>
using namespace std;
using std::cout;
using std::cin;
using std::endl;
#define tab "\t"
#define delimiter "---------------------------------------\n"

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
			A[i][j] = rand() % 100;
		}
	}
	std::cout << delimiter;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			std::cout << A[i][j] << tab;
		}
		std::cout << endl;
	}
	std::cout << delimiter;
	int buffer = 0;
	for (int l = 0; l < y; l++)
	{

	for (int k = 0; k < x; k++)
	{
		for (int i = 0; i < x-1; i++)
		{
			for (int j = 0; j < y-1; j++)
			{
				if (A[k][j] > A[k][j+1])
				{
					buffer = A[k][j];
					A[k][j] = A[k][j+1];
					A[k][j+1] = buffer;
				}
			}
			for (int j = 0; j < y - 1; j++)
			{
				if (A[i][j] > A[i + 1][j])
				{
					buffer = A[i][j];
					A[i][j] = A[i+1][j];
					A[i+1][j] = buffer;
				}
			}
		}
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
}