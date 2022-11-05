#include "String.h"

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