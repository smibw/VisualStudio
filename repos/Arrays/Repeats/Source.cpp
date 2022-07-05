#include <iostream>
#include <ctime>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

//#define NEVER_BEFORE

#define tab "\t"

void main()
{
	setlocale(LC_ALL, "");

	const int n = 10;
	int arr[n] = {};
	int maxrand = 0;
	int minrand = 0;
	srand(time(NULL));
	do
	{
		std::cout << "������� ����������� ��������� �����: "; std::cin >> minrand;
		std::cout << "������� ������������ ��������� �����: "; std::cin >> maxrand;
		if (minrand >= maxrand) std::cout << "Error: �� ����� ����������� ��������, ���������� ��� ���." << endl;
	} while (minrand >= maxrand);
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (maxrand - minrand) + minrand;
	}
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << tab;
	}
	std::cout << endl;
#ifdef NEVER_BEFORE
	for (int i = 0; i < n; i++)
	{
		bool never_before = true; //������������, ��� ������� �������� ����� �� �����������, �� ��� ����� ���������;
		for (int j = 0; j < i; j++)
		{
			if (arr[i] == arr[j])
			{
				never_before = false; break;
			}
		}
		if (never_before)
		{

			int count = 1;
			for (int j = i + 1; j < n; j++)
			{
				if (arr[i] == arr[j])
				{
					count++;
				}
			}
			if (count > 1) std::cout << arr[i] << " ����������� " << count << " ���� " << endl;
		}
	}
#endif // NEVER_BEFORE

	for (int i = 0; i < n; i++)
	{
		bool met_before = false;
		for (int j = 0; j < i; j++)
		{
			if (arr[i] == arr[j])
			{
				met_before = true;
				break;
			}
		}
		if (met_before)continue;
		int count = 1;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] == arr[j]) count++;
		}
		if (count > 1)std::cout << arr[i] << " ����������� " << count << " ���� " << endl;
	}
}