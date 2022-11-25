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
		std::cout << "����������" << std::endl;
	}
};
class Lion :public Cat
{
public:
	void sound()const override
	{
		std::cout << "� ���� ������ ����� ������..." << std::endl;
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
		std::cout << "��������������" << std::endl;
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
	����������� ������� �����.
	����������� ���������� �����, ���������� �������� ������� ����������.��������� �� ��������� ����� ����������� �������.
	��������, ����� ���: ��������, ��������, ������������ �������� � �.�.
	����������� ������ ����� ���� ��� ��������� � ������������� ������ �������, � ����� ��� ���������� ��������� ��������.
	��� ����, ����� ������� ����� ����������� ���������� �������� � ���, ���� �� 1 ����� ����������� �����.
	����� ����������� ���������� �����, �� ������� �����������. ��������, virtual type name(parameters) = 0;
	�� ������ ���� ������������� � �������� ������, � ��������� ������ �������� ����� ����� ����� �����������.
*/