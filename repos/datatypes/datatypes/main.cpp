//datatypes
#include <iostream>
using namespace std;
//#define INTEGRAL_TYPES
//#define REAL_TYPES

void main()
{
	setlocale(LC_ALL, "Russian");
	//cout << true << endl;
	//cout << false << endl;
#ifdef INTEGRAL_TYPES
	cout << sizeof(int) << endl;
	cout <<"Unsigned int: " << 0 << " ... " << UINT_MAX << endl;
	cout << "signed int: " << INT_MIN << " ... " << INT_MAX << endl;
#endif // INTEGRAL_TYPES
#ifdef REAL_TYPES
	cout << sizeof(float) << endl;
	cout << FLT_MIN << " ... " << FLT_MAX << endl;
	cout << sizeof(double) << endl;
	cout << DBL_MIN << " ... " << DBL_MAX << endl;
#endif

}
