#include <iostream>
#include <conio.h>
using namespace std;
using std::cout;
using std::cin;

void main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "Введите количество итераций: "; cin >> n;
	for (int i=0;i<n;i++)
	{
		cout <<i<< "\t";
	}
	cout << endl;
}