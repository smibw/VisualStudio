//TASK вывести на экран аски таблицу исп.любой цикл, но не исп ни 1 операции сравнения
#include <iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

void main()
{
	setlocale(LC_ALL, "");	

		do 
		{
			int i = 256;
			std::cout << (char)i << "\t";
			i--;
		} while (true);
}