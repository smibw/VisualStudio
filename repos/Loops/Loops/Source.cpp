#include <iostream>
#include <conio.h>
using namespace std;
//#define PALINDROME
//#define HAPPYBILET
#define SHOOTER_1
//#define SHOOTER_2

#define UP_ARROW 72
#define DOWN_ARROW 80
#define RIGHT_ARROW 77
#define LEFT_ARROW 75 
#define Escape 27
#define Enter 13


void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef PALINDROME
	int number;
	int reverse;
	reverse = 0;
	cout << "Наберите число: "; cin >> number;
	int buffer = number;
	do
	{
		reverse *= 10;
		reverse += buffer % 10;
		buffer /= 10;
	} while (buffer != 0);
	if (number == reverse)
	{
		cout << "Число - палиндром."; cout << number; cout << reverse;
	}
	else
	{
		cout << "Число - не палиндром."; cout << number; cout << reverse;
	}
#endif // PALINDROME
#ifdef HAPPYBILET
	int b, i, l, e, t, z, summ_1, summ_2;
	cout << "Вводите номер билета по одной цифре. После каждой введенной цифры нажимайте Enter.\n";
	cout << "Введите номер билета: "; cin >> b>> i>> l>> e >> t >> z;
	cout << b << i << l << e << t << z << endl;
	summ_1 = b + i + l;
	summ_2 = e + t + z;
	if (summ_1 == summ_2)
	{
		cout << "Happy ticket";
	}
	else cout << "Standart ticket";
#endif 
#ifdef SHOOTER_1
	char key;
	do
	{
		key = _getch();
		cout << int(key) << "\t" << key << endl;
		switch (key)
		{
		case -32:cout << " "; break;
		case 119:cout << " Вперед"<< endl; break;
		case 87:cout << " Вперед" << endl; break;
		case UP_ARROW:cout << "Вперед" << endl; break;
		case 115:cout << " Назад" << endl; break;
		case 83:cout << " Назад" << endl; break;
		case DOWN_ARROW:cout << "Назад" << endl; break;
		case 100:cout << " Вправо" << endl; break;
		case RIGHT_ARROW:cout << "Вправо" << endl; break;
		case 68:cout << " Вправо" << endl; break;
		case 97: cout << " Влево" << endl; break;
		case LEFT_ARROW: cout << "Влево" << endl; break;
		case 65:cout << " Влево" << endl; break;
		case Enter:cout << " Огонь!" << endl; break;
		case 101:cout << " Поднять предмет" << endl; break;
		case 69:cout << " Поднять предмет" << endl; break;
		case 32:cout << " Прыжок" << endl; break;
		case Escape:cout << " Выход" << endl; break;
		default :cout << " Error:действие не распознано" << endl;
		}

	} while (key != 27);
	cout << "Вы покинули битву." << endl;
#endif
#ifdef SHOOTER_2
	char key;
	do
	{
		key = _getch();
		//cout << (int)key << "\t" << key << endl;
		if (key == 'w' || key == 'W' || key == UP_ARROW)	cout << "Вперед" << endl;
		else if (key == 's' || key == 'S' || key == DOWN_ARROW)	cout << "Назад" << endl;
		else if (key == 'a' || key == 'A' || key == LEFT_ARROW)	cout << "Влево" << endl;
		else if (key == 'd' || key == 'D' || key == RIGHT_ARROW) cout << "Вправо" << endl;
		else if (key == ' ')cout << "Прыжок" << endl;
		else if (key == Enter)cout << "Огонь" << endl;
		else if (key == Escape)cout << "Выход" << endl;
		else if (key != -32)cout << "Error: не понимаю, что вы хотите сделать..." << endl;
	} while (key != Escape);
#endif // SHOOTER_2

}