#include"Constants.h"
#include"stdafx.h"
void ShiftLeft(int arr[], const int n)
{
	int shift;
	std::cout << "Введите значение смещения: "; std::cin >> shift;
	for (int i = 0; i < shift; i++)
	{
		int buffer = arr[0];
		for (int i = 0; i < n; i++)
		{
			arr[i] = arr[i + 1];
		}
		arr[n - 1] = buffer;
	}
}
void ShiftLeft(float arr[], const int n)
{
	int shift;
	std::cout << "Введите значение смещения: "; std::cin >> shift;
	for (int i = 0; i < shift; i++)
	{
		float buffer = arr[0];
		for (int i = 0; i < n; i++)
		{
			arr[i] = arr[i + 1];
		}
		arr[n - 1] = buffer;
	}
}
void ShiftLeft(double arr[], const int n)
{
	int shift;
	std::cout << "Введите значение смещения: "; std::cin >> shift;
	for (int i = 0; i < shift; i++)
	{
		double buffer = arr[0];
		for (int i = 0; i < n; i++)
		{
			arr[i] = arr[i + 1];
		}
		arr[n - 1] = buffer;
	}
}
void ShiftLeft(char arr[], const int n)
{
	int shift;
	std::cout << "Введите значение смещения: "; std::cin >> shift;
	for (int i = 0; i < shift; i++)
	{
		char buffer = arr[0];
		for (int i = 0; i < n; i++)
		{
			arr[i] = arr[i + 1];
		}
		arr[n - 1] = buffer;
	}
}
void ShiftLeft(int arr[x][y], const int x, const int y)
{
	int shift;
	std::cout << "Введите значение смещения: "; std::cin >> shift;
	for (int i = 0; i < shift; i++)
	{
		int buffer = arr[0][0];
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
void ShiftLeft(float arr[x][y], const int x, const int y)
{
	int shift;
	std::cout << "Введите значение смещения: "; std::cin >> shift;
	for (int i = 0; i < shift; i++)
	{
		float buffer = arr[0][0];
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
void ShiftLeft(double arr[x][y], const int x, const int y)
{
	int shift;
	std::cout << "Введите значение смещения: "; std::cin >> shift;
	for (int i = 0; i < shift; i++)
	{
		double buffer = arr[0][0];
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
void ShiftLeft(char arr[x][y], const int x, const int y)
{
	int shift;
	std::cout << "Введите значение смещения: "; std::cin >> shift;
	for (int i = 0; i < shift; i++)
	{
		char buffer = arr[0][0];
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
void ShiftRight(int arr[], const int n)
{
	int shift;
	std::cout << "Введите значение смещения: "; std::cin >> shift;
	for (int i = 0; i < shift; i++)
	{
		int buffer = arr[n - 1];
		for (int i = n - 1; i > 0; i--)
		{
			arr[i] = arr[i - 1];
		}
		arr[0] = buffer;
	}
}
void ShiftRight(float arr[], const int n)
{
	int shift;
	std::cout << "Введите значение смещения: "; std::cin >> shift;
	for (int i = 0; i < shift; i++)
	{
		float buffer = arr[n - 1];
		for (int i = n - 1; i > 0; i--)
		{
			arr[i] = arr[i - 1];
		}
		arr[0] = buffer;
	}
}
void ShiftRight(double arr[], const int n)
{
	int shift;
	std::cout << "Введите значение смещения: "; std::cin >> shift;
	for (int i = 0; i < shift; i++)
	{
		double buffer = arr[n - 1];
		for (int i = n - 1; i > 0; i--)
		{
			arr[i] = arr[i - 1];
		}
		arr[0] = buffer;
	}
}
void ShiftRight(char arr[], const int n)
{
	int shift;
	std::cout << "Введите значение смещения: "; std::cin >> shift;
	for (int i = 0; i < shift; i++)
	{
		char buffer = arr[n - 1];
		for (int i = n - 1; i > 0; i--)
		{
			arr[i] = arr[i - 1];
		}
		arr[0] = buffer;
	}
}
void ShiftRight(int arr[x][y], const int x, const int y)
{
	int shift;
	std::cout << "Введите значение смещения: "; std::cin >> shift;
	for (int i = 0; i < shift; i++)
	{
		int buffer = arr[x - 1][y - 1];
		int buffer_2 = arr[x - 2][y - 1];
		int buffer_3 = arr[x - 3][y - 1];

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
void ShiftRight(float arr[x][y], const int x, const int y)
{
	int shift;
	std::cout << "Введите значение смещения: "; std::cin >> shift;
	for (int i = 0; i < shift; i++)
	{
		float buffer = arr[x - 1][y - 1];
		float buffer_2 = arr[x - 2][y - 1];
		float buffer_3 = arr[x - 3][y - 1];

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
void ShiftRight(double arr[x][y], const int x, const int y)
{
	int shift;
	std::cout << "Введите значение смещения: "; std::cin >> shift;
	for (int i = 0; i < shift; i++)
	{
		double buffer = arr[x - 1][y - 1];
		double buffer_2 = arr[x - 2][y - 1];
		double buffer_3 = arr[x - 3][y - 1];

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
void ShiftRight(char arr[x][y], const int x, const int y)
{
	int shift;
	std::cout << "Введите значение смещения: "; std::cin >> shift;
	for (int i = 0; i < shift; i++)
	{
		char buffer = arr[x - 1][y - 1];
		char buffer_2 = arr[x - 2][y - 1];
		char buffer_3 = arr[x - 3][y - 1];

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