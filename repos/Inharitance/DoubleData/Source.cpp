#include <iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

#define tab "\t"
#define delimiter "\n----------------------------------\n"
//#define DEBUG

template <typename T>
class List
{
	class Element
	{
		T Data;
		Element* pNext;
		Element* pPrev;
	public:
		Element(T Data, Element* pNext = nullptr, Element* pPrev = nullptr);			
		~Element();
		friend class List<T>;
	}*Head, *Tail;
		unsigned int size;
	class ConstBaseIterator
	{
	protected:
		Element* Temp;
	public:
		ConstBaseIterator(Element* Temp);
		~ConstBaseIterator();

		bool operator==(const ConstBaseIterator& other)const;
		bool operator!=(const ConstBaseIterator& other)const;
		const T& operator*()const;
	};
public:

	class ConstIterator:public ConstBaseIterator
	{
	public:
		ConstIterator(Element* Temp = nullptr);
		~ConstIterator();
		ConstIterator& operator++();
		ConstIterator operator++(int);
		ConstIterator& operator--();
		ConstIterator operator--(int);
	};

	class ConstReverseIterator:public ConstBaseIterator
	{
	public:
		ConstReverseIterator(Element* Temp);
		~ConstReverseIterator();
		ConstReverseIterator& operator++();
		ConstReverseIterator operator++(int);
		ConstReverseIterator& operator--();
		ConstReverseIterator operator--(int);
	};

	class Iterator:public ConstIterator
	{
	public:
		Iterator(Element* Temp) :ConstIterator(Temp) {}
		~Iterator() {}
		T& operator*();
	};

	class ReverseIterator :public ConstReverseIterator
	{
	public:
		ReverseIterator(Element* Temp) :ConstReverseIterator(Temp) {}
		~ReverseIterator() {}
		T& operator*();
	};

	ConstIterator begin()const;
	ConstIterator end()const;
	ConstReverseIterator rbegin()const;
	ConstReverseIterator rend()const;
	ReverseIterator rbegin();
	ReverseIterator rend();

	//					Constructors:
	List();
	List(const std::initializer_list<T>& il);
	List(const List<T>& other);
	~List();

	//			Operator:
	List<T>& operator=(const List<T>& other);

	//			Adding Elements:
	void push_front(T Data);
	void push_back(T Data);
	void insert(int Index, T Data);

	//			Removing Elements:
	void pop_front();
	void pop_back();

