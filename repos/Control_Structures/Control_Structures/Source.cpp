#include <iostream>
using namespace std;

//#define TUSK_1
//#define TUSK_2
////#define VESION_OF_TUSK_3_PROSCHE
#define ONLY_SWITCH

void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef TUSK_1
	int t;
	cout << "Введите температуру на улице: "; cin >> t;
	if (t > 0)cout << "На улице тепло.";			
	else 	  cout << "На улице холодно.";			
#endif // Tusk1

#ifdef TUSK_2
	int i;
	cout << "Введите число: "; cin >> i;
	if (i > 0 && i <= 10)
	{		cout << "Вы попали в цель.";	}
	else
	{		cout << "Вы промахнулись.";	}
#endif // Tusk2

#ifdef TUSK_3
	int chislo_1;
	int otvet;
	int chislo_2;
	int zhelanie_1;
	int zhelanie_2;
	int zhelanie_3;
	int zhelanie_4;
	int zhelanie_5;
	cout << "Введите число: "; cin >> chislo_1;
	cout << "Введите число: "; cin >> chislo_2;
	cout << "Вы хотите сложить? Да(напишите 1). Нет(напишите 0)."; cin >> zhelanie_1; cout << endl;
	cout << "Вы хотите вычесть?  Да(напишите 1). Нет(напишите 0)."; cin >> zhelanie_2; cout << endl;
	cout << "Вы хотите умножить? Да(напишите 1). Нет(напишите 0)."; cin >> zhelanie_3; cout << endl;
	cout << "Вы хотите разделить? Да(напишите 1). Нет(напишите 0)."; cin >> zhelanie_4; cout << endl;
	cout << "Вы хотите посчитать остаток от деления? Да(напишите 1). Нет(напишите 0)."; cin >> zhelanie_5; 
	cout << endl;
	if (zhelanie_1 == 1)
	{
		otvet = chislo_1 + chislo_2;
		cout << otvet << endl;
	}
	else if (zhelanie_2 == 1)
	{
		otvet = chislo_1 - chislo_2;
		cout << otvet << endl;
	}
	else if (zhelanie_3 == 1)
	{
		otvet = chislo_1 * chislo_2;
		cout << otvet << endl;
	}
	else if (zhelanie_4 == 1)
	{
		otvet = chislo_1 / chislo_2;
		cout << otvet << endl;
	}
	else if (zhelanie_5 == 1)
	{
		cout << "Считаем остаток:";
		otvet = chislo_1 % chislo_2;
		cout << otvet << endl;
		cout << "Что вы еще ожидали от простейшего калькулятора?=)";
	}
	else {
		cout << "Error..." << endl;
		cout << "Что вы еще ожидали от простейшего калькулятора?=)";
	}
#endif // Tusk3 
#ifdef VESION_OF_TUSK_3_PROSCHE

	double a, b;
	char s;
	cout << "Введите арифметическое выражение: ";
	cin >> a >> s >> b;
	if (s == '+')
	{
		cout << a << "+" << b << "=" << a + b << endl;
	}
	else if (s == ' - ')
	{
		cout << a << "-" << b << "=" << a - b << endl;
	}
	else if (s == '*')
	{
		cout << a << "*" << b << "=" << a * b << endl;
	}
	else if (s == '/')
	{
		cout << a << "/" << b << "=" << a / b << endl;
	}
	else cout << "Error";
#endif
#ifdef ONLY_SWITCH
	int var = 0;
	int const user_1 = 0;
	int const user_2 = 1;
	int const user_N = 2;
	int g,h,j;
	g = h = j = 5;
	switch (var)
	{
	case user_1: g=5+10; break;
	case user_2: h=10-5; break;
	case user_N: j=10/2; break;
	default: "Error";
	}
	cout << g << h << j;
#endif
}
