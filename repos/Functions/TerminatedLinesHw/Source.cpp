#include <iostream>
#include<Windows.h>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

void remove_symbol(char str[], const char symbol);
void remove_symbol_better(char str[]);
void remove_symbol_for_bin(char str[]);

void to_upper(char str[]);				//��������� ������ � ������� �������
void to_lower(char str[]);				//��������� ������ � ������ �������
void shrink(char str[]);				//������� ������ ������� �� �����������
bool is_palindrome(const char str[]);	//���������, �������� �� ������ �����������
bool is_int_number(const char str[]);	//���������, �������� �� ������ ����� ���������� ������
int  to_int_number(char str[]);			//���� ������ �������� ����� ���������� ������, ���������� �� �������� ��������
bool is_bin_number(const char str[]);	//���������, �������� �� ������ �������� ������
int  bin_to_dec(char str[]);			//���� ������ �������� �������� ������, ���������� �� ���������� ��������
bool is_hex_number(const char str[]);	//���� ������ �������� �������� ������, ���������� �� ���������� ��������
int  hex_to_dec(char str[]);			//���� ������ �������� ����������������� ������, ���������� �� ���������� ��������

void main()
{
	setlocale(LC_ALL, "");
	const int SIZE = 50;
	char str[SIZE] = {};
	std::cout << "������� �����." << std::endl;
	SetConsoleCP(1251);
	cin.getline(str,SIZE);
	//shrink(str);
	//std::cout << str << std::endl;;
	//to_upper(str);
	//std::cout << str << std::endl;;
	//to_lower(str);
	//std::cout << str<<std::endl;
	//std::cout << "������ " << (is_palindrome(str) ? "" : "�� ") << "�������� �����������" << std::endl;
	//std::cout << "������ " << (is_int_number(str) ? "" : "�� ") << "�������� ����� ���������� ������" << std::endl;
	//std::cout<<to_int_number(str)<<std::endl; 
	//std::cout << "������ " << (is_bin_number(str) ? "" : "�� ") << "�������� �������� ������" << std::endl;
	//std::cout << bin_to_dec(str) << std::endl;
	std::cout << "������ " << (is_hex_number(str) ? "" : "�� ") << "�������� ����� ����������������� ������" << std::endl;
}
void to_upper(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= '�' && str[i] <= '�'|| str[i] >= 'a' && str[i] <= 'z') str[i] -= ' ';
	}
}
void to_lower(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= '�' && str[i] <= '�' || str[i] >= 'A' && str[i] <= 'Z') str[i] += ' ';
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
		if (buffer[i] < 'A' || buffer[i] > 'F'|| buffer[i] < '1'|| buffer[i] > '9')
		{
			delete[] buffer;
			return false;
		}

	}
	delete[] buffer;
	return true;
}
/*
int  hex_to_dec(char str[]);
*/