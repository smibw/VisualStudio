#include <iostream>
#include <set>
#include <list>
#include<map>
using std::cout;
using std::cin;
using std::endl;

#define tab "\t"
#define delimiter "\n-------------------------------\n"

//#define STL_SET
//#define STL_MAP
#define DICTIONARY

void main()
{
	setlocale(LC_ALL, "Rus");
#ifdef STL_SET
	std::set<int> set = { 50,25,75,16,32,64,128,86,32,64,50,8,8,8 };
	for (std::set<int>::iterator it = set.begin(); it != set.end(); ++it)
	{
		std::cout << *it << tab;
	}
	std::cout << std::endl;
	int value;
	std::cout << "¬ведите добавл€емое значение: "; std::cin >> value;
	set.insert(value);
	for (int i : set)std::cout << i << tab; std::cout << std::endl;
	std::set<int>::iterator position = set.find(75);
	set.insert(position, 1024);
	for (int i : set) std::cout << i << tab; std::cout << std::endl;
	for (std::set<int>::iterator it = set.lower_bound(20); it != set.upper_bound(80); ++it)
	{
		std::cout << *it << tab;
	}
	std::cout << std::endl;
#endif // STL_SET

#ifdef STL_MAP
	std::map<int, std::string>week =
	{
		std::pair<int,std::string>(0,"Sunday"),
		std::pair<int,std::string>(1,"Monday"),
		std::pair<int,std::string>(2,"Tuesday"),
		{3,"Wednesday"},
		{4,"Thursday"},
		{5,"Friday"},
		{6,"Saturday"},
		{7,"Sunday"},
		{0,"Monday"}
	};
	for (std::map<int, std::string>::iterator it = week.begin(); it != week.end(); ++it)
	{
		std::cout << it->first << tab << it->second << std::endl;
	}
#endif // STL_MAP

#ifdef DICTIONARY
	std::map<std::string, std::list<std::string>> dictionary =
	{
		std::pair<std::string, std::list<std::string>>("squad",{"группа","команда","отделение"}),
		std::pair<std::string, std::list<std::string>>("flock",{"клок","пучок"}),
		{"plural",{"множественный", "бесчисленный", "многочисленный"}},
		{"space",{"космос","пробел","пространство"}}
	};
	for (std::map<std::string, std::list<std::string>>::iterator it = dictionary.begin(); it != dictionary.end(); ++it)
	{
		std::cout << it->first << ":\t";
		for (std::list<std::string>::iterator jt = it->second.begin(); jt != it->second.end(); ++jt)
		{
			std::cout << *jt << ", ";
		}
		std::cout << "\b\b;";
		std::cout << std::endl;
	}
	std::cout << delimiter;
	for (std::pair<std::string, std::list<std::string>> i : dictionary)
	{
		std::cout << i.first << ":\t";
		for (std::string j : i.second)
		{
			std::cout << j << ", ";
		}
		std::cout << "\b\b;";
		std::cout << std::endl;
	}
#endif // DICTIONARY

};
/*
	¬се ассоциативные контейнеры хран€т информацию в виде бинарного дерева
	это хорошо видно по тому, что они все отсортированы.
	multiset способен хранить повтор€ющиес€ элементы, а set только уникальные.
	map - это контейнер, каждый элемент которого содержит "пару"-"ключ-значение"("key-value"),
	которые могут быть как одного так и разных типов
	ключи €вл€ютс€ уникальными, то есть в контейнере не может быть двух контейнеров с одинаковым ключом.
	сортировка элементов производитс€ по ключу
	multimap позвол€ет повтор€ть ключи.
*/