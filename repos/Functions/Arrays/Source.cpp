#include <iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;
#define tab "\t";
#define delimiter "-----------------------------------------------------------\n"
void PrintArray(int arr[], const int n);
void FillRand(int arr[], const int n);
void SortArray(int arr[], const int n);

void main()
{
	setlocale(LC_ALL, "");
	const int n = 5;
	int arr[n];
	FillRand(arr, n);
	PrintArray(arr, n);
	SortArray(arr, n);
	PrintArray(arr, n);
	std::cout << delimiter;
	const int SIZE = 8;
	int brr[SIZE];
	FillRand(brr, SIZE);
	PrintArray(brr, SIZE);
	SortArray(brr, SIZE);
	PrintArray(brr, SIZE);
}
void PrintArray(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << tab;
	}
	std::cout << endl;
}
void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}
void SortArray(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{

			if (arr[j] > arr[i])
			{
				int buffer = arr[i];
				arr[i] = arr[j];
				arr[j] = buffer;
			}
		}
	}
}