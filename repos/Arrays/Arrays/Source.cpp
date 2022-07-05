#include <iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

#define tab "\t"
#define VVOD_MASSIVA
//#define PRYAMOI_VIVOD
//#define OBRATNII_VIVOD
//#define SUMMA_MASSIVA
#define MIN_MAX_ZNACHENIE_MASSIVA



void main()
{
	setlocale(LC_ALL, "");
	const int n=5;
	int arr[n];
	int summ= 0;
	
#ifdef VVOD_MASSIVA
	std::cout << "Введите значение массива: ";
	for (int i = 0; i < n; i++)
	{
		std::cin >> arr[i];
	}
#endif // VVOD_MASSIVA

#ifdef PRYAMOI_VIVOD
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << tab;
	}
	std::cout << endl;
#endif // PRYAMOI_VIVOD

#ifdef OBRATNII_VIVOD
	for (int i = n - 1; i >= 0; i--)
	{
		std::cout << arr[i] << tab;
	}
#endif // OBRATNII_VIVOD

#ifdef SUMMA_MASSIVA
	for (int i = 0; i < n; i++)
	{
		summ += arr[i];
	}
	std::cout<<"Сумма элементов массива: " << summ<<tab;
	std::cout << "Среднее арифметическое элементов массива: " << (double)summ / n<<tab;
#endif // SUMMA_MASSIVA

#ifdef MIN_MAX_ZNACHENIE_MASSIVA
	int max, min;
	max = min = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < min) min = arr[i];
		else if (arr[i] > max) max = arr[i];
	}
	std::cout << "Минимальное значение в массиве: " << min << endl;
	std::cout << "Максимальное значение в массиве: " << max << endl;
#endif // MIN_MAX_ZNACHENIE_MASSIVA
}