	//			Methods:
	void print()const;
	void reverse_print()const;
};
/////////////////////////////////////////////////////////////////////////
///////////////						Element					/////////////
/////////////////////////////////////////////////////////////////////////
template <typename T> List<T>::Element::Element(T Data, Element* pNext, Element* pPrev )
	:Data(Data), pNext(pNext), pPrev(pPrev)
{
	std::cout << "EConstructor:\t" << this << std::endl;
}
template <typename T> List<T>::Element::~Element()
{
	std::cout << "EDestructor:\t" << this << std::endl;
}
/////////////////////////////////////////////////////////////////////////
///////////////				 Const_BASE_Iterators			/////////////
/////////////////////////////////////////////////////////////////////////
template<typename T> List<T>::ConstBaseIterator::ConstBaseIterator(Element* Temp) :Temp(Temp)
{
#ifdef DEBUG
	std::cout << "BCItConstructor:\t" << this << std::endl;
#endif // DEBUG
}
template<typename T> List<T>::ConstBaseIterator::~ConstBaseIterator()
{
#ifdef DEBUG
	std::cout << "BCItDestructor:\t" << this << std::endl;
#endif // DEBUG
}
template <typename T> bool List<T>::ConstBaseIterator::operator==(const ConstBaseIterator& other)const
{
	return this->Temp == other.Temp;
}
template <typename T> bool List<T>::ConstBaseIterator::operator!=(const ConstBaseIterator& other)const
{
	return this->Temp != other.Temp;
}
template <typename T> const T& List<T>::ConstBaseIterator::operator*()const
{
	return Temp->Data;
}
/////////////////////////////////////////////////////////////////////////
///////////////				 Const_Iterators			/////////////////
/////////////////////////////////////////////////////////////////////////
template<typename T> List<T>::ConstIterator::ConstIterator(Element* Temp) :ConstBaseIterator(Temp)
{
#ifdef DEBUG
	std::cout << "ItConstructor:\t" << this << std::endl;
#endif // DEBUG
}
template<typename T> List<T>::ConstIterator::~ConstIterator()
{
#ifdef DEBUG
	std::cout << "ItDestructor:\t" << this << std::endl;
#endif // DEBUG

}
template<typename T> typename List<T>::ConstIterator& List<T>::ConstIterator::operator++()
{
	ConstBaseIterator::Temp = ConstBaseIterator::Temp->pNext;
	return *this;
}
template<typename T> typename List<T>::ConstIterator List<T>::ConstIterator::operator++(int)
{
	ConstIterator old = *this;
	ConstBaseIterator::Temp = ConstBaseIterator::Temp->pNext;
	return old;
}
template<typename T> typename List<T>::ConstIterator& List<T>::ConstIterator::operator--()
{
	ConstBaseIterator::Temp = ConstBaseIterator::Temp->pPrev;
	return *this;
}
template<typename T> typename List<T>::ConstIterator List<T>::ConstIterator::operator--(int)
{
	ConstIterator old = *this;
	ConstBaseIterator::Temp = ConstBaseIterator::Temp->pPrev;
	return old;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T>List<T>::ConstReverseIterator::ConstReverseIterator(Element* Temp) :ConstBaseIterator(Temp)
{
#ifdef DEBUG
	std::cout << "RItConstructor:\t" << this << std::endl;
#endif // DEBUG
}
template<typename T>List<T>::ConstReverseIterator::~ConstReverseIterator()
{
#ifdef DEBUG
	std::cout << "RItConstructor:\t" << this << std::endl;
#endif // DEBUG
}
template<typename T>typename List<T>::ConstReverseIterator& List<T>::ConstReverseIterator::operator++()
{
	ConstBaseIterator::Temp = ConstBaseIterator::Temp->pPrev;
	return *this;
}
template<typename T>typename List<T>::ConstReverseIterator List<T>::ConstReverseIterator::operator++(int)
{
	ConstReverseIterator old = *this;
	ConstBaseIterator::Temp = ConstBaseIterator::Temp->pPrev;
	return old;
}
template<typename T>typename List<T>::ConstReverseIterator& List<T>::ConstReverseIterator::operator--()
{
	ConstBaseIterator::Temp = ConstBaseIterator::Temp->pNext;
	return *this;
}
template<typename T>typename List<T>::ConstReverseIterator List<T>::ConstReverseIterator::operator--(int)
{
	ConstReverseIterator old = *this;
	ConstBaseIterator::Temp = ConstBaseIterator::Temp->pNext;
	return old;
} 
/////////////////////////////////////////////////////////////////////////
///////////////////				Iterators			/////////////////////
/////////////////////////////////////////////////////////////////////////
template<typename T>T& List<T>::Iterator::operator*()
{
	return ConstBaseIterator::Temp->Data;
}
template<typename T>T& List<T>::ReverseIterator::operator*()
{
	return ConstBaseIterator::Temp->Data;
}

///////////////////////////////////////////////////////////////////////////
//////////////////					List		     //////////////////////
///////////////////////////////////////////////////////////////////////////
template<typename T>typename List<T>::ConstIterator List<T>::begin()const
{
	return Head;
}
template<typename T>typename List<T>::ConstIterator List<T>::end()const
{
	return nullptr;
}
template<typename T>typename List<T>::ConstReverseIterator List<T>::rbegin()const
{
	return Tail;
}
template<typename T>typename List<T>::ConstReverseIterator List<T>::rend()const
{
	return nullptr;
}
template<typename T>typename List<T>::ReverseIterator List<T>::rbegin()
{
	return Tail;
}
template<typename T>typename List<T>::ReverseIterator List<T>::rend()
{
	return nullptr;
}
//					Constructors:
template<typename T>List<T>::List()
{
	Head = Tail = nullptr;
	size = 0;
	std::cout << "LConstructor:\t" << this << std::endl;
}
template<typename T>List<T>::List(const std::initializer_list<T>& il) :List()
{
	for (T const* it = il.begin(); it != il.end(); it++)
	{
		push_back(*it);
	}
}
template<typename T>List<T>::List(const List<T>& other) :List()
{
	*this = other;
	std::cout << "CopeCOnstructor:" << this << std::endl;
}
template<typename T>List<T>::~List()
{
	//while (Head)pop_front();
	while (Tail)pop_back();
	std::cout << "LDestructor:\t" << this << std::endl;
}
//			Operator:
template <typename T>List<T>& List<T>::operator=(const List<T>&other)
{
	if (this == &other) return *this;
	while (Head)pop_front();
	for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)
		push_back(Temp->Data);
	std::cout << "CopeAssignment:\t" << this << std::endl;
	return *this;
}
//			Adding Elements:
template <typename T>void List<T>::push_front(T Data)
{
	if (Head == nullptr && Tail == nullptr)
	{
		Head = Tail = new Element(Data);
		size++;
		return;
	}
	Head = Head->pPrev = new Element(Data, Head);
	size++;
}
template <typename T>void List<T>::push_back(T Data)
{
	if (Head == nullptr && Tail == nullptr)
	{
		Head = Tail = new Element(Data);
		size++;
		return;
	}
	Tail = Tail->pNext = new Element(Data, nullptr, Tail);
	size++;
}
template <typename T>void List<T>::insert(int Index, T Data)
{
	if (Index > size)
	{
		std::cout << "Error: Out of range." << std::endl;
		return;
	}
	if (Index == 0)return push_front(Data);
	if (Index == size)return push_back(Data);
	Element* Temp;
	if (Index < size / 2)
	{
		Temp = Head;
		for (int i = 0; i < Index; i++)Temp = Temp->pNext;
	}
	else
	{
		Temp = Tail;
		for (int i = 0; i < size - Index - 1; i++)Temp = Temp->pPrev;
	}
	/*Element* New=new Element(Data);
	New->pNext=Temp;
	New->pPrev=Temp->pPrev;
	Temp->pPrev->pNext=New;
	Temp->pPrev=New;*/
	Temp->pPrev = Temp->pPrev->pNext = new Element(Data, Temp, Temp->pPrev);
	size++;
}
//			Removing Elements:
template <typename T>void List<T>::pop_front()
{
	if (Head == nullptr && Tail == nullptr)return;
	if (Head == Tail)
	{
		delete Head;
		Head = Tail = nullptr;
		size--;
		return;
	}
	Head = Head->pNext;
	delete Head->pPrev;
	Head->pPrev = nullptr;
	size--;
}
template <typename T>void List<T>::pop_back()
{
	if (Head == Tail)return pop_front();
	Tail = Tail->pPrev;
	delete Tail->pNext;
	Tail->pNext = nullptr;
	size--;
}
//			Methods:
template <typename T>void List<T>::print()const
{
	std::cout << "������ ������: " << Head << std::endl;
	for (Element* Temp = Head; Temp; Temp = Temp->pNext)
		std::cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << std::endl;
	std::cout << "����� ������: " << Tail << std::endl;
	std::cout << "���������� ��������� ������: " << size << std::endl;
}
template <typename T>void List<T>::reverse_print()const
{
	std::cout << "����� ������: " << Tail << std::endl;
	for (Element* Temp = Tail; Temp; Temp = Temp->pPrev)
		std::cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << std::endl;
	std::cout << "������ ������: " << Head << std::endl;
	std::cout << "���������� ��������� ������: " << size << std::endl;

}

