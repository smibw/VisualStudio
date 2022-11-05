#include <iostream>
#include<Windows.h>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

void remove_symbol(char str[], const char symbol);
void remove_symbol_better(char str[]);
void remove_symbol_for_bin(char str[]);

void to_upper(char str[]);				//Переводит строку в верхний регистр
void to_lower(char str[]);				//Переводит строку в нижний регистр
void shrink(char str[]);				//Удаляет лишние пробелы из предложения
bool is_palindrome(const char str[]);	//Проверяет, является ли строка палиндромом
bool is_int_number(const char str[]);	//Проверяет, является ли строка целым десятичным числом
int  to_int_number(char str[]);			//Если строка является целым десятичным числом, возвращает ее числовое значение
bool is_bin_number(const char str[]);	//Проверяет, является ли строка двоичным числом
int  bin_to_dec(char str[]);			//Если строка является двоичным числом, возвращает ее десятичное значение
bool is_hex_number(const char str[]);	//Если строка является двоичным числом, возвращает ее десятичное значение
int  hex_to_dec(char str[]);			//Если строка является шестнадцатеричным числом, возвращает ее десятичное значение

void main()
{
	setlocale(LC_ALL, "");
	const int SIZE = 50;
	char str[SIZE] = {};
	std::cout << "Введите текст." << std::endl;
	SetConsoleCP(1251);
	cin.getline(str,SIZE);
	//shrink(str);
	//std::cout << str << std::endl;;
	//to_upper(str);
	//std::cout << str << std::endl;;
	//to_lower(str);
	//std::cout << str<<std::endl;
	//std::cout << "Строка " << (is_palindrome(str) ? "" : "НЕ ") << "является палиндромом" << std::endl;
	//std::cout << "Строка " << (is_int_number(str) ? "" : "НЕ ") << "является целым десятичным числом" << std::endl;
	//std::cout<<to_int_number(str)<<std::endl; 
	//std::cout << "Строка " << (is_bin_number(str) ? "" : "НЕ ") << "является двоичным числом" << std::endl;
	//std::cout << bin_to_dec(str) << std::endl;
	std::cout << "Строка " << (is_hex_number(str) ? "" : "НЕ ") << "является целым шестнадцатиричным числом" << std::endl;
	std::cout << hex_to_dec(str) << std::endl;
}
void to_upper(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= 'а' && str[i] <= 'я'|| str[i] >= 'a' && str[i] <= 'z') str[i] -= ' ';
	}
}
void to_lower(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= 'А' && str[i] <= 'Я' || str[i] >= 'A' && str[i] <= 'Z') str[i] += ' ';
	}
}
void shrink(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == ' ' && str[i + 1] == ' ')
		{
			for (int j = i + 1; str[j]; j++)
			{
				str[j] = str[j + 1];
			}
		}
	}
}
void remove_symbol(char str[], const char symbol)
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == symbol)
		{
			for (int j = i; str[j]; j++)str[j] = str[j + 1];
		}
	}
}
bool is_palindrome(const char str[])
{
	char* buffer = new char[strlen(str) + 1]{};
	strcpy(buffer, str);
	to_lower(buffer);
	remove_symbol(buffer, ' ');
	int size = strlen(buffer);
	for (int i = 0; i < size; i++)
	{
		if (buffer[i] != buffer[size - 1 - i])
		{
			delete[] buffer;
			return false;
		}
	}
	delete[] buffer;
	return true;
}
bool is_int_number(const char str[])
{
	char* buffer = new char[strlen(str) + 1]{};
	strcpy(buffer, str);
	remove_symbol(buffer, ' ');
	int size = strlen(buffer);
	for (int i = 0; i < size; i++)
	{
		if (buffer[i] < '0' || buffer[i] > '9')
		{
			delete[] buffer;
			return false;
		}
	}
	delete[] buffer;
	return true;
}
int  to_int_number(char str[])
{
	if (is_int_number(str) == true)
	{

		int a = 0;
		char* buffer = new char[strlen(str) + 1]{};
		strcpy(buffer, str);
		remove_symbol(buffer, ' ');
		int size = strlen(buffer);
		int* number = new int[size + 1]{};
		for (int i = 0; i < size; i++)
		{
			if (buffer[i] >= '0' && buffer[i] <= '9')	number[i] = buffer[i];
		}
		for (int i = 0; i < size; i++)
		{
			switch (buffer[i])
			{
			case '0':number[i] -= '0'; break;
			case '1':number[i] -= '0'; break;
			case '2':number[i] -= '0'; break;
			case '3':number[i] -= '0'; break;
			case '4':number[i] -= '0'; break;
			case '5':number[i] -= '0'; break;
			case '6':number[i] -= '0'; break;
			case '7':number[i] -= '0'; break;
			case '8':number[i] -= '0'; break;
			case '9':number[i] -= '0'; break;
			default:  break;
			}
		}
		int size2 = size;
		for (int i = 0; i < size; i++)
		{
			int b = 1;
			for (int j = size2 - 1; j > 0; j--)
			{
				b *= 10;
			}
			size2--;
			a += number[i] * b;
		}
		delete[] buffer;
		return a;
	}
	else return 0;
}
bool is_bin_number(const char str[])
{
	char* buffer = new char[strlen(str) + 1]{};
	strcpy(buffer, str);
	remove_symbol(buffer, ' ');
	int size = strlen(buffer);
	for (int i = 0; i < size; i++)
	{
		if (buffer[i] != '0' && buffer[i] != '1')
		{
			delete[] buffer;
			return false;
		}

	}
	delete[] buffer;
	return true;
}
int  bin_to_dec(char str[])
{
	if (is_bin_number(str) == true)
	{

		int a = to_int_number(str);
		int b = sizeof(a) - 1;
		int buffer = 0;
		int i = 0;
		do
		{
			int c = 1;
			for (int k = b - i; k < b; k++)
			{
				c *= 2;
			}
			(a % 10) == 1 ? buffer += (a % 10) * c : buffer += 0;
			a /= 10;
			i++;
		} while (a != 0);
		return buffer;
	}
	else return 0;
}
bool is_hex_number(const char str[])
{
	char* buffer = new char[strlen(str) + 1]{};
	strcpy(buffer, str);
	remove_symbol(buffer, ' ');
	int size = strlen(buffer);
	for (int i = 0; i < size; i++)
	{
		if (buffer[i] < 'A' && buffer[i] > 'F'|| buffer[i] < '1'&& buffer[i] > '9')
		{
			delete[] buffer;
			return false;
		}

	}
	delete[] buffer;
	return true;
}

int  hex_to_dec(char str[])	
{
	int rez = 0;
	int k=0;
	for (int i = 0; str[i]; i++)
	{
		switch (toupper(str[i]))
		{
		case 'A': k = 10; break;
		case 'B': k = 11; break;
		case 'C': k = 12; break;
		case 'D': k = 13; break;
		case 'E': k = 14; break;
		case 'F': k = 15; break;
		case '1': k = 1; break;
		case '2': k = 2; break;
		case '3': k = 3; break;
		case '4': k = 4; break;
		case '5': k = 5; break;
		case '6': k = 6; break;
		case '7': k = 7; break;
		case '8': k = 8; break;
		case '9': k = 9; break;
		case '0': k = 0; break;
		}
		int res = 1;
		int x = 16;
		int y = (strlen(str) - 1 - i);
		for (int i = 1; i <= y; i++)	res *= x;
		rez += k * res;
	}
	return rez;
}