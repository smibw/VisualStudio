#include <iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;
#define tab "\t"
#define delimiter "--------------------\n"
//#define MIRROR_ELEVATOR
#define COOL_ELEVATOR
void MirrorElevator(int x);
int elevator(int floor, int chose);
int main()
{
	setlocale(LC_ALL, "");
#ifdef MIRROR_ELEVATOR
	int x;
	std::cout << "Введите этаж: "; std::cin >> x;
	MirrorElevator(x);
#endif // MIRROR_ELEVATOR

#ifdef COOL_ELEVATOR
	int floor = 0;
	int chose;
	std::cout << "Выберите номер этажа: " << std::endl;  std::cin >> chose;
	elevator(floor, chose);
#endif // COOL_ELEVATOR

}
void MirrorElevator(int x)
{
	if (x == 0)
	{
		std::cout << "Вы в подвале."<<std::endl;
		return;
	}
	std::cout << "Вы на " << x << " этаже \n";
	MirrorElevator(x - 1);
	std::cout << "Вы на " << x << " этаже \n";
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