template <typename T>List<T> operator+(const List<T>& left, const List<T>& right)
{
	List<T> cat = left;
	for (typename List<T>::ConstIterator it = right.begin(); it != right.end(); it++)
	{
		cat.push_back(*it);
		//*it *= 100;
	}
	return cat;
}

template<typename T>void FillRand(List<T>& list)
{
	for (typename List<T>::Iterator it = list.begin(); it != list.end(); it++)
	{
		*it = rand();
	}
}


//#define BASE_CHECK
//#define CONSTRUCTION_CHECK
//#define pumpurumpumpum
//#define CHTOTOCHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef BASE_CHECK
	setlocale(LC_ALL, "");
	int n;
	std::cout << "������� ������ ������: "; std::cin >> n;
	List list;
	for (int i = 0; i < n; i++)
	{
		//list.push_front(rand() % 100);
		list.push_back(rand() % 100);
	}
	list.print();
	list.reverse_print();

	int index;
	int value;
	std::cout << "������� ������ ������������ ��������: "; std::cin >> index;
	std::cout << "������� �������� ������������ ��������: "; std::cin >> value;
	list.insert(index, value);
	list.print();
	list.reverse_print();
#endif // BASE_CHECK

#ifdef CONSTRUCTION_CHECK
	List list = { 3,5,8,13,21 };
	list.print();
	list.reverse_print();
	std::cout << delimiter << std::endl;

	List list2;
	list2 = list;
	list2.print();
	list2.reverse_print();
