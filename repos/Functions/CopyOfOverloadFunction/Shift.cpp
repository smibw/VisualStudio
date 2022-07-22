#include"Shift.h"
template<typename T>void ShiftLeft(T arr[], const int n)
{
	int shift;
	std::cout << "Введите значение смещения: "; std::cin >> shift;
	for (int i = 0; i < shift; i++)
	{
		T buffer = arr[0];
		for (int i = 0; i < n; i++)
		{
			arr[i] = arr[i + 1];
		}
		arr[n - 1] = buffer;
	}
}
template<typename T>void ShiftLeft(T arr[x][y], const int x, const int y)
{
	int shift;
	std::cout << "Введите значение смещения: "; std::cin >> shift;
	for (int i = 0; i < shift; i++)
	{
		T buffer = arr[0][0];
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				arr[i][j] = arr[i][j + 1];
			}
		}
		arr[x - 1][y - 1] = buffer;
	}
}

template<typename T>void ShiftRight(T arr[], const int n)
{
	int shift;
	std::cout << "Введите значение смещения: "; std::cin >> shift;
	for (int i = 0; i < shift; i++)
	{
		T buffer = arr[n - 1];
		for (int i = n - 1; i > 0; i--)
		{
			arr[i] = arr[i - 1];
		}
		arr[0] = buffer;
	}
}
template<typename T>void ShiftRight(T arr[x][y], const int x, const int y)
{
	int shift;
	std::cout << "Введите значение смещения: "; std::cin >> shift;
	for (int i = 0; i < shift; i++)
	{
		T buffer = arr[x - 1][y - 1];
		T buffer_2 = arr[x - 2][y - 1];
		T buffer_3 = arr[x - 3][y - 1];

		for (int i = x - 1; i >= 0; i--)
		{
			for (int j = y - 1; j > 0; j--)
			{
				arr[i][j] = arr[i][j - 1];
			}
		}
		arr[0][0] = buffer;
		arr[2][0] = buffer_2;
		arr[1][0] = buffer_3;
	}
}