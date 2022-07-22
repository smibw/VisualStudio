#include"Constants.h"
#include"stdafx.h"
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << tab;
	}
	std::cout << endl;
}
void Print(float arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << tab;
	}
	std::cout << endl;
}
void Print(double arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << tab;
	}
	std::cout << endl;
}
void Print(char arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << tab;
	}
	std::cout << endl;
}
void Print(int arr[x][y], const int x, const int y)
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			std::cout << arr[i][j] << tab;
		}
		std::cout << std::endl;
	}
}
void Print(float arr[x][y], const int x, const int y)
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			std::cout << arr[i][j] << tab;
		}
		std::cout << std::endl;
	}
}
void Print(double arr[x][y], const int x, const int y)
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			std::cout << arr[i][j] << tab;
		}
		std::cout << std::endl;
	}
}
void Print(char arr[x][y], const int x, const int y)
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			std::cout << arr[i][j] << tab;
		}
		std::cout << std::endl;
	}
}
