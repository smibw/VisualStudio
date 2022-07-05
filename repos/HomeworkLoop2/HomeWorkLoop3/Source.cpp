#include <iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;
#define TASK_1
//#define TASK_2

void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef TASK_1
	for (int j = 1; j < 10; j++)
	{
		for (int i = 1; i < 10; i++)
		{
			std::cout << i << "*" << j << "=" << i * j << "\t";
		}
		std::cout << std::endl;
	}
#endif // TASK_1
#ifdef TASK_2
	for (int j = 1; j < 10; j++)
	{
		std::cout << std::endl;
		for (int i = 1; i < 10; i++)
		{
			std::cout << i * j << "\t";
		}
		std::cout << std::endl;
	}
#endif // TASK_2

}
