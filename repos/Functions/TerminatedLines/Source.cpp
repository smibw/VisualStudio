#include <iostream>
#include <Windows.h>
using namespace std;
using std::cout;
using std::endl;
using std::cin;

//#define EXAMPLE1
//#define EXAMPLE2
//#define EXAMPLE3
//#define Task1
#define Task2

int StringLength(const char str[]);
void upper_case(char str[]);
void lower_case(char str[]);
void shrink(char[]);
bool is_palindrome(char str[]);

void main()
{
	setlocale(LC_ALL, "");
#ifdef EXAMPLE1
	//char str[] = { 'H', 'e', 'l', 'l', 'o',0 };
	char str[] = "Hello";
	//Hello-строкова€ костанта;
	std::cout << str << std::endl;
	std::cout << typeid(str).name() << std::endl;
	std::cout << typeid("hello").name() << std::endl;
#endif // EXAMPLE1

#ifdef EXAMPLE2
	const int SIZE = 20;
	char str[SIZE] = {};

	std::cout << "¬ведите строку: ";
	//std::cin >> str;
	cin.getline(str, SIZE);
	std::cout << str << std::endl;
#endif // EXAMPLE2

#ifdef EXAMPLE3
	const int SIZE = 20;
	char str[SIZE] = {};
	std::cout << (int) '\0'  << std::endl;
	std::cout << (int)'0' << std::endl;
	std::cout << "¬ведите строку: ";
	//std::cin >> str;
	SetConsoleCP(1251);
	cin.getline(str, SIZE);
	std::cout << str << std::endl;
#endif // EXAMPLE3

#ifdef Task1
	const int SIZE = 256;
	char str[SIZE] = {};
	std::cout << (int)'\0' << std::endl;
	std::cout << (int)'0' << std::endl;
	std::cout << "¬ведите строку: ";
	SetConsoleCP(1251);
	cin.getline(str, SIZE);
	SetConsoleCP(866);
	std::cout << str << std::endl;
	std::cout << "ƒлина строки:" << StringLength(str) << std::endl;
	std::cout << "ƒлина строки:" << strlen(str) << std::endl;
#endif // Task1

#ifdef Task2
	const int SIZE = 256;
	char str[SIZE] = {};
	//std::cout << (int)'\0' << std::endl;
	//std::cout << (int)'0' << std::endl;
	std::cout << "¬ведите строку: ";
	SetConsoleCP(1251);
	cin.getline(str, SIZE);
	SetConsoleCP(866);
	std::cout << str << std::endl;
	upper_case(str);
	std::cout << str << std::endl;
	lower_case(str);
	std::cout << str << std::endl;
#endif // Task2

	
}
void shrink(char[])
{
	for (int i = 0; str[i]; i++)
	{
		while

			for (int j=0;str[j];j++)
			{
				str[j] = str[j + 1];
			}
	}
}
void lower_case(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		str[i] = tolower(str[i]);
	}
}
void upper_case(char str[])
{
	
	for (int i = 0; str[i]; i++)
	{
		//if (str[i] >= 97 && str[i] <= 122)str[i] -= 32;
		//if (str[i] >= 'а' && str[i] <= '€')str[i] -= ' ';
		//if (str[i] == 'Є')str[i] = '®';
		str[i] = toupper(str[i]);
	}
	std::cout << std::endl;
}
int StringLength(const char str[])
{
	int i = 0;
	for (; str[i]; i++);
	return i;
}
bool is_palindrome(char str[])
{
	int size = strlen(str);
	for (int i = 0; i < size; i++)
	{
		if (str[i] != str[size - 1 - i]) return false;
	}
	return true;
}