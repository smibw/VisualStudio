#include "stdafx.h"
#include "Power.h"
int Power(int number, int degree,int power)
{
	if (degree == 0)
	{
		return power;
	}
	else if (degree > 0)
	{
		return Power(number, degree - 1,power*number);
	}
}