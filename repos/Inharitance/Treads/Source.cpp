#include <iostream>
#include <thread>
using namespace std;
using std::cout;
using std::cin;
using std::endl;
using namespace std::chrono_literals;

bool finish = false;

void Plus()
{
	while (!finish)
	{
	std::cout << "+ ";
	std::this_thread::sleep_for(0.5s);
	}
}
void Minus()
{
	while (!finish)
	{
		std::cout << "- ";
		std::this_thread::sleep_for(1s);
	}
}
void main()
{
	setlocale(LC_ALL, "");
	//Plus();
	//Minus();
	std::thread plus_thread(Plus);
	std::thread minus_thread(Minus);
	cin.get();
	finish = true;

	minus_thread.join();
	plus_thread.join();
}
