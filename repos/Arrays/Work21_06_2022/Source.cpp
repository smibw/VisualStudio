#include <iostream>
#include <ctime>

using namespace std;
using std::cout;
using std::cin;
using std::endl;

#define tab "\t"
//#define SORT
//#define SORT_1
//#define SORT_2


void main()
{
	setlocale(LC_ALL, "");
#ifdef SORT
	const int n = 10;
	int arr[n];
	int buffer = 0;

	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << tab;
	}
	std::cout << endl;
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << tab;
	}
	std::cout << endl;
#ifdef SORT_1
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] < arr[j])
			{
				buffer = arr[j];
				arr[j] = arr[i];
				arr[i] = buffer;
			}
			k++;
		}
	}
#endif // SORT_1
#ifdef SORT_2
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[i])
			{
				buffer = arr[i];
				arr[i] = arr[j];
				arr[j] = buffer;
			}
			k++;
		}
}
#endif // SORT_2


	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << tab;
	}
	std::cout << endl;
	std::cout << k;
#endif // SORT

	const int n = 10;
	int arr[n];
	int maxrand = 0;
	int minrand = 0;
	srand(time(NULL));
	do
	{
		std::cout << "Введите минимальное случайное число: "; std::cin >> minrand;
		std::cout << "Введите максимальное случайное число: "; std::cin >> maxrand;
		if (minrand >= maxrand) std::cout << "Error: вы ввели некорретное значение, попробуйте еще раз." << endl;
	} while (minrand >= maxrand);
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (maxrand - minrand) + minrand;
	}

	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i]<<tab;
	}
	std::cout << endl;

	for (int i = 0; i < n; i++)
	{
		int k = 0;
		for (int j = 0; j <n; j++)
		{
			if (arr[j] == arr[i])
			{
				k++;
			}
		}
		if (k == 1) continue;
		std::cout <<"Количество повторений числа "<<arr[i]<<"="<< k<< endl;
	}
}