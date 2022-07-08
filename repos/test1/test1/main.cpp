#include <iostream>
using namespace std;
//#define SearchCharType
//#define Lineconst
//1#define Numberconst
//#define IDK
//#define Arithmetical
//#define Assignmentoperator
int main()
{
	setlocale(LC_ALL, "Russian");

#ifdef SearchCharType
	cout << '+' << endl;
	cout << sizeof(char) << endl;
	cout << sizeof('+') << endl;
	cout << typeid('+').name() << endl;
#endif
#ifdef Lineconst
	cout << "Строковые константы:\n";
	cout << "Hello world" << endl;
	cout << sizeof("Hello world") << endl;
	cout << "+" << endl;
	cout << sizeof("+") << endl;
#endif
#ifdef Numberconst
	cout << 1024 << endl;
	cout << sizeof(1024) << endl;
	cout << typeid(1024).name() << endl;
#endif
#ifdef IDK
	cout << 3.14 << endl;//double
	cout << 5. << endl;//double
	cout << 5.f << endl;//float
	cout << 123ll << endl;//long long
	cout << 123ull << endl;// unsigned long long
#endif
#ifdef Arithmetical
	int a = 25;
	int b = 7;
	cout << b % a << endl;
#endif
#ifdef Assignmentoperator
	int a = 25;
	int b = a;
	int c = (a + b) * 2;
	cout << c << endl;

#endif


}
