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
		Element(T Data, Element* pNext = nullptr, Element* pPrev = nullptr) 
			:Data(Data), pNext(pNext), pPrev(pPrev)
		{
			std::cout << "EConstructor:\t" << this << std::endl;
		}
		~Element()
		{
			std::cout << "EDestructor:\t" << this << std::endl;
		}
		friend class List<T>;
	}*Head, *Tail;
		unsigned int size;
	class ConstBaseIterator
	{
	protected:
		Element* Temp;
	public:
		ConstBaseIterator(Element* Temp) :Temp(Temp)
		{
#ifdef DEBUG
			std::cout << "BCItConstructor:\t" << this << std::endl;
#endif // DEBUG
		}
		~ConstBaseIterator()
		{
#ifdef DEBUG
			std::cout << "BCItDestructor:\t" << this << std::endl;
#endif // DEBUG

		}

		bool operator==(const ConstBaseIterator& other)const
		{
			return this->Temp == other.Temp;
		}
		bool operator!=(const ConstBaseIterator& other)const
		{
			return this->Temp != other.Temp;
		}
		const T& operator*()const
		{
			return Temp->Data;
		}
	};
public:
	class ConstIterator:public ConstBaseIterator
	{
	public:
		ConstIterator(Element* Temp = nullptr) :ConstBaseIterator(Temp)
		{
#ifdef DEBUG
			std::cout << "ItConstructor:\t" << this << std::endl;
#endif // DEBUG

		}
		~ConstIterator()
		{
#ifdef DEBUG
			std::cout << "ItDestructor:\t" << this << std::endl;
#endif // DEBUG

		}

		ConstIterator& operator++()
		{
			Temp = Temp->pNext;
			return *this;
		}
		ConstIterator operator++(int)
		{
			ConstIterator old = *this;
			Temp = Temp->pNext;
			return old;
		}
		ConstIterator& operator--()
		{
			Temp = Temp->pPrev;
			return *this;
		}
		ConstIterator operator--(int)
		{
			ConstIterator old = *this;
			Temp = Temp->pPrev;
			return old;
		}
	};
	class ConstReverseIterator:public ConstBaseIterator
	{
	public:
		ConstReverseIterator(Element* Temp) :ConstBaseIterator(Temp)
		{
#ifdef DEBUG
			std::cout << "RItConstructor:\t" << this << std::endl;
#endif // DEBUG
		}
		~ConstReverseIterator()
		{
#ifdef DEBUG
			std::cout << "RItConstructor:\t" << this << std::endl;
#endif // DEBUG
		}

		ConstReverseIterator& operator++()
		{
			Temp = Temp->pPrev;
			return *this;
		}
		ConstReverseIterator operator++(int)
		{
			ConstReverseIterator old = *this;
			Temp = Temp->pPrev;
			return old;
		}
		ConstReverseIterator& operator--()
		{
			Temp = Temp->pNext;
			return *this;
		}
		ConstReverseIterator operator--(int)
		{
			ConstReverseIterator old = *this;
			Temp = Temp->pNext;
			return old;
		}
	};
	class Iterator:public ConstIterator
	{
	public:
		Iterator(Element* Temp) :ConstIterator(Temp) {}
		~Iterator() {}

		int& operator*()
		{
			return Temp->Data;
		}
	};
	class ReverseIterator :public ConstReverseIterator
	{
	public:
		ReverseIterator(Element* Temp) :ConstReverseIterator(Temp) {}
		~ReverseIterator() {}

		int& operator*()
		{
			return Temp->Data;
		}
	};
	ConstIterator begin()const
	{
		return Head;
	}
	ConstIterator end()const
	{
		return nullptr;
	}
	ConstReverseIterator rbegin()const
	{
		return Tail;
	}
	ConstReverseIterator rend()const
	{
		return nullptr;
	}
	//					Constructors:
	List()
	{
		Head = Tail = nullptr;
		size = 0;
		std::cout << "LConstructor:\t" << this << std::endl;
	}
	List(const std::initializer_list<T>& il) :List()
	{
		for (int const* it = il.begin(); it != il.end(); it++)
		{
			push_back(*it);
		}
	}
	List(const List<T>& other) :List()
	{
		*this = other;
		std::cout << "CopeCOnstructor:" << this << std::endl;
	}
	~List()
	{
		//while (Head)pop_front();
		while (Tail)pop_back();
		std::cout << "LDestructor:\t" << this << std::endl;
	}
	//			Operator:
	List<T>& operator=(const List<T>& other)
	{
		if (this == &other) return *this;
		while (Head)pop_front();
		for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)
			push_back(Temp->Data);
		std::cout << "CopeAssignment:\t" << this << std::endl;
		return *this;
	}
	//			Adding Elements:
	void push_front(T Data)
	{
		if (Head == nullptr && Tail == nullptr)
		{
			Head = Tail = new Element(Data);
			size++;
			return;
		}
		Head =Head->pPrev= new Element(Data, Head);
		size++;
	}
	void push_back(T Data)
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
	void insert(int Index, T Data)
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
			for (int i = 0; i < size - Index - 1; i++)Temp =Temp->pPrev;
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
	void pop_front()
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
	void pop_back()
	{
		if (Head == Tail)return pop_front();
		Tail = Tail->pPrev;
		delete Tail->pNext;
		Tail->pNext = nullptr;
		size--;
	}
	//			Methods:
	void print()const
	{
		std::cout << "Голова списка: " << Head << std::endl;
		for (Element* Temp = Head; Temp; Temp = Temp->pNext)
			std::cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << std::endl;
		std::cout << "Хвост списка: " << Tail<<std::endl;
		std::cout << "Количество элементов списка: " << size << std::endl;
	}
	void reverse_print()const
	{
		std::cout << "Хвост списка: " << Tail<<std::endl;
		for(Element* Temp=Tail;Temp;Temp=Temp->pPrev)
			std::cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << std::endl;
		std::cout << "Голова списка: " << Head << std::endl;
		std::cout << "Количество элементов списка: " << size << std::endl;

	}
};

template <typename T>
List<T> operator+(const List<T>& left, const List<T>& right)
{
	List<T> cat = left;
	for (List<T>::ConstIterator it = right.begin(); it != right.end(); it++)
	{
		cat.push_back(*it);
		//*it *= 100;
	}
	return cat;
}

template<typename T>
void FillRand(List<T>& list)
{
	for (List<T>::Iterator it = list.begin(); it != list.end(); it++)
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
	std::cout << "Введите размер списка: "; std::cin >> n;
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
	std::cout << "Введите индекс добавляемого элемента: "; std::cin >> index;
	std::cout << "Введите значение добавляемого элемента: "; std::cin >> value;
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

}
/*
Двусвязный список=список, который содержит не только адрес след но и предыдущего элемента
благодаря этому по 2связному списку можно перемещаться по 2м направлениям
как от начала к концу, так и от конца к началу.
Кроме головы, у 2связного списка есть еще и хвост(Tail), он указывает на по следний элемент списка.
Что дает возможность добавлять элементы в конец списка за константное время.
Когда список пуст, его голова и хвост указывают на 0.
А когда в списке появляется 1й элемент, он одновременно является и головой и хвостом.
Кроме того он одновременно является и первым и посленим элементом списка, причем с обеих сторон.
ВОзможность прохождения по списку в обоих направлениях
теоретически сокращает время доступа к элементу в 2 раза
но делает список тяжелее по сравнению с 1связным в полтора раза.
*/