#include <iostream>
#include <string>
#include <map>

using namespace std;
using std::cout;
using std::cin;
using std::endl;

//AbstractPrototipe
class Player
{
public:
	virtual ~Player() {}
	virtual void print()const = 0;
	virtual Player* clone()const = 0;
};

//ConcretePrototipes:
class CarPlayer :public Player
{
	std::string name;
	int id;
public:
	CarPlayer(const std::string& name, int id) :name(name), id(id) 
	{
		std::cout << "CarConstructor:\t" << this << std::endl;
	}
	CarPlayer(const CarPlayer& other) :name(other.name), id(other.id) 
	{
		std::cout << "CarCopyConstructor:\t" << this << std::endl;
	}
	~CarPlayer() 
	{
		std::cout << "CarDestructor:\t" << this << std::endl;
	}

	void print()const override
	{
		std::cout << "Car Player: " << name << " " << id << std::endl;
	}
	Player* clone()const
	{
		return new CarPlayer(*this);
	}
};

class BikePlayer :public Player
{
	std::string name;
	int id;
public:
	BikePlayer(const std::string& name, int id) :name(name), id(id)
	{
		std::cout << "BikeConstructor:\t" << this << std::endl;
	}
	BikePlayer(const BikePlayer& other) :name(other.name), id(other.id)
	{
		std::cout << "BikeCopyConstuctor:\t" << this << std::endl;
	}
	~BikePlayer() 
	{
		std::cout << "BikeDestructor:\t" << this << std::endl;
	}

	void print()const
	{
		std::cout << "Bike player: " << name << " " << id << std::endl;
	}
	Player* clone()const
	{
		return new BikePlayer(*this);
	}
};

enum PlayerType { CAR, BIKE };

class PlayerFactory
{
	std::map<PlayerType, Player*> players;
public:
	PlayerFactory()
	{
		players[CAR] =  new CarPlayer("BNW", 1000);
		players[BIKE] =  new BikePlayer("HarleyDavidson", 777);
	}
	~PlayerFactory()
	{
		delete players[CAR];
		delete players[BIKE];
	}
	Player* CreatePlayer(PlayerType type)
	{
		return players[type]->clone();
	}
};

void main()
{
	setlocale(LC_ALL, "");

	PlayerFactory factory;

	std::cout << "\n------------------------------------------------\n";

	Player* player1 = factory.CreatePlayer(CAR);
	player1->print();

	std::cout << "\n------------------------------------------------\n";

	Player* player2 = factory.CreatePlayer(BIKE);
	player2->print();

	std::cout << "\n------------------------------------------------\n";

}

/*
	Prototipe - порождающий паттерн, создающий эталонные проекты
	В этом паттерне обязательно должен присутствовать метод clone, 
	который создает точную копию объекта

		Client	----------->	AbstractPrototipe
		{						{
		Operation()				Clone();
		}						}

		ConcretePrototipe					ConcretePrototipe2

*/