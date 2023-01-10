#include <iostream>
#include<conio.h>
#include<thread>
using namespace std;
using namespace std::chrono_literals;
using std::cout;
using std::cin;
using std::endl;

#define delimiter "\n-------------------------------\n"
#define min_tank_VOLUME 20
#define max_tank_VOLUME 80

class Tank
{
	const unsigned int VOLUME;	//Характеристика объекта
	double fuel;				//Состояние объекта
public:
	unsigned int get_VOLUME()const
	{
		return VOLUME;
	}
	double get_fuel_level()const
	{
		return fuel;
	}
	void fill(double fuel)
	{
		if (fuel < 0)return;
		if (this->fuel + fuel < VOLUME)this->fuel += fuel;
		else this->fuel = VOLUME;
	}
	Tank(unsigned int volume)
		:VOLUME(volume<=min_tank_VOLUME?min_tank_VOLUME:
			volume>max_tank_VOLUME?max_tank_VOLUME:volume)
	{
		this->fuel = 0;
		std::cout << "Tank is ready" << std::endl;
	}
	~Tank()
	{
	std::cout << "Tank is over" << std::endl;
	}
	void info()const
	{
		std::cout << "Tank volume: " << VOLUME << " liters" << std::endl;
		std::cout << "Fuel level: " << fuel << " liters" << std::endl;
	}
};

#define min_engine_consumption 4
#define max_engine_consumption 20

class Engine
{
	double consumption;
	double consumption_per_second;
	bool is_started;
public:
	double get_conssumption()const
	{
		return consumption;
	}
	double get_consumption_per_second()const
	{
		return consumption_per_second;
	}
	Engine(double consumption)
		:consumption(consumption<min_engine_consumption ? min_engine_consumption :
			consumption>max_engine_consumption ? max_engine_consumption : consumption)
	{
		consumption_per_second = consumption * 3e-5;
		std::cout << "Engine is ready" << std::endl;
	}
	~Engine()
	{
		std::cout << "Engine is over" << std::endl;
	}
	bool start()
	{
		return is_started = true;
	}
	bool stop()
	{
		return is_started = false;
	}
	bool started()const
	{
		return is_started;
	}
	void info()const
	{
		std::cout << "Consumption/100 km: " << consumption<<" liters" << std::endl;
		std::cout << "Consumption/1sec km: " << consumption_per_second <<" liters" << std::endl;
		std::cout << "Engine is " << (is_started ? "started" : "stopped") << std::endl;
	}
};

class Car
{
	Engine engine;
	Tank tank;
	bool driver_inside;
	struct Control
	{
		std::thread panel_thread;
	}threads;
public:
	Car(double consumption, int volume):engine(consumption), tank(volume)
	{
		driver_inside = false;
		std::cout << "Your car is ready to go" << std::endl;
	}
	~Car()
	{
		std::cout << "Your car is over" << std::endl;
	}
	void get_in()
	{
		driver_inside = true;
		threads.panel_thread = std::thread(&Car::panel,this);
	}
	void get_out()
	{
		driver_inside = false;
		if (threads.panel_thread.joinable()) threads.panel_thread.join();
		system("CLS");
		std::cout << "You are out of a car" << std::endl;
	}

	void control()
	{
		char key;
		do
		{
			key = _getch();
			switch (key)
			{
			case 13:
				if (driver_inside)get_out();
				else get_in();
				break;
			case'F':
			case'f':
				if (driver_inside)
				{
					std::cout << "Чтобы заправиться, выйдите из машины" << std::endl;
				}
				else
				{
					double fuel;
					std::cout << "Введите объем топлива: "; std::cin >> fuel;
					tank.fill(fuel);
				}
					break;
			case'I':
			case'i':
				//if (engine.started())engine.stop();
				//else engine.start();
			case 27:
				get_out();
				std::cout << "Good buy;-)" << std::endl;
				break;
			}
		} while (key != 27);
	}
	void panel()
	{
		while (driver_inside)
		{
			system("CLS");
			std::cout << "Engine is " << (engine.started() ? "started" : "stopped") << std::endl;
			std::cout << "Fuel level: " << tank.get_fuel_level() << " liters" << std::endl;
			std::this_thread::sleep_for(500ms);
		}
	}
	void info()const
	{
		engine.info();
		tank.info();
	}
};

//#define TANK_CHECK
//#define ENGINE_CHECK
void main()
{
	setlocale(LC_ALL, "Rus");
#ifdef TANK_CHECK
	Tank tank(3);
	tank.info();
	std::cout << delimiter << std::endl;
	tank.fill(10);
	tank.fill(3);
	tank.info();
#endif // TANK_CHECK

#ifdef ENGINE_CHECK
	Engine engine(10);
	//engine.start();
	engine.info();
#endif // ENGINE_CHECK

	Car BMW(12, 60);
	//BMW.info();
	BMW.control();
}