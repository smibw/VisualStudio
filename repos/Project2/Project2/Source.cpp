#include <iostream>
using namespace std;

void main()
{
setlocale (LC_ALL, "Russian");
	double znachenie_a;
	double znachenie_b;
	double znachenie_c;
	cout << "��������� �� �������� �������� �������.\n";
	cout << "������� �������� �: "; cin >> znachenie_a;
	cout << "������� �������� b: "; cin >> znachenie_b;
	znachenie_c = znachenie_a;
	znachenie_a = znachenie_b;
	znachenie_b = znachenie_c;
	cout << "�������� �: " << znachenie_a << endl;
	cout << "�������� b: " << znachenie_b << endl;

}


