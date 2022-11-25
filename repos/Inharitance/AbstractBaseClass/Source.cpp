#include <iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

class Animal
{
	std::string name;
public:
	virtual void sound()const = 0;
};
class Cat:public Animal
{

};
class Tiger :public Cat
{
public:
	void sound()const override
	{
		std::cout << "Рррррррррр" << std::endl;
	}
};
class Lion :public Cat
{
public:
	void sound()const override
	{
		std::cout << "Я царь зверей между прочим..." << std::endl;
	}
};
class Dog :public Animal
{

};
class Wolf :public Dog
{
public:
	void sound()const override
	{
		std::cout << "АУУУУУУУУУУУУУ" << std::endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");

	//Animal slon;
	//Cat tom;
	//Tiger tiger;
	//tiger.sound();

	//Lion killer;
	//killer.sound();

	//Wolf ayf;
	//ayf.sound();

	/*
	Animal* zoo[] =
	{
		new Tiger,
		new Lion,
		new Wolf
	};
	for (int i = 0; i < sizeof(zoo)/sizeof(Animal*); i++)
	{
		zoo[i]->sound();
	}
	*/
}


/*
	Абстрактный базовый класс.
	Абстрактным называется класс, экземпляры которого создать невозможно.Поскольку он описывает очень абстрактные понятия.
	Например, такие как: животное, растение, транспортное средство и т.д.
	Абстрактные классы нужны лишь для обобщения и классификации других классов, а также для построения классовых иерархий.
	Для того, чтобы сделать класс абстрактным достаточно объявить в нем, хотя бы 1 чисто виртуальный метод.
	Чисто виртуальным называется метод, не имеющий определения. Например, virtual type name(parameters) = 0;
	ОН должен быть переопределен в дочернем классе, в противном случае дочерний класс также будет абстрактным.
*/