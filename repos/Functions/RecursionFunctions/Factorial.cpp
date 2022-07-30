#include "stdafx.h"
#include "Factorial.h"
int Factorial(int number,int factorial)
{
	if (number == 0)
	{
		return factorial;
	}
	else if (number > 0)
	{
		factorial *= number;
		Factorial(number - 1, factorial);
	}
}