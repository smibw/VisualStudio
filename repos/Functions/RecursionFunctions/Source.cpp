#include "stdafx.h"
#include "Factorial.h"
#include "Power.h"
#include "Fibonacii.h"
int main()
{
	setlocale(LC_ALL, "");
	int number=0;
	int factorial = 1;
	bool chose;
	int second_chose;
	int degree;
	int limit;
	int amount;
	int number2 = 1;
	int power = 1;
	std::cout <<tab<<tab<<tab "Добро пожаловать в Программируемый Калькулятор." << std::endl;
	std::cout << tab << tab << tab "Вы готовы заняться математическими вычислениями?" << std::endl;
	std::cout << "Если готовы продолжить, нажмите 1." << tab << tab << tab << "Если не готовы, нажмите 2."<<std::endl;
	std::cin >> chose;
	if (!chose) return 0;
	std::cout << delimiter << delimiter;
	std::cout << "Нахождение факториала. Нажмите 1." << tab << tab;
	std::cout << "Нахождение степени. Нажмите 2." << std::endl;
	std::cout << "Нахождение ряда Фибоначчи до определенного значения. Нажмите 3." << std::endl;
	std::cout << "Нахождение ряда Фибоначчи до определенного количества значений. Нажмите 4." << std::endl;
	std::cin >> second_chose;
	std::cout << delimiter << delimiter;
	switch (second_chose)
	{
	case 1: std::cout << "Найти факториал числа: "; 
		std::cin >> number; 
		std::cout << "Факториал числа " << number << " = " << Factorial(number, factorial) << std::endl; break;
	case 2: std::cout << "Найти число ";
		std::cin >> number; 
		std::cout << " в степени "; 
		std::cin >> degree; 
		std::cout << "Число " << number <<" в степени " <<degree<< " = " << Power(number, degree,power) << std::endl; break;
	case 3: std::cout << "Введите предел: "; 
		std::cin >> limit; 
		Fibonacii_limit(number,number2, limit); break;
	case 4: std::cout << "Введите количество чисел: "; 
		std::cin >> amount;
		amount /= 2;
		Fibonacii_amount(number, number2, amount); break;
	}
}
