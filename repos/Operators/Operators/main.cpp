#include<iostream>
using namespace std;
//#define Arithmetical_Operators
#define Trinary
//#define Assignment_Operator
//#define Increment_Decrement
//#define Compaund_Assignments
//#define CNTRL_K_S
void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef Arithmetical_Operators
	cout << 17 / 3 << endl;
	cout << 17 % 3 << endl;
	cout << 3 % 17 << endl;

#endif
#ifdef Trinary
	int a;
	cout << "Введите а: "; cin >> a; cout << endl;
	a > 5 ? a += 8 : a *= 3; cout << a;
#endif
#ifdef Assignment_Operator
	int a=5;
	int b= a + 6;
	const int d=2;
	int c = (a * b) / d;
	int f ,g,h;
	f = g = h = 0;
//	l - value = r - value; для всех оператоов ассоциативность слева на право, для присваивания справа налево;
	cout << c;
#endif
#ifdef Increment_Decrement
	int i = 3;
	i++; ++i; i++;
	cout << i;
	// ++i; prefix increment
	// i++; postfix increment
	// --i; prefix decrement
	// i--; postfix decrement
#endif
#ifdef Compaund_Assignments

#endif
#ifdef CNTRL_K_S
	sdwpojrisjdkjpowekpogklsdk; ksogweppodksfsl
		sdogpsdkdsf
#endif // CNTRL_K_S

}