#include <iostream>

using namespace std;
using std::cout;
using std::cin;
using std::endl;

//#define DECIMAL
//#define HEXADECIMAL
//#define HEXADECIMAL_2
#define HEXADECIMAL_COPY

void main()
{
	setlocale(LC_ALL, "");

#ifdef DECIMAL
	int decimal;
	std::cout << "Введите десятичное число с клавиатуры: "; std::cin >> decimal;
	const int MAX_SIZE = 32;
	bool bin[MAX_SIZE] = {};
	int i = 0;
	for (; decimal; i++, decimal /= 2) bin[i] = decimal % 2;

	for (--i; i >= 0; i--)
	{
		std::cout << bin[i];
		if (i % 8 == 0) std::cout << " ";
		if (i % 4 == 0) std::cout << " ";
	}
	std::cout << endl;
#endif // DECIMAL

#ifdef HEXADECIMAL
	int decimal;
	std::cout << "Введите десятичное число для перевода в шестнадцатеричную систему исчисления: "; std::cin >> decimal;
	const int MAX_SIZE = 8;
	int hexadecimal[MAX_SIZE];
	int i = 0;
	for (; i <= 7; i++)
	{
		hexadecimal[i] = decimal % 16;
		decimal /= 16;
		switch (hexadecimal[i])
		{
		case 1: hexadecimal[i] = 1; continue;
		case 2: hexadecimal[i] = 2; continue;
		case 3: hexadecimal[i] = 3; continue;
		case 4:hexadecimal[i] = 4; continue;
		case 5:hexadecimal[i] = 5; continue;
		case 6:hexadecimal[i] = 6; continue;
		case 7:hexadecimal[i] = 7; continue;
		case 8:hexadecimal[i] = 8; continue;
		case 9:hexadecimal[i] = 9; continue;
		case 10: hexadecimal[i] = 'A'; continue;
		case 11: hexadecimal[i] = 'B'; continue;
		case 12: hexadecimal[i] = 'C'; continue;
		case 13: hexadecimal[i] = 'D'; continue;
		case 14: hexadecimal[i] = 'E'; continue;
		case 15:hexadecimal[i] = 'F'; continue;
		default: hexadecimal[i] = 0; continue;
		}
	}
	for (; i >= 0; i--)
	{
		if (hexadecimal[i] == 0) std::cout << hexadecimal[i];
		if (hexadecimal[i] == 1) std::cout << hexadecimal[i];
		if (hexadecimal[i] == 2) std::cout << hexadecimal[i];
		if (hexadecimal[i] == 3) std::cout << hexadecimal[i];
		if (hexadecimal[i] == 4) std::cout << hexadecimal[i];
		if (hexadecimal[i] == 5) std::cout << hexadecimal[i];
		if (hexadecimal[i] == 6) std::cout << hexadecimal[i];
		if (hexadecimal[i] == 7) std::cout << hexadecimal[i];
		if (hexadecimal[i] == 8) std::cout << hexadecimal[i];
		if (hexadecimal[i] == 9) std::cout << hexadecimal[i];
		if (hexadecimal[i] == 65) std::cout << (char)hexadecimal[i];
		if (hexadecimal[i] == 66) std::cout << (char)hexadecimal[i];
		if (hexadecimal[i] == 67) std::cout << (char)hexadecimal[i];
		if (hexadecimal[i] == 68) std::cout << (char)hexadecimal[i];
		if (hexadecimal[i] == 69) std::cout << (char)hexadecimal[i];
		if (hexadecimal[i] == 70) std::cout << (char)hexadecimal[i];
	}
#endif //HEXADECIMAL

#ifdef HEXADECIMAL_2
	int decimal;
	std::cout << " Введите десятичное число: "; std::cin >> decimal;
	const int n = 8;
	int hex[n] = {};
	int i = 0;
	for (; decimal; i++)
	{
		hex[i] = decimal % 16;
		decimal /= 16;
	}
	std::cout << "0x"; //Префикс показывающий, что число записано в hexadecimal
	for (; i >= 0; i--)
	{
		std::cout << char(hex[i] + (hex[i] < 10 ? 48 : 55));
		/*switch (hex[i])
		{
			case 10:std::cout << "A"; break;
			case 11:std::cout << "B"; break;
			case 12:std::cout << "C"; break;
			case 13:std::cout << "D"; break;
			case 14:std::cout << "E"; break;
			case 15:std::cout << "F"; break;
			default:std::cout << hex[i];
		}*/
	}
	std::cout << endl;
#endif // HEXADECIMAL_2

#ifdef HEXADECIMAL_COPY
	int decimal;
	std::cout << "Введите десятичное число: "; std::cin >> decimal;
	const int n = 8;
	int hexadecimal[n]{};
	int i = 0;
	for (; decimal; i++)
	{
		hexadecimal[i] = decimal % 16;
		decimal /= 16;
	}
	for (; i >= 0; i--)
	{
		std::cout << char(hexadecimal[i] + (hexadecimal[i] < 10 ? 48 : 55));
	}
	std::cout << endl;
#endif // HEXADECIMAL_COPY

}