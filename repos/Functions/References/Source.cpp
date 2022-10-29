#include <iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

void main()
{
	setlocale(LC_ALL, "");
	int a = 2;
	int& ra=a;
	ra += 3;
	std::cout << a<<std::endl;
	std::cout << &a<<std::endl;
	std::cout << &ra<<std::endl;
}