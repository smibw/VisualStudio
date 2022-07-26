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
	std::cout << "Выберите номер этажа: " << std::endl;  std::cin >> chose;
	elevator(floor,chose);
}
int elevator(int floor, int chose)
{
	if (floor == 0)
	{
		std::cout << "Вы в подвале." << std::endl;
		return elevator(floor+1,chose);
	}
	else if (floor < 50&&floor-1!=chose)
	{
		std::cout << "Вы поднимаетесь." << std::endl;
		std::cout << "Вы достигли этажа N" << floor << std::endl;
		if (chose == floor) std::cout << "Вы достигли нужного этажа, выходите." << std::endl;
		return elevator(floor + 1,chose);
	}
	else if(floor==50)
	{
		std::cout << "Вы поднимаетесь." << std::endl;
		std::cout << "Вы достигли крыши." << std::endl;
		return 0;
	}
}
