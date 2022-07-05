#include <iostream>
using namespace std;

void main()
{
setlocale (LC_ALL, "Russian");
	double znachenie_a;
	double znachenie_b;
	double znachenie_c;
	cout << "Программа по перемене значений местами.\n";
	cout << "Введите значение а: "; cin >> znachenie_a;
	cout << "Введите значение b: "; cin >> znachenie_b;
	znachenie_c = znachenie_a;
	znachenie_a = znachenie_b;
	znachenie_b = znachenie_c;
	cout << "Значение а: " << znachenie_a << endl;
	cout << "Значение b: " << znachenie_b << endl;

}


