#include <iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;
using std::size_t;

class String;
String operator+(const String& left, const String& right);

class String
{
	std::size_t size;	//Размер строки в байтах
	char* str;		//указатель на строку в динамической памяти
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
const char* String::get_str()const
{
	return str;
}
char* String::get_str()
{
	return str;
}
std::size_t String::get_size()const
{
	return size;
}

//			Constructors:
String::String(size_t size) :size(size), str(new char[size] {})
{
	//this->size = size;
	//this->str = new char[size] {}; //Потери памяти!
	std::cout << "DefConstructor:\t" << this << std::endl;
}
String::String(const char str[]) :String(strlen(str) + 1)
{
	//this->size = strlen(str)+1;
	//this->str = new char[size] {};
	for (int i = 0; i < size; i++)this->str[i] = str[i];
	std::cout << "Constructor:\t" << std::endl;
}
String::String(const String& other) : String(other.str)
{
	//this->size = other.size;
	//this->str = new char[size] {};
	//for (int i = 0; i < size; i++)this->str[i] = other.str[i];
	std::cout << "CopyConstructor:\t" << this << std::endl;
}
String::String(String&& other) : size(other.size), str(other.str)
{
	//this->size = other.size;
	//this->str = other.str;
	other.size = 0;
	other.str = nullptr;
	std::cout << "MoveConstructor: " << this << std::endl;

}
String::~String()
{
	delete[] this->str;
	std::cout << "Destructor:\t" << this << std::endl;
}

//				Operators:
String& String::operator=(const String& other)
{
	if (this == &other)return *this;
	delete[] this->str;
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++) this->str[i] = other.str[i];
	std::cout << "CopeAssignment:\t" << this << std::endl;
	return *this;
}
String& String::operator= (String&& other)
{
	if (this == &other) return *this;
	delete[] this->str;
	this->size = other.size;
	this->str = other.str;
	other.size = 0;
	other.str = nullptr;
	std::cout << "MoveAssignment:\t" << this << std::endl;
	return *this;
}
String& String::operator+=(const String& other)
{
	return *this = *this + other;
}
char String::operator[](int i)const
{
	return str[i];
}
char& String::operator[](int i)
{
	return str[i];
}
//				Methods:
void String::print()const
{
	std::cout << "size:\t" << size << std::endl;
	std::cout << "str:\t" << str << std::endl;
}
ostream& operator<<(ostream& os, const String& obj)
{
	return os << obj.get_str();
}

String operator+(const String& left, const String& right)
{
	/*String cat(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)	
		cat.get_str()[i] = left.get_str()[i];
	for (int i = 0; i < right.get_size(); i++)
		cat.get_str()[i + left.get_size() - 1] = right.get_str()[i];
		*/
	String cat(left.get_size() + right.get_size());
	for (int i = 0; i < left.get_size(); i++)
		cat[i] = left[i];	
	for (int i = 0; i < right.get_size(); i++)
		cat[i + left.get_size() -1] = right[i];
	return cat;
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
	//String str3;
	// str3 = str1 + str2;
	//cout << str3 << endl;
	str1 += str2;
	std::cout << str1 << std::endl;
	String str4 = str1;
	std::cout << str4 << std::endl;

#endif // OPERATOR_PLUS_CHECK


}