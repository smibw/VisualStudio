#include <iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

class String
{
	size_t size;	//Размер строки в байтах
	char* str;		//указатель на строку в динамической памяти
public:
	const char* get_str()const
	{
		return str;
	}
	int get_size()const
	{
		return size;
	}
		//			Constructors:
	explicit String(size_t size=80)
	{
		this->size = size;
		this->str = new char[size] {};
		std::cout << "DefConstructor:\t" << this << std::endl;
	}
	String(const char str[])
	{
		this->size = strlen(str)+1;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = str[i];
		std::cout << "Constructor:\t" << std::endl;
	}
	String(const String& other)
	{
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		std::cout << "CopyConstructor:\t" << this << std::endl;
	}
	~String()
	{
		delete[] this->str;
		std::cout << "Destructor:\t" << this << std::endl;
	}
	//				Operators:
	String& operator=(const String& other)
	{
		if (this== &other)return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++) this->str[i] = other.str[i];
		std::cout << "CopeAssignment:\t" << this << std::endl;
		return *this;
	}
	const char& operator[](int i)const
	{
		return str[i];
	}
	char& operator[](int i)
	{
		return str[i];
	}
	//				Methods:
	void print()const
	{
		std::cout << "size:\t" <<size<< std::endl;
		std::cout << "str:\t" << str<<std::endl;
	}
};
ostream& operator<<(ostream& os, const String& obj)
{
	return os << obj.get_str();
}

String operator+(const String& left, const String& right)
{
	String answer(left.get_size() + right.get_size());
	for (int i = 0; i < left.get_size(); i++)
	{
		answer[i] = left[i];
	}
	for (int i = 0; i < right.get_size(); i++)
	{
		answer[i + left.get_size() -1] = right[i];
	}
	return answer;
}

//#define CONSTRUCTOR_CHECK
#define OPERATOR_PLUS_CHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTOR_CHECK
	String str1;			//Пустая строка размером 80 Байт
	str1.print();
	std::cout << str1 << std::endl;

	String str2(22);
	str2.print();

	String str3 = "Hello";
	str3.print();

	String str4 = str3;			// CopyConstructor
	std::cout << str4 << std::endl;

	String str5;				// Default Constructor
	str5 = str4;				//CopyAssignmment
	std::cout << str5 << std::endl;
#endif // CONSTRUCTOR_CHECK


#ifdef OPERATOR_PLUS_CHECK
	String str1 = "Hello";
	String str2 = "World";
	String str3 = str1 + str2;
	cout << str3 << endl;
#endif // OPERATOR_PLUS_CHECK
}