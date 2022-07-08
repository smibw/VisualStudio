#include <iostream>
#include <conio.h>
using namespace std;

#define Enter 13
#define Escape 27
#define UP_ARROW 72
#define DOWN_ARROW 80
#define RIGHT_ARROW 75
#define LEFT_ARROW 77

void main()
{
	setlocale(LC_ALL, "Russian");
	char key;
	do
	{
			key = _getch();
			switch (key)
			{
			case'w':case'W':case UP_ARROW:		cout << "Вперед" <<	endl;	break;
			case's':case'S':case DOWN_ARROW :	cout << "Назад" <<	endl;	break;
			case'a':case'A':case LEFT_ARROW:	cout << "Налево" << endl;	break;
			case'd':case'D':case RIGHT_ARROW :	cout << "Вправо" << endl;	break;
			case' ':	cout << "Прыжок" << endl;	break;
			case Enter:	cout << "Огонь" <<	endl;	break;
			case Escape:cout << "Выход" <<	endl;	break;
			case -32:								break;
			default:	cout << "Error" <<	endl;
			}
	}
			while (key!=Escape);
}