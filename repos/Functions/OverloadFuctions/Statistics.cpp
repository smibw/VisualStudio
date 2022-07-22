#include"Constants.h"
#include"stdafx.h"
int Sum(int arr[], const int n)
{
	int Sum = 0;
	for (int i = 0; i < n; i++)
	{
		Sum += arr[i];
	}
	return Sum;
}
float Sum(float arr[], const int n)
{
	float Sum = 0;
	for (int i = 0; i < n; i++)
	{
		Sum += arr[i];
	}
	return Sum;
}
double Sum(double arr[], const int n)
{
	double Sum = 0;
	for (int i = 0; i < n; i++)
	{
		Sum += arr[i];
	}
	return Sum;
}
char Sum(char arr[], const int n)
{
	char Sum = 0;
	for (int i = 0; i < n; i++)
	{
		Sum += arr[i];
	}
	return Sum;
}
int Sum(int arr[x][y], const int x, const int y)
{
	int Sum = 0;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			Sum += arr[i][j];
		}
	}
	return Sum;
}
float Sum(float arr[x][y], const int x, const int y)
{
	float Sum = 0;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			Sum += arr[i][j];
		}
	}
	return Sum;
}
double Sum(double arr[x][y], const int x, const int y)
{
	double Sum = 0;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			Sum += arr[i][j];
		}
	}
	return Sum;
}
char Sum(char arr[x][y], const int x, const int y)
{
	char Sum = 0;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			Sum += arr[i][j];
		}
	}
	return Sum;
}
int Avg(int arr[], const int n)
{
	return Sum(arr, n) / n;
}
float Avg(float arr[], const int n)
{
	return Sum(arr, n) / n;
}
double Avg(double arr[], const int n)
{
	return Sum(arr, n) / n;
}
char Avg(char arr[], const int n)
{
	return Sum(arr, n) / n;
}
int Avg(int arr[x][y], const int x, const int y)
{
	return Sum(arr, x, y) / (x * y);
}
float Avg(float arr[x][y], const int x, const int y)
{
	return Sum(arr, x, y) / (x * y);
}
double Avg(double arr[x][y], const int x, const int y)
{
	return Sum(arr, x, y) / (x * y);
}
char Avg(char arr[x][y], const int x, const int y)
{
	return Sum(arr, x, y) / (x * y);
}
int minValueIn(int arr[], const int n)
{
	int minValueIn = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (minValueIn > arr[i])	minValueIn = arr[i];
	}
	return minValueIn;
}
float minValueIn(float arr[], const int n)
{
	float minValueIn = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (minValueIn > arr[i])	minValueIn = arr[i];
	}
	return minValueIn;
}
double minValueIn(double arr[], const int n)
{
	double minValueIn = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (minValueIn > arr[i])	minValueIn = arr[i];
	}
	return minValueIn;
}
char minValueIn(char arr[], const int n)
{
	char minValueIn = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (minValueIn > arr[i])	minValueIn = arr[i];
	}
	return minValueIn;
}
int minValueIn(int arr[x][y], const int x, const int y)
{
	int minValueIn = arr[0][0];
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			if (minValueIn > arr[i][j])	minValueIn = arr[i][j];
		}
	}
	return minValueIn;
}
float minValueIn(float arr[x][y], const int x, const int y)
{
	float minValueIn = arr[0][0];
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			if (minValueIn > arr[i][j])	minValueIn = arr[i][j];
		}
	}
	return minValueIn;
}
double minValueIn(double arr[x][y], const int x, const int y)
{
	double minValueIn = arr[0][0];
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			if (minValueIn > arr[i][j])	minValueIn = arr[i][j];
		}
	}
	return minValueIn;
}
char minValueIn(char arr[x][y], const int x, const int y)
{
	char minValueIn = arr[0][0];
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			if (minValueIn > arr[i][j])	minValueIn = arr[i][j];
		}
	}
	return minValueIn;
}
int maxValueIn(int arr[], const int n)
{
	int maxValueIn = 0;
	for (int i = 0; i < n; i++)
	{
		if (maxValueIn < arr[i]) maxValueIn = arr[i];
	}
	return maxValueIn;
}
float maxValueIn(float arr[], const int n)
{
	float maxValueIn = 0;
	for (int i = 0; i < n; i++)
	{
		if (maxValueIn < arr[i]) maxValueIn = arr[i];
	}
	return maxValueIn;
}
double maxValueIn(double arr[], const int n)
{
	double maxValueIn = 0;
	for (int i = 0; i < n; i++)
	{
		if (maxValueIn < arr[i]) maxValueIn = arr[i];
	}
	return maxValueIn;
}
char maxValueIn(char arr[], const int n)
{
	char maxValueIn = 0;
	for (int i = 0; i < n; i++)
	{
		if (maxValueIn < arr[i]) maxValueIn = arr[i];
	}
	return maxValueIn;
}
int maxValueIn(int arr[x][y], const int x, const int y)
{
	int maxValueIn = 0;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			if (maxValueIn < arr[i][j])	maxValueIn = arr[i][j];
		}
	}
	return maxValueIn;
}
float maxValueIn(float arr[x][y], const int x, const int y)
{
	float maxValueIn = 0;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			if (maxValueIn < arr[i][j])	maxValueIn = arr[i][j];
		}
	}
	return maxValueIn;
}
double maxValueIn(double arr[x][y], const int x, const int y)
{
	double maxValueIn = 0;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			if (maxValueIn < arr[i][j])	maxValueIn = arr[i][j];
		}
	}
	return maxValueIn;
}
char maxValueIn(char arr[x][y], const int x, const int y)
{
	char maxValueIn = 0;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			if (maxValueIn < arr[i][j])	maxValueIn = arr[i][j];
		}
	}
	return maxValueIn;
}
