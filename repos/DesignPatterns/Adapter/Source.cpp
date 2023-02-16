#include<iostream>
#include<string>

using namespace std;
using std::cout;
using std::cin;
using std::endl;

typedef int Cable;

//Adaptee source interface
class EuropeanSicketInterface
{
public:
	virtual int voltage() = 0;
	
	virtual Cable live() = 0;		//Фаза
	virtual Cable neutral() = 0;	//0
	virtual Cable earth() = 0;		//Заземление
};

//Adaptee
class Socket :public EuropeanSicketInterface
{
	int voltage()override
	{
		return 220;
	}

	Cable live()override
	{
		return 1;
	}
	Cable neutral()
	{
		return -1;
	}
	Cable earth()
	{
		return 0;
	}
};

//Target interface:
class USASocketInterface
{
public:
	virtual int voltage() = 0;

	virtual Cable live() = 0;
	virtual Cable neutral() = 0;
};

//The adapter:
class Adapter :public USASocketInterface
{
	EuropeanSicketInterface* socket;

public:
	void plugIn(EuropeanSicketInterface* outlet)
	{
		socket = outlet;
	}

	int voltage()override
	{
		return 110;
	}
	Cable live()
	{
		return socket->live();
	}
	Cable neutral()
	{
		return socket->neutral();
	}
};

//Client:
class ElectricKettle
{
	USASocketInterface* power;
public:
	void plugIn(USASocketInterface* supply)
	{
		power = supply;
	}

	void boil()
	{
		if (power->voltage() > 110)
		{
			std::cout << "Alarm: Kettle is on fire" << std::endl;
			return;
		}
		if (power->live() == 1 && power->neutral() == -1)
		{
			std::cout << "Have a nice coffee" << std::endl;
		}
	}
};

void main()
{
	setlocale(LC_ALL, "");
	
	Socket* socket=new Socket;
	Adapter* adapter=new Adapter;
	ElectricKettle* kettle = new ElectricKettle;

	adapter->plugIn(socket);
	kettle->plugIn(adapter);

	kettle->boil();
}

/*
	Adapter - структурный паттерн, который позволяет взаимодействовать объектам
	с несовместимыми интерфейсами. Он состоит из целевого объекта

				Client				 Target{};			 Adaptee{};
										|					 |								
										|					 |
										|---->Adapter{};<----|
 */