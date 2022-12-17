#pragma warning (disable:4326)
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#define tab "\t"
#define delimiter "\n--------------------------------------\n"
#define DEBUG

class Tree
{
protected:
	class Element
	{
		int Data;		//Значение элемента
		Element *pLeft, *pRight;	//Адреса потомков
	public:
		Element(int Data, Element* pLeft = nullptr, Element* pRight = nullptr) 
			:Data(Data), pLeft(pLeft), pRight(pRight)
		{
#ifdef DEBUG
			std::cout << "EConstructor:\t" << this << std::endl;
#endif // DEBUG
		}
		~Element()
		{
#ifdef DEBUG
			std::cout << "EDestructor:\t" << this << std::endl;
#endif // DEBUG
		}
		bool isLeaf()const
		{
			return pLeft == pRight;
		}
		friend class Tree;
		friend class UniqueTree;
	}*Root;
public:
	Element* getRoot()const
	{
		return Root;
	}
	Tree() :Root(nullptr)
	{
		std::cout << "TConstructor:\t" << this << std::endl;
	}
	Tree(const std::initializer_list<int>& il) :Tree()
	{
		for (int const* it = il.begin(); it != il.end(); ++it)
			insert(*it, Root);
	}
	~Tree()
	{
		clear(Root);
		std::cout << "TDestructor:\t" << this << std::endl;
	}
	void insert(int Data)
	{
		insert(Data, Root);
	}
	void erase(int Data)
	{
		erase(Data, Root);
	}
	void clear()
	{
		clear(Root);
		Root = nullptr;
	}
	int minValue()const
	{
		return minValue(Root);
	}
	int maxValue()const
	{
		return maxValue(Root);
	}
	int Count()const
	{
		return Count(Root);
	}
	int Sum()const
	{
		return Sum(Root);
	}
	double Avg()const
	{
		return (double)Sum(Root) / Count(Root);
	}
	int Depth()const
	{
		return Depth(Root);
	}
	void print()const
	{
		print(Root);
		std::cout << std::endl;
	}
private:
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
	void erase(int Data, Element*& Root)
	{
		if (Root == nullptr)return;
		erase(Data, Root->pLeft);
		erase(Data, Root->pRight);
		if (Data == Root->Data)
		{
			if (Root->isLeaf())
			{
				delete Root;
				Root = nullptr;
			}
			else
			{
				if (Count(Root->pLeft) > Count(Root->pRight))
				{
					Root->Data = maxValue(Root->pLeft);
					erase(maxValue(Root->pLeft), Root->pLeft);
				}
				else
				{
					Root->Data = minValue(Root->pRight);
					erase(minValue(Root->pRight), Root->pRight);
				}
			}
		}
	}
	void clear(Element* Root)
	{
		if (Root == nullptr)return;
		clear(Root->pLeft);
		clear(Root->pRight);
		delete Root;
	}
	int minValue(Element* Root)const
	{
		//if (Root->pLeft == nullptr)return Root->Data;
		//return minValue(Root->pLeft);
		if (Root == nullptr)return 0;
		return Root->pLeft == nullptr ? Root->Data : minValue(Root->pLeft);
	}
	int maxValue(Element* Root)const
	{
		//if (Root->pRight == nullptr)return Root->Data;
		//return maxValue(Root->pRight);
		if (Root == nullptr)return 0;
		return Root->pRight ? maxValue(Root->pRight) : Root->Data;
	}
	int Count(Element* Root)const
	{
		//if (Root == nullptr)return 0;
		//else return count(Root->pLeft) + count(Root->pRight) + 1;
		return !Root ? 0 : Count(Root->pLeft) + Count(Root->pRight) + 1;
	}
	int Sum(Element* Root)const
	{
		//if (Root == nullptr)return 0;
		//else return sum(Root->pLeft) + sum(Root->pRight) + Root->Data;
		return !Root ? 0 : Sum(Root->pLeft) + Sum(Root->pRight) + Root->Data;
	}
	int Depth(Element* Root)const
	{
		if (Root == nullptr)return 0;
		/*
		else if (depth(Root->pLeft) > depth(Root->pRight) )return depth(Root->pLeft) + 1;
		else return depth(Root->pRight) + 1;
		*/
		/*
		return !Root?0:
			depth(Root->pLeft) > depth(Root->pRight) ?
			depth(Root->pLeft) + 1 :
			depth(Root->pRight) + 1;
		*/
		int left_depth = Depth(Root->pLeft) + 1;
		int right_depth = Depth(Root->pRight) + 1;
		return left_depth > right_depth ? left_depth : right_depth;
	}
	void print(Element* Root)const
	{
		if (Root == nullptr)return;
		print(Root->pLeft);
		std::cout << Root->Data << tab;
		print(Root->pRight);
	}
};
class UniqueTree :public Tree
{
	void insert(int Data, Element* Root)
	{
		if (this->Root == nullptr)this->Root = new Element(Data);
		if (Root == nullptr)return;
		if (Data < Root->Data)
		{
			if (Root->pLeft == nullptr)Root->pLeft = new Element(Data);
			else insert(Data, Root->pLeft);
		}
		else if (Data > Root->Data)
		{
			if (Root->pRight == nullptr)Root->pRight = new Element(Data);
			else insert(Data, Root->pRight);
		}
	}
public:
	void insert(int Data)
	{
		insert(Data, Root);
	}
};

