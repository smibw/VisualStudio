#include <iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

//#define TASK1
//#define TASK2
//#define TASK3

void main()
{
	setlocale(LC_ALL, "");
	int number, buffer,a,b,f,x;
#ifdef TASK1
	number = 10819;
	std::cout << number << std::endl;
	for (int i = 1; i <= 9; i++)
	{
		if (number > 0)
		{
			buffer = number % 10;
			number /= 10;
			std::cout << i << "�� ������ ����� �����: " << buffer << std::endl;
		}
		else break;
	}
#endif // TASK1

#ifdef TASK2
	x = 0;
	std::cout << "a="; std::cin >> a; std::cout << std::endl;
	std::cout << "b="; std::cin >> b; std::cout << std::endl;
	std::cout << "f="; std::cin >> f; std::cout << std::endl;
	std::cout << "������ �������� ��� ���������� �� �������:	x=(� + b � f / �) + f * a * a � (a + b)";
	x = (a + b - f / a) + f * a * a - (a + b);
	std::cout << "=" << x << std::endl;
#endif // TASK2

#ifdef TASK3
	char g, y;
	std::cout << "������� ����� ������� ��������:";
	cin >> g;
	y = int(g) - 32;
	cout << "�� �� ����� � ������� ��������:" << y << endl;
#endif // TASK3

	
}