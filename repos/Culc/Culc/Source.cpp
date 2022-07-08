#include<iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	double operand_a;
	double operand_b;
	char operatorr;
	cout << "Введите арифметическое выражение: ";
	cin >> operand_a >> operatorr >> operand_b;
	switch (operatorr)
	{
	case'+':cout << operand_a << operatorr << operand_b << "=" << operand_a + operand_b << endl; break;
	case'-': cout << operand_a << operatorr << operand_b << "=" << operand_a - operand_b << endl; break;
	case'*':cout << operand_a << operatorr << operand_b << "=" << operand_a * operand_b << endl; break;
	case'/':cout << operand_a << operatorr << operand_b << "=" << operand_a / operand_b << endl; break;
	default:cout << "Error";
	}
	operand_a >= 5 ? cout<<operand_b * operand_a : cout<<operand_b / operand_a;

}