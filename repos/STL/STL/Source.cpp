#include <iostream>
#include<list>
#include <array>
#include <vector>
using std::cout;
using std::cin;
using std::endl;

#define tab "\t"
#define delimiter "\n------------------------------------------------\n"
//#define STL_ARRAY
//#define MY_EXCEPTION
//#define STL_VECTOR
//#define _EMPTY_AND_PUSHING_VALUES_ONE_BY_ONE_LIST
#define VECTOR_LIST

template<typename T>void print(const std::list<T>& bruh);
template<typename T>void print(const std::vector<T>& vec);

void main()
{
	setlocale(LC_ALL, "Rus");
#ifdef STL_ARRAY
	const int SIZE = 5;
	std::array<int, SIZE> arr={3,5,8,12,21};
	for (int i = 0; i < arr.size(); i++)
	{
		std::cout << arr[i] << tab;
	}
	std::cout << std::endl;
#endif // STL_ARRAY

#ifdef MY_EXCEPTION
	try
	{
		throw std::exception("my test exception");
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
#endif // MY_EXCEPTION

#ifdef STL_VECTOR
	std::vector<int> vec = { 0,1,1,2,3,5,8,13,21,34};
	print(vec);
	vec.push_back(123);
	print(vec);
	vec.resize(13);
	print(vec);
	vec.resize(7);
	vec.shrink_to_fit();		
	print(vec);
	vec.reserve(25);
	print(vec);
	try
	{
	for (int i = 0; i < vec.capacity(); i++)
	{
		std::cout << vec.at(i) << tab;
	}
	std::cout << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		std::cout << *it << tab;
	}
	std::cout << std::endl;
	for (std::vector<int>::reverse_iterator it = vec.rbegin(); it != vec.rend(); ++it)
	{
		std::cout << *it << tab;
	}
	std::cout << std::endl;
	int index, value,number;
	std::cout << "������� ������ ������������ ��������: " << std::endl; std::cin >> index;
	if (index >= vec.size())std::cout << "Out of range" << std::endl;
	std::cout << "������� ���������� ����������� ��������: " << std::endl; std::cin >> number;
	std::cout << "������� �������� ������������ ��������: " << std::endl; std::cin >> value;

	vec.insert(vec.begin() + index, number,value);
	print(vec);
#endif // STL_VECTOR
#ifdef _EMPTY_AND_PUSHING_VALUES_ONE_BY_ONE_LIST
	std::list<int> bruh;
	bruh.push_back(5);
	bruh.push_back(10);
	bruh.push_back(15);
	for (int x : bruh)
		std::cout << x << tab;
#endif // _EMPTY_AND_PUSHING_VALUES_ONE_BY_ONE_LIST

#ifdef VECTOR_LIST
	std::vector<int> forward = {};
	int number,index=0;
	const int ask = 0;
	std::cout << "��� ����������� ������ �������� � ���� �������: 0" << std::endl;;
	do
	{
			std::cout << "������� ����� ��������: "; std::cin >> number;
			if (number == 0)
			{
				break;
			}
			forward.push_back(number);
		
		 
	} while (ask != number);
	print(forward);
	std::list<int> bruh(forward.begin(), forward.end());
	print(bruh);
	std::cout << "������� ����� ��� ��������: "; std::cin >> number;
	bruh.remove(number);
	print(bruh);
	std::cout << "������� ������ �������� ��� ����������:"; std::cin >> index;
	std::cout << "������� �������� ��� ����������:"; std::cin >> number;
	//bruh.insert(it,index, number);
	print(bruh);
#endif // VECTOR_LIST

}
template<typename T>void print(const std::list<T>& bruh)
{
	for (int i : bruh)
		std::cout << i << tab;
	std::cout << std::endl;
	std::cout << "Size: " << bruh.size() << std::endl;
	std::cout << "Max Size: " << bruh.max_size() << std::endl;
}
template<typename T>void print(const std::vector<T>& vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << tab;
	}
	std::cout << std::endl;
	std::cout << "Size: " << vec.size() << std::endl;
	std::cout << "Max size: " << vec.max_size() << std::endl;
	std::cout << "Capacity: " << vec.capacity() << std::endl;
}
/*
Standart Template Library- ����������� ��������� ����������
��� ����� �����������, ����������, ����������,�������������� ��������,������������ � �����������,
��������������� ��� �������� � ������ � �������.
��� �������� STL �������� ����������, ��� ���� ����������� �������� � ������� ��������� ����� �����.
�������� �������� STL �������� ��������� - ��� ������, ������� ���������� �������� ������ �������� � ������.
� ������� ���������� ���� ���� ����� ����������, ������� ������� �� ����, 
����� ��������� ������ ���������� ���� ���������.
��������� STL ��������� ����� �������, ��� ����� �������� � ������ ������������.
���������� ������: 
1.����������������(Sequence containers) : array,vector,deque,list,forward_list.
2.�������������(Associatove containers): map, multimap, set, multiset.
3.����������-��������(Adaptors):stack, queue, priority_queue;
4.��������������� ������������� ����������(Unordered associative containers):unordered_map,unordered_set,
unordered_multimap,unordered_multiset.

������ ��������� �������� � ����������� ������������ �����.

���������������� ���������� ��� sequence containers
array-���������, ������� ������ ������ � ���� ������������ �������.
vector - ��� ���������, ������� ������ ������ � ���� ������������� �������.
� ������� ���� ���������������(capacity), ������� ����������, ������� ��������� ����� ���������
� ������ ��� ��������������� ������. 
capacity-size=���������� ���������, ������ ����� ���� ��������� � ������ ��� ��������������� ������.
���� ��� ���������� �������� capacity==size, �� ��������� ��������������� ������
� ������ ������� � ������� ���� ������ ������, ��� ��� ����������� ������.
� ��� ��� ������������ ����� ���������������� ��� ����������� �������� ���������� ���������,
�� ���������� ��������������� ������.
resize() ������������� ������ ������ ������� ��� � ������� ��� � � ������� �������.
shrink_to_fit() ������� ��������������� ������� �� ������������ �������.
reserve() ��������� ��������� ���������������(capacity), �� ������ � ������� �������.
*/