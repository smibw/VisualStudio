#include <iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

#define tab "\t"
void main()
{
	setlocale(LC_ALL, "");
	const int n = 20;
	int arr[n];
	int minrand, maxrand;
	do
	{
		std::cout << "¬ведите минимальное случайное число: "; std::cin >> minrand;
		std::cout << "¬ведите максимальное случайное число: "; std::cin >> maxrand;
		if (minrand > maxrand) std::cout << "Error: вы ввели некорретное значение, попробуйте еще раз." << endl;
	} while (minrand>=maxrand);
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (maxrand - minrand) + minrand;
		//if (arr[i] >= 100) arr[i] -= 50; //не самый оптимальный вариант
	}
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << tab;
	}
}