#endif // CONSTRUCTION_CHECK

#ifdef pumpurumpumpum
	List list = { 3, 5, 8, 13, 21 };
	for (int i : list)
	{
		cout << i << tab;
	}
	cout << endl;
	for (List::ConstReverseIterator rit = list.rbegin(); rit != list.rend(); rit++)
	{
		std::cout << *rit << tab;
	}
	std::cout << std::endl;
#endif // pumpurumpumpum


#if CHTOTOCHECK
	List list = { 3, 5, 8, 13, 21 };
	List list2 = { 34,55,89 };
	List list3 = list + list2;
	for (int i : list)std::cout << i << tab;	std::cout << std::endl;
	for (int i : list2)std::cout << i << tab;	std::cout << std::endl;
	for (int i : list3)std::cout << i << tab;	std::cout << std::endl;
#endif // CHTOTOCHECK


	List<int> i_list = { 3,5,8,13,21 };
	i_list.print();
	i_list.reverse_print();
	List<int> i_list_2 = { 34,55,89 };
	List<int> i_list_3 = i_list + i_list_2;
	for (int i : i_list_3) std::cout << i << tab; std::cout << std::endl;

	List<double> d_list_1 = { 2.7, 3.14, 5.3, 8.9 };
	d_list_1.print();
	d_list_1.reverse_print();
	List<double> d_list_2 = { 25.4, 88.97, 98.2 };
	List<double> d_list_3 = d_list_1 + d_list_2;
	for (double i : d_list_3)std::cout << i << tab; std::cout << std::endl;

	List<std::string> s_list_1 = { "������","�����","��","�����","�����","���" };
	List<std::string> s_list_2 = { "���","�","��������","�����","�","���","������","�������" };
	List<std::string> s_list_3 = s_list_1 + s_list_2;
	for (std::string i : s_list_3)std::cout << i << "  "; std::cout << std::endl;
	for (List<std::string>::ReverseIterator it = s_list_3.rbegin(); it != s_list_3.rend(); ++it)
	{
		std::cout << *it << tab;
	}
	std::cout << std::endl;
}
/*
���������� ������=������, ������� �������� �� ������ ����� ���� �� � ����������� ��������
��������� ����� �� 2�������� ������ ����� ������������ �� 2� ������������
��� �� ������ � �����, ��� � �� ����� � ������.
����� ������, � 2�������� ������ ���� ��� � �����(Tail), �� ��������� �� �� ������� ������� ������.
��� ���� ����������� ��������� �������� � ����� ������ �� ����������� �����.
����� ������ ����, ��� ������ � ����� ��������� �� 0.
� ����� � ������ ���������� 1� �������, �� ������������ �������� � ������� � �������.
����� ���� �� ������������ �������� � ������ � �������� ��������� ������, ������ � ����� ������.
����������� ����������� �� ������ � ����� ������������
������������ ��������� ����� ������� � �������� � 2 ����
�� ������ ������ ������� �� ��������� � 1������� � ������� ����.
*/