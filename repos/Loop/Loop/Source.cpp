#include <iostream>
#include <conio.h>
using namespace std;
//#define gfgf
//#define gsgf2

void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef gfgf
	int i = 0;
	int n;
	cout << "Введите количество итераций:"; cin >> n;
	while (i < n)
	{
		cout << i++ << "Hello world!\n";
	}
#endif // gfgf
#ifdef gfgf2
	int n;
	cout << "Введите количество итераций:"; cin >> n;
	while (n--)
	{
		cout << n << "Hello world!\n";
	}
#endif // gfgf2
	char key;
	do {
		key = _getch();// _getch ожидает нажатия клавиши и вшзвращает ASCII код нажатой клавиши
		//_getch находится в conio.h
		cout << (int)key << "\t" << key << endl;
	} while (key!=27);
}