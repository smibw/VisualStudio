#pragma once
#include <iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;
using std::size_t;
/////////////////////////////////////////////////////////////////////////
////////////////// ���������� ������(CLASS DECLARATION)//////////////////
/////////////////////////////////////////////////////////////////////////
class String;
String operator+(const String& left, const String& right);
ostream& operator<<(ostream& os, const String& obj);
class String
{
	std::size_t size;	//������ ������ � ������
	char* str;		//��������� �� ������ � ������������ ������
public:
	const char* get_str()const;
	char* get_str();
	std::size_t get_size()const;

	//				Constructors:
	explicit String(std::size_t size = 80);
	String(const char str[]);
	String(const String& other);
	String(String&& other);
	~String();

	//				Operators:
	String& operator=(const String& other);
	String& operator= (String&& other);
	String& operator+=(const String& other);
	char operator[](int i)const;
	char& operator[](int i);

	//				Methods:
	void print()const;
};
/////////////////////////////////////////////////////////////////////////
////////////////// ����� ���������� ������(CLASS DECLARATION END)////////
/////////////////////////////////////////////////////////////////////////