#define BASE_CHECK

void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef BASE_CHECK
	int n;
	std::cout << "Введите количество элементов: " << std::endl; std::cin >> n;
	Tree tree;
	for (int i = 0; i < n; i++)
	{
		tree.insert(rand() % 100);
	}
	tree.clear();
	tree.print();
	std::cout << std::endl;
	std::cout << "Минимальное значение бинарного дерева: " << tree.minValue() << std::endl;
	std::cout << "Максимальное значение бинарного дерева: " << tree.maxValue() << std::endl;
	std::cout << "Количество элементов в бинарном дереве: " << tree.Count() << std::endl;
	std::cout << "Сумма всех элементов бинарного дерева: " << tree.Sum() << std::endl;
	std::cout << "Среднее значение в бинарном дереве: " << tree.Avg() << std::endl;
	std::cout << "Глубина бинарного дерева: " << tree.Depth() << std::endl;

	UniqueTree unique_tree;
	for (int i = 0; i < n; i++)
	{
		unique_tree.insert(rand() % 100);
	}
	unique_tree.print();
	std::cout << std::endl;
	std::cout << "Минимальное значение уникального бинарного дерева: " << unique_tree.minValue() << std::endl;
	std::cout << "Максимальное значение уникального бинарного дерева: " << unique_tree.maxValue() << std::endl;
	std::cout << "Количество элементов в уникальном бинарном дереве: " << unique_tree.Count() << std::endl;
	std::cout << "Сумма всех элементов уникального бинарного дерева: " << unique_tree.Sum() << std::endl;
	std::cout << "Среднее значение в уникальном бинарном дереве: " << unique_tree.Avg() << std::endl;
	std::cout << "Глубина уникального бинарного дерева: " << unique_tree.Depth() << std::endl;
#endif // BASE_CHECK

	Tree my_tree = { 50,25,75,16,32,58,85,48,49,64,91 };
	my_tree.print();
	std::cout << std::endl;
	std::cout << "Минимальное значение бинарного дерева: " << my_tree.minValue() << std::endl;
	std::cout << "Максимальное значение бинарного дерева: " << my_tree.maxValue() << std::endl;
	std::cout << "Количество элементов в бинарном дереве: " << my_tree.Count() << std::endl;
	std::cout << "Сумма всех элементов бинарного дерева: " << my_tree.Sum() << std::endl;
	std::cout << "Среднее значение в бинарном дереве: " << my_tree.Avg() << std::endl;
	std::cout << "Глубина данного бинарного дерева: " << my_tree.Depth() << std::endl;

	int value;
	std::cout << "Введите удаляемое значение: " << std::endl;
	std::cin >> value;
	my_tree.erase(value);
	my_tree.print();
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


	Элемент не имеющий потомков называется листом
*/