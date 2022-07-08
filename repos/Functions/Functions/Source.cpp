#pragma warning (disable:4326)
#include <iostream>

using namespace std;
using std::cout;
using std::cin;
using std::endl;
#define tab "\t"
#define delimiter "\n---------------------\n"
int Add(int a, int b);
int Sub(int a, int b);
int Mul(int a, int b);
double Div(int a, int b);

void main()
{
	setlocale(LC_ALL, "");
	/*type name(parameters) //Объявление функции.
	{
		...;
		group of statements;
		...;
	}*/
	int a, b;
	std::cout << "Введите 2 числа: "; std::cin >> a >> b;
	int c = Add(a, b);
	std::cout << a << " + " << b << " = " << c << std::endl;
	std::cout << a << " - " << b << " = " << Sub(a, b) << std::endl;
	std::cout << a << " * " << b << " = " << Mul(a, b) << std::endl;
	std::cout << a << " / " << b << " = " << Div(a, b) << std::endl;
}

int Add(int a, int b)
{
	int c = a+b;
	return c;
}

int Sub(int a, int b)
{
		return a - b;
}
int Mul(int a, int b)
{
	return a * b;
}
double Div(int a, int b)
{
	return (double)a / b;
}


