#include <iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;
#define tab "\t"
#define delimiter "--------------------\n"
int elevator(int floor, int chose);
int main()
{
	setlocale(LC_ALL, "");
	int floor = 0;
	int chose ;
	std::cout << "�������� ����� �����: " << std::endl;  std::cin >> chose;
	elevator(floor,chose);
}
int elevator(int floor, int chose)
{
	if (floor == 0)
	{
		std::cout << "�� � �������." << std::endl;
		return elevator(floor+1,chose);
	}
	else if (floor < 50&&floor-1!=chose)
	{
		std::cout << "�� ������������." << std::endl;
		std::cout << "�� �������� ����� N" << floor << std::endl;
		if (chose == floor) std::cout << "�� �������� ������� �����, ��������." << std::endl;
		return elevator(floor + 1,chose);
	}
	else if(floor==50)
	{
		std::cout << "�� ������������." << std::endl;
		std::cout << "�� �������� �����." << std::endl;
		return 0;
	}
}
