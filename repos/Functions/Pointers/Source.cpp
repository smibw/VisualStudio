#include <iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;
//#define BASICS_POINTERS

void main()
{
	setlocale(LC_ALL, "");
#ifdef BASICS_POINTERS
	int a = 2;
	int* pa = &a;
	std::cout << a << std::endl;
	std::cout << &a << std::endl;
	std::cout << pa << std::endl;
	std::cout << *pa << std::endl;
	int b = 3;
	int* pb;
	pb = &b;
	std::cout << b << std::endl;
	std::cout << &b << std::endl;
	std::cout << pb << std::endl;
	std::cout << *pb << std::endl;
#endif // BASICS_POINTERS

	const int n = 5;
	int arr[n] = { 3,5,8,13,21 };
	std::cout << arr << std::endl;
	std::cout << *arr << std::endl;
	for(int i = 0; i < n; i++)
	{
		std::cout << *(arr+i) << "\t";
	}
}