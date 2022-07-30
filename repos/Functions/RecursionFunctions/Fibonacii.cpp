#include "stdafx.h"
#include "Fibonacii.h"
int Fibonacii_limit(int number,int number2, int limit)
{
	if (number > limit)
	{
		return 0;
	}
	else if (number < limit)
	{
		std::cout << number << tab << number2 << tab;
		number += number2;
		return Fibonacii_limit(number, number2 + number, limit);
	}
}
int Fibonacii_amount(int number, int number2,int amount)
{
	if (amount==0)
	{
		return 0;
	}
		else if (amount>0)
	{
		std::cout << number << tab << number2 << tab;
		number += number2;
		return Fibonacii_amount(number,number2+number,amount-1);
	}
}