#include <iostream>

using namespace std;
using std::cout;
using std::cin;
using std::endl;

#define tab "\t"
#define delimiter "\n------------\n"
//#define FACTORIAL
#define DEGREE

int Factorial(int factorial, int number);
int Degree(int number, int x);

void main()
{
	setlocale(LC_ALL, "");
	int	number;
#ifdef FACTORIAL
	int factorial = 1;
	std::cout << "������� �����:"; std::cin >> number;
	std::cout << "��������� ����� = " << Factorial(factorial, number);
#endif // FACTORIAL

#ifdef DEGREE
	int x = 0;
	std::cout << "������� �����: "; std::cin >> number;
	std::cout << "������� ������� �����: "; std::cin >> x;
	std::cout << "������� ����� = " << Degree(number, x);
#endif // DEGREE

}
int Factorial(int factorial, int number)
{
	int counter;
	counter = number;
	for (int i = 0; i < counter; i++)
	{
		factorial *= number;
		number--;
	}
	return factorial;
}
int Degree(int number, int x)
{
	int end = 1;
	for (int i = 0; i < x; i++)
	{
		end*= number;
	}
	return end;
}