#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#define tab "\t"
#define delimiter "\n--------------------------------------\n"

class Tree
{
	class Element
	{
		int Data;		//Значение элемента
		Element* pLeft;	//Адреса потомков
		Element* pRight;
	public:
		Element(int Data, Element* pLeft = nullptr, Element* pRight = nullptr) : Data(Data), pLeft(pLeft), pRight(pRight)
		{
			std::cout << "EConstructor:\t" << this << std::endl;
		}
		~Element()
		{
			std::cout << "EDestructor:\t" << this << std::endl;
		}
		friend class Tree;
	}*Root;
public:
	 Element* getRoot()const
	{
		return Root;
	}
	Tree():Root(nullptr)
	{
		std::cout << "TConstructor:\t" << this << std::endl;
	}
	~Tree()
	{
		std::cout << "TDestructor:\t" << this << std::endl;
	}

	//		Methods:
	void insert(int Data, Element* Root)
	{
		if (this->Root == nullptr)this->Root = new Element(Data);
		if (Root == nullptr)return;
		if (Data < Root->Data)
		{
			if (Root->pLeft == nullptr)Root->pLeft = new Element(Data);
			else insert(Data, Root->pLeft);
		}
		else
		{
			if (Root->pRight == nullptr)Root->pRight = new Element(Data);
			else insert(Data, Root->pRight);
		}
	}
	void print(Element* Root)const
	{
		if (Root == nullptr)return;
		print(Root->pLeft);
		std::cout << Root->Data << tab;
		print(Root->pRight);
	}
};

void main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	std::cout << "Введите количество элементов: " << std::endl; std::cin >> n;
	Tree tree;
	for (int i = 0; i < n; i++)
	{
		tree.insert(rand() % 100,tree.getRoot());
	}
	tree.print(tree.getRoot());
	std::cout<<std::endl;
}
/*
	Бинарное дерево-набор элементов в произвольных областях памяти, каждый из которых имеет 2 потомка
	левый и правый. Левый потомок обычно имеет значение меньше текущего элемента,
	а правый больше текущего элемента. Такое дерево называется бинарным деревом поиска.
	Кроме бинарного дерева поиска существуует также карсно-черное дерево.
	Как и любого другого дерева у бинарного дерева есть корень,
	который содержит адрес начального элемента дерева.
	И если дерево пустое, то его корень указывает на 0.
						   50				depth 0
				    25		      75		depth 1
				13      32    58       85	depth 2
				//perfect binary tree
	Таким деревом называет дерево у которого у правой и левой ветки одинаковое количество узлов
	и у каждого узла на заданной глубине в левой и правой ветке одинаковое количество потомков.
	depth 0=2^0;
	depth 1=2^1;
	depth 2=2^2;
	depth 3=2^3;
	etc.
	То есть количество веток=2^глубины.
	кроме идеально сбалансированного дерева существует также вырожденное дерево
						3
							5	
								8
						//Degenerate tree(Pathological tree)
	Вырожденное бинарное дерево по своим свойствам напоминает односвязный список
	то есть у него такой же медленный доступ к элементам как и у 1связного спика
	в то время как, в идеально сбалансированном идеальном дереве из тысячи элементов
	нужный элемент можно найти на 10 итераций.
	Существует 2 проблемы: рекурсивная и итерационная
	В итерационной реализации каждый элемент кроме адресов потомков также должен хранить адрес родителя.
	В рекурсивной реализации такой необходимости нет поскольку адрес родительского элемента
	и так сохраняется в стеке, во время рекурсивного вызова.
	Мы будем реализовывать бинарное дерево рекурсивно
*/