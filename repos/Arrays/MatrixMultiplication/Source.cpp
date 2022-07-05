#include <iostream>

using namespace std;
using std::cout;
using std::cin;
using std::endl;
#define tab "\t"
#define delimiter "\n------------------\n"
//#define MATRIX_MULTIPLICATION
//#define MATRIX_DETERMINATION
//#define MATRIX_DETERMINATION_2

void main()
{
	setlocale(LC_ALL, "");
#ifdef MATRIX_MULTIPLICATION
	const int x=3;
	const int y=3;
	int A[x][y];
	int B[x][y];
	int C[x][y]{};
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			A[i][j] = rand() % 10;
			B[i][j] = rand() % 10;
		}
	}
	std::cout << delimiter;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			std::cout << A[i][j]<<tab;
		}
		std::cout << endl;
	}
	std::cout << delimiter;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			std::cout << B[i][j]<<tab;
		}
		std::cout << endl;
	}
	std::cout << delimiter;
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
#endif // MATRIX_MULTIPLICATION

#ifdef MATRIX_DETERMINATION
	int detA = 0;
	const int x = 3;
	const int y = 5;
	int A[x][y]
	{
		{1,2,3,1,2,},
		{10,5,6,10,5,},
		{7,8,9,7,8,},
	};

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			std::cout << A[i][j] << tab;
		}
		std::cout << endl;
	}
	int i = 0;
	for (int j = 0; j < y; j++)
	{
		if (j == 2)
		{
			detA -= A[i][j] * A[i + 1][j - 1] * A[i + 2][j - 2];
			detA += A[i][j] * A[i + 1][j + 1] * A[i + 2][j + 2];
		}
		else if (j < 2) detA += A[i][j] * A[i + 1][j + 1] * A[i + 2][j + 2];
		else detA -= A[i][j] * A[i + 1][j - 1] * A[i + 2][j - 2];
	}
	std::cout << detA;
#endif // MATRIX_DETERMINATION

#ifdef MATRIX_DETERMINATION_2
	const int n = 3;
	int A[n][n]
	{
		{1,2,3,},
		{4,5,6,},
		{7,8,9,},
	};
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cout << A[i][j] << tab;
		}
		std::cout << endl;
	}
	std::cout << delimiter;
	int B[n][n * 2];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			B[i][j] = B[i][j + n] = A[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n * 2; j++)
		{
			std::cout << B[i][j] << tab;
		}
		std::cout << endl;
	}
	std::cout << delimiter;
	int main_diag = 0;
	int aux_diag = 0;
	for (int i = 0; i < n; i++)
	{
		int main_product = 1;
		for (int j = 0; j < n; j++)
		{
			main_product *= B[j][j + i];
		}
		main_diag += main_product;

		int aux_product = 1;
		for (int j = 0; j < n; j++)
		{
			aux_product *= B[n - 1 - j][j + i];
		}
		aux_diag += aux_product;
	}
	std::cout << "Determinant = " << main_diag - aux_diag << endl;
#endif // MATRIX_DETERMINATION_2

}