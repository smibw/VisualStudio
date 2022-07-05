#include <iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

//#define SQUARE
//#define TRIANGLE_A
//#define TRIANGLE_B
//#define TRIANGLE_C
//#define TRIANGLE_D
//#define ROMB
//#define KRADENII_KOD_ROMBA
//#define CHEREDOVANIE
//#define TRIANGLE_2
//#define TRIANGLE_3
//#define TRIANGLE_4
//#define ROMB_1
#define ROMB_2

void main()
{
	setlocale(LC_ALL, "Russian");
	int n,copy,copy_1,copy_2,copy_3;
	cout << "Введите размер фигуры: "; cin >> n;
	copy = n;
	copy_1 = n;
	copy_2 = 0;
	copy_3=n;
#ifdef SQUARE
	for (int i = 0; i < n; i++)
	{
		for (int i = 0; i < n; i++)
		{
			std::cout << "* ";
		}
		std::cout << endl;
	}
#endif // SQUARE

#ifdef TRIANGLE_A
	for (int i = 0; i < n; i++)
	{

		for (int j = 0; j <= i; j++)
		{
			std::cout << "* ";
		}
		std::cout << endl;
	}
#endif // TRIANGLE_A

#ifdef TRIANGLE_B
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < copy; j++)
		{
			std::cout << "* ";
		}
		copy--;
		std::cout << endl;
	}
#endif // TRIANGLE_B

#ifdef TRIANGLE_C
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (j <= n - copy)
			{
				std::cout << "  ";
			}
			else
			{
				std::cout << "* ";
			}
		}
		std::cout << endl;
		copy--;
	}
#endif // TRIANGLE_C

#ifdef TRIANGLE_D
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (j <= n - i)
			{
				std::cout << "  ";
			}
			else
			{
				std::cout << "* ";
			}
		}
		std::cout << endl;
	}
#endif // TRIANGLE_D

#ifdef ROMB
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1;  j <= n; j++)
			{
				if (j <= n - i)		std::cout << " ";
				else if(j==copy_1)	std::cout << "/";
				else	std::cout << " ";
			}
				copy_1--;
			for (int j = 0; j < i; j++)
			{
				if (copy_2 == j)	std::cout << "\\";
				else	std::cout << " ";
			}
			copy_2++;
			std::cout << endl;
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (j == n - copy)	std::cout << "\\";
				else std::cout << " ";
			}
			for (int j = 0; j <= n; j++) 
			{
				 if (j == copy_3-1)	std::cout << "/";
				else 	std::cout << " ";
			}
			copy_3--;
			copy--;
			std::cout << endl;
		}
#endif //ROMB

#ifdef KRADENII_KOD_ROMBA

		for (int i = 0; i < n * 2; ++i) {
			for (int j = 0;
				i < n ? j < n - i : j < i - n + 1;
				++j)
				cout << ' ';

			cout << (i < n ? '/' : '\\');

			for (int j = 0;
				i < n ? j < i * 2 : j < (n * 2 - i - 1) * 2;
				++j)
				cout << ' ';

			cout << (i < n ? '\\' : '/');

			for (int j = 0;
				i < n ? j < n - i : j < i - n + 1;
				++j)
				cout << ' ';

			cout << endl;
		}
		украл крутой код для ромба
#endif // KRADENII_KOD_ROMBA

#ifdef CHEREDOVANIE
		for (int i = 0; i < n; i++)
		{
			if (n % 2 == 0)
			{

				for (int j = 0; j < n; j++)
				{
					copy_2++;
					if (copy_2 % 2 == 0)	std::cout << "- ";
					else	std::cout << "+ ";
				}
			copy_2--;
			}
			else
			{

				for (int j = 0; j < n; j++)
				{
					copy_2++;
					if (copy_2 % 2 == 0)	std::cout << "- ";
					else    std::cout << "+ ";
				}
			}
			std::cout << endl;
		}
#endif // CHEREDOVANIE

#ifdef TRIANGLE_2
		for (int i = 0; i < n; i++)
		{
			for (int j = i; j < n; j++)
			{
				std::cout << "*";
			}
			std::cout << endl;
		}
#endif // TRIANGLE_2

#ifdef TRIANGLE_3
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < i; j++) std::cout << "  ";
			for (int j = i; j < n; j++) std::cout << "* ";
			std::cout << endl;
		}
#endif // TRIANGLE_3

#ifdef TRIANGLE_4
		for (int i = 0; i < n; i++)
		{
			for (int j = i; j < n - 1; j++) std::cout << "  ";
			for (int j = 0; j <= i; j++) std::cout << "* ";
			std::cout << endl;
		}
#endif // TRIANGLE_4

#ifdef ROMB_1

		for (int i = 0; i < n; i++)
		{
			for (int j = i; j < n; j++) std::cout << " ";	std::cout << "/";
			for (int j = 0; j < i; j++) std::cout << "  ";	std::cout << "\\";
			std::cout << endl;
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j <= i; j++) std::cout << " "; std::cout << "\\";
			for (int j = i; j < n - 1; j++) std::cout << "  "; std::cout << "/";
			std::cout << endl;
		}
#endif // ROMB_1

#ifdef ROMB_2
		for (int i = 0; i < n; i++)
		{
			for (int j = i; j < n; j++) std::cout << " "; std::cout << "/";
			for (int j = 0; j < i * 2; j++) std::cout << " "; std::cout << "\\";
			std::cout << endl;
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j <= i; j++) std::cout << " "; std::cout << "\\";
			for (int j = 0; j < (n - i - 1) * 2; j++) std::cout << " "; std::cout << "/";
			std::cout << endl;
		}
#endif // ROMB_2

}