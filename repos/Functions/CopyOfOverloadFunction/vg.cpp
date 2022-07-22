#include"vg.h"
#include"Statistics.h"
#include"Statistics.cpp"
double Avg(int arr[], const int n)
{
	return (double)Sum(arr, n) / n;
}
double Avg(float arr[], const int n)
{
	return (double)Sum(arr, n) / n;
}
double Avg(double arr[], const int n)
{
	return (double)Sum(arr, n) / n;
}
double Avg(char arr[], const int n)
{
	return (double)Sum(arr, n) / n;
}
double Avg(int arr[x][y], const int x, const int y)
{
	return (double)Sum(arr, x, y) / (x * y);
}
double Avg(float arr[x][y], const int x, const int y)
{
	return (double)Sum(arr, x, y) / (x * y);
}
double Avg(double arr[x][y], const int x, const int y)
{
	return (double)Sum(arr, x, y) / (x * y);
}
double Avg(char arr[x][y], const int x, const int y)
{
	return (double)Sum(arr, x, y) / (x * y);
}