#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

class Element
{
	int Data;		//�������� ��������
	Element* pNext;	//����� ���������� ��������
	static unsigned int count;	//���������� ���������
public:
	Element(int Data, Element* pNext = nullptr) :Data(Data), pNext(pNext)
	{
		count++;
		cout << "EConstructor:\t" << this << endl;
	}
	~Element()
	{
		count--;
		cout << "EDestructor:\t" << this << endl;
	}
	friend class ForwardList;
	friend ForwardList operator+(const ForwardList& left, const ForwardList& right);
	
};

unsigned int Element::count = 0;	//����������� ���������� ����� ������������������� ������ �� �������

class ForwardList
{
	Element* Head;	//��������� �� ��������� ������� ������
	//������ �������� ������ ����� � ������
	unsigned int size;
public:
	ForwardList() :Head(nullptr), size(0)
	{
		//����������� �� ��������� ������� ������ ������.
		//���� ������ ��������� �� 0, �� ������ ����
		cout << "LConstructor:\t" << this << endl;
	}
	ForwardList(const ForwardList& other):ForwardList()
	{
		/*for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)
			push_back(Temp->Data);*/
		*this = other;
		std::cout << "CopyConstructor:\t" << this << std::endl;
	}
	ForwardList(const ForwardList&& other) :ForwardList()
	{
		*this = std::move(other);
		std::cout << "MoveConstructor:\t" << std::endl;
	}
	~ForwardList()
	{
		while (Head)pop_front();
		cout << "LDestructor:\t" << this << endl;
	}
	//				Operators:
	ForwardList& operator=(const ForwardList& other)
	{
		if (this == &other)return *this;
		while (Head)pop_front();
		for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)
			push_back(Temp->Data);
		std::cout << "CopyAssignment:\t" << this << std::endl;
		return *this;
	}
	ForwardList& operator=(ForwardList&& other)
	{
		if (this == &other) return *this;
		while (Head)pop_front();
		this->Head = other.Head;
		this->size = other.size;
		other.Head = nullptr;
		other.size = 0;
		std::cout << "MoveAssignment:\t" << std::endl;
		return *this;
	}

	//				Adding Elements:
	void push_front(int Data)
	{
		/*
		//1) ������� ����� �������:
		Element* New = new Element(Data);
		//2) �������������� ����� ������� � ������ ������:
		New->pNext = Head;
		//3) ��������� ������ �� ����� �������:
		Head = New;
		size++;
		*/
		Head = new Element(Data, Head);
		size++;

	}
	void push_back(int Data)
	{
		if (Head == nullptr)return push_front(Data);
		//1) ������� ����� �������:
		//Element* New = new Element(Data);
		//2) ������� �� ���������� �������� ������:
		Element* Temp = Head;
		while (Temp->pNext)Temp = Temp->pNext;
		//������ �������� ��������� �� ��������� ������� ������,
		//� � ���� ����� ������������ ����� �������.
		//3) ������������ � ���������� �������� ������ ����� �������:
		//Temp->pNext = New;
		Temp->pNext = new Element(Data);
		size++;
	}
	void insert(int Index, int Data)
	{
		if (Index == 0)return push_front(Data);
		if (Index > size)
		{
			cout << "Error: Out of range" << endl;
			return;
		}
		//1) ������� ����� �������:
		//Element* New = new Element(Data);

		//2) ������� �� ������� ��������:
		Element* Temp = Head;
		for (int i = 0; i < Index - 1; i++)
			/*if(Temp->pNext)*/Temp = Temp->pNext;

		//3) �������� ����� ������� � ������:
		//New->pNext = Temp->pNext;
		//Temp->pNext = New;
		Temp->pNext = new Element(Data, Temp->pNext);
		size++;
	}

	//				Removing elements
	void pop_front()
	{
		//1) ��������� ����� ���������� ��������:
		Element* erased = Head;
		//2) ��������� ������� �� ������:
		Head = Head->pNext;
		//3) ������� ������� �� ������:
		delete erased;
		size--;
	}
	void pop_back()
	{
		if (Head == nullptr)return;
		if (Head->pNext == nullptr)return pop_front();
		//1) ������� �� �������������� �������� ������:
		Element* Temp = Head;
		while (Temp->pNext->pNext)Temp = Temp->pNext;
		//2) ������� ��������� ������� �� ������:
		delete Temp->pNext;
		//3) �������� ��������� �� ��������� �������:
		Temp->pNext = nullptr;
		size--;
	}

	//				Methods:
	void print()const
	{
		cout << "Head:\t" << Head << endl;
		/*
		Element* Temp = Head;	//Temp - ��� ��������.
		//�������� - ��� ���������, ��� ������ �������� 
		//����� �������� ������ � ��������� ��������� ������.
		while (Temp)
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			Temp = Temp->pNext;	//������� �� ��������� �������
		}
		*/
		for (Element* Temp = Head; Temp; Temp = Temp->pNext)
			std::cout << Temp << tab << Temp->Data << tab << Temp->pNext << std::endl;
		cout << "���������� ��������� ������:\t  " << size << endl;
		cout << "����� ���������� ��������� ������:" << Element::count << endl;
	}
	friend ForwardList operator+(const ForwardList& left, const ForwardList& right);
};
ForwardList operator+(const ForwardList& left, const ForwardList& right)
{
	ForwardList cat = left;
	for (Element* Temp = right.Head; Temp; Temp = Temp->pNext)
		cat.push_back(Temp->Data);
	return cat;
}

//#define BASE_CHECK
//#define COUNT_CHECK
//#define RANGE_BASED_FOR_ARRAY
#define RANGE_BASED_FOR_LIST

void main()
{
	setlocale(LC_ALL, "");
#ifdef BASE_CHECK
	int n;
	cout << "������� ������ ������: "; cin >> n;
	ForwardList list;
	list.push_back(1024);
	list.print();
	list.pop_back();
	list.print();
	for (int i = 0; i < n; i++)
	{
		//list.push_front(rand() % 100);
		list.push_back(rand() % 100);
	}
	list.print();
	/*list.push_back(123);
	list.print();*/
	//list.pop_back();
	int index;
	int value;
	cout << "������� ������ ������������ ��������: "; cin >> index;
	cout << "������� �������� ������������ ��������: "; cin >> value;
	list.insert(index, value);
	list.print();
#endif // BASE_CHECK

#ifdef COUNT_CHECK
	ForwardList list1;
	list1.push_back(3);
	list1.push_back(5);
	list1.push_back(8);
	list1.push_back(13);
	list1.push_back(21);

	ForwardList list2;
	list2.push_back(34);
	list2.push_back(55);
	list2.push_back(89);

	list1.print();
	list2.print();

	ForwardList list3 = list1 + list2;
	list3.print();

#endif // COUNT_CHECK

#ifdef RANGE_BASED_FOR_ARRAY
	int arr[] = { 3,5,8,13,21 };
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		std::cout << arr[i] << "\t";
	}
	std::cout << std::endl;
	//range-based for (for ��� ���������, �.�. ��� ����������)
	for (int i : arr)
	{
		std::cout << i << "\t";
	}
	std::cout << std::endl;
#endif // RANGE_BASED_FOR_ARRAY

#ifdef RANGE_BASED_FOR_LIST
	ForwardList list = { 3,5,8,13,21 };
	for (int i : list)
	{
		std::cout << i << "\t";
	}
	std::cout << std::endl;
#endif // RANGE_BASED_FOR_LIST

}