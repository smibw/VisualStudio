#include <iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;
#define tab "\t"
#define delimiter "----------------------------------\n"
void FillArray(int arr[], const int n);
void PrintArray(int arr[], const int n);
int SumArray(int arr[], const int n);
double AvgArray(int arr[], const int n);
int MinValueIn(int arr[], const int n);
int MaxValueIn(int arr[], const int n);
void ShiftLeft(int arr[], const int n);
void ShiftRight(int arr[], const int n);
void main()
{
	setlocale(LC_ALL, "");
	const int n = 5;
	int arr[n];
	FillArray(arr, n);
	PrintArray(arr, n);
	std::cout<<delimiter;
	std::cout<<"Сумма всех элементов массива = "<<SumArray(arr, n)<<std::endl;
	std::cout<<delimiter;
	std::cout << "Среднее-арифметическое элементов массива = " << AvgArray(arr, n) << std::endl;
	std::cout<<delimiter;
	std::cout << "Минимальное значение элемента в массиве = " << MinValueIn(arr, n) << std::endl;
	std::cout<<delimiter;
	std::cout << "Максимальное значение элемента в массиве = " << MaxValueIn(arr, n) << std::endl;
	std::cout << delimiter;
	ShiftLeft(arr, n);
	PrintArray(arr, n);
	std::cout<<delimiter;
	ShiftRight(arr, n);
	PrintArray(arr, n);
	std::cout << delimiter;
}
void FillArray(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}
void PrintArray(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << tab;
	}
	std::cout<<std::endl;
}
int SumArray(int arr[], const int n)
{
	int summ = 0;
	for (int i = 0; i < n; i++)
	{
		summ += arr[i];
	}
	return summ;
}
double AvgArray(int arr[], const int n)
{
	double avg = 0;
	avg = (double)SumArray(arr, n) / n;
	return avg;
}
int MinValueIn(int arr[], const int n)
{
	int minNumber = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (minNumber > arr[i]) minNumber = arr[i];
	}
	return minNumber;
}
int MaxValueIn(int arr[], const int n)
{
	int maxNumber = 0;
	for (int i = 0; i < n; i++)
	{
		if (maxNumber < arr[i]) maxNumber = arr[i];
	}
	return maxNumber;
}
void ShiftLeft(int arr[], const int n)
{
	int shift;
	std::cout << "Введите значение сдвига: "; std::cin >> shift;
	for (int i = 0; i < shift; i++)
	{
		int buffer = arr[0];
		for (int i = 0; i < n; i++)
		{
			arr[i] = arr[i + 1];
		}
		arr[n-1] = buffer;
	}
}
void ShiftRight(int arr[], const int n)
{
	int shift;
	std::cout << "Введите значение сдвига: ";std::cin>>shift;
	for (int i = 0; i < shift; i++)
	{
		int buffer = arr[n - 1];
		for (int j = n-1; j > 0; j--)
		{
			arr[j] = arr[j - 1];
		}
		arr[0] = buffer;
	}
}