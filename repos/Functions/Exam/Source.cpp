//TASK ������� �� ����� ���� ������� ���.����� ����, �� �� ��� �� 1 �������� ���������
#include <iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

void main()
{
	setlocale(LC_ALL, "");	

		do 
		{
			int i = 256;
			std::cout << (char)i << "\t";
			i--;
		} while (true);
}