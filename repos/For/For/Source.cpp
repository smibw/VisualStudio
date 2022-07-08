#include <iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	//for (couter; condition; expression)
	//{
	//	...;
	//	group - of - statements;
	//	...;
	//}
	int i;
	int a, b, c;
	i = 0;
	a = 0;
	b = 0;
	c = 0;
	for (i; i != 8; i++)
	{
		cout << a << endl;
		a = ++b * ++c;
		cout << a << endl;
	}
	cout << a;
}