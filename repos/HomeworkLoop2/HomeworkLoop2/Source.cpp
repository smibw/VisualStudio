#include <iostream>
using namespace std;

//#define TASK_1
#define TASK_2
//#define TASK_3

void main()
{
	setlocale(LC_ALL, "Russian");

#ifdef TASK_1
	int factorial, number, safe;
	factorial = 1;
	cout << "Введите число, факториал которого требуется узнать:!"; cin >> number; cout << endl;
	safe = number;
	for (int i = 0; i < safe; i++)
	{
		factorial *= number;
		number--;
	}
	cout << factorial;
#endif // TASK_1

#ifdef TASK_2
	int stepenb, osnovanie;
	double number;
	number = 1;
	cout << "Введите число, которое требуется возвести в степень: "; cin >> osnovanie; cout << endl;
	cout << "Введите степень, в которую требуется возвести число: "; cin >> stepenb;
	if (stepenb>0)
	for (int i = 0; i < stepenb; i++)
	{
		number *= osnovanie;
	}
	else 
	{
		for (int i = 0; i > stepenb; i--)
		number /= osnovanie;
	}
	cout << number;
#endif // TASK_2

#ifdef TASK_3
	char simvol;
	int i, max_ascii;
	simvol = 0;
	for (i = 0; i < 256; i++)
	{
		if (i%16 == 0)
		{
			cout << simvol << endl;
			simvol++;
		}
		else
		{
			cout << simvol << " ";
			simvol++;
		}
		int i;
	}
#endif // TASK_3
}