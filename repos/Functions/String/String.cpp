#include "String.h"

/////////////////////////////////////////////////////////////////////////
////////////////// ÎÏĞÅÄÅËÅÍÈÅ ÊËÀÑÑÀ(CLASS DEFINITION)//////////////////
/////////////////////////////////////////////////////////////////////////
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
	//this->str = new char[size] {}; //Ïîòåğè ïàìÿòè!
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
		cat[i + left.get_size() - 1] = right[i];
	return cat;
}

/////////////////////////////////////////////////////////////////////////
////////////////// ÊÎÍÅÖ ÎÏĞÅÄÅËÅÍÈÅ ÊËÀÑÑÀ(CLASS DEFINITION END)////////
/////////////////////////////////////////////////////////////////////////