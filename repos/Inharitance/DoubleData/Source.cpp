#include "List.h"
#include"List.cpp"
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