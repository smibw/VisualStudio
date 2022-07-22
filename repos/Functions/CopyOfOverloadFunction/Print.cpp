#include"Print.h"
template<typename T>void Print(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << tab;
	}
	std::cout << endl;
}
template<typename T>void Print(T arr[x][y], const int x, const int y)
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			std::cout << arr[i][j] << tab;
		}
		std::cout << std::endl;
	}
}