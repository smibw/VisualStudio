#include <iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

void Exchange(int a, int b);

void main()
{
	setlocale(LC_ALL, "");
	int a = 2, b = 3;
	std::cout << a << "\t" << b << std::endl;
	std::cout << &a << "\t" << &b << std::endl;
	Exchange(a, b);
	std::cout << a << "\t" << b << std::endl;

}
void Exchange(int a, int b)
{
	std::cout << &a << "\t" << &b << std::endl;
	int buffer = a;
	a = b;
	b = buffer;
}