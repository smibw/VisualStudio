#include"Statistics.h"
template<typename T>T Sum(T arr[], const int n)
{
	T Sum = 0;
	for (int i = 0; i < n; i++)
	{
		Sum += arr[i];
	}
	return Sum;
}
template<typename T>T Sum(T arr[x][y], const int x, const int y)
{
	T Sum = 0;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			Sum += arr[i][j];
		}
	}
	return Sum;
}



template<typename T>T minValueIn(T arr[], const int n)
{
	T minValueIn = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (minValueIn > arr[i])	minValueIn = arr[i];
	}
	return minValueIn;
}
template<typename T>T minValueIn(T arr[x][y], const int x, const int y)
{
	T minValueIn = arr[0][0];
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			if (minValueIn > arr[i][j])	minValueIn = arr[i][j];
		}
	}
	return minValueIn;
}

template<typename T>T maxValueIn(T arr[], const int n)
{
	T maxValueIn = 0;
	for (int i = 0; i < n; i++)
	{
		if (maxValueIn < arr[i]) maxValueIn = arr[i];
	}
	return maxValueIn;
}
template<typename T>T maxValueIn(T arr[x][y], const int x, const int y)
{
	T maxValueIn = 0;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			if (maxValueIn < arr[i][j])	maxValueIn = arr[i][j];
		}
	}
	return maxValueIn;
}
