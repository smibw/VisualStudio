#include <iostream>
#include<conio.h>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

#define CHESS

#define UPPER_LEFT_ANGLE	(char)218
#define UPPET_RIGHT_ANGLE	(char)191
#define DOWN_LEFT_ANGLE		(char)192
#define DOWN_RIGHT_ANGLE	(char)217
#define WHITE_PART			"\xDB\xDB"
#define BLACK_PART			"  "
#define LINE				"\xC4\xC4"
#define VERTICAL_LINE		(char)179

void main()
{
	int n;
	setlocale(LC_ALL, "");
	std::cout << "Размерность шахматной доски: "; std::cin >> n;
	setlocale(LC_ALL, "C");
/*
	for (int i = 0; i <n ; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i % 2 == 0)
			{
			std::cout << (char)32<<(char)254;
			}
			else
			{
			std::cout << (char)223<<(char)255;
			}
		}
		std::cout << endl;
	}
	std::cout << endl;
	for (int i = 0; i < 256; i++)
	{
		std::cout << i << "\t" << (char)i;
	}
*/

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			//if ((i+j) % 2 == 0) std::cout << "+ ";	else std::cout << "- ";
			//(i+j) % 2 == 0? std::cout << "+ ": std::cout << "- ";
			std::cout << (	(i + j) % 2 == 0 ? "+ " : "- ");
		}
		std::cout << endl;
	}
	
#ifdef CHESS
	n++;
	for (int i = 0; i <= n; i++)
	{
		std::cout << "\t";
		for (int j = 0; j <= n; j++)
		{
			if (i == 0 && j == 0)	std::cout << UPPER_LEFT_ANGLE;
			else if (i == 0 && j == n)	std::cout << UPPET_RIGHT_ANGLE;
			else if (i == n && j == 0)	std::cout << DOWN_LEFT_ANGLE;
			else if (i == n && j == n)	std::cout << DOWN_RIGHT_ANGLE;
			else if (j == 0 || j == n)	std::cout << VERTICAL_LINE;
			else if (i == 0 || i == n)	std::cout << LINE;
			else
			{
				std::cout << ((i + j) % 2 == 0 ? WHITE_PART : BLACK_PART);
			}
		}
		std::cout << endl;
	}
#endif // CHESS

}