#include <iostream>
#include<conio.h>
using namespace std;
//#define TASK_1
#define TASK_2
//#define TASK_3

void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef TASK_1
	unsigned int chislo;
	int edinica;
	int desyatki;
	int sotni;
	int tisyachi;
	int desyatki_tisyach;
	int sotni_tisyach;
	int million;
	int counter;
	const int sravnenie = 0;
	int startovoe_znachenie;
	int i;
	cout << "��������� ������������ �������� ����� �� ������� ��������� ����������� ��� ���.\n";
	do
	{
		cout << "������� ����� � ����������: "; cin >> chislo;
		startovoe_znachenie = chislo;
		counter = 1000000;
		million = chislo / counter;
		chislo -= million * counter;
		sotni_tisyach = chislo / (counter / 10);
		chislo -= sotni_tisyach * (counter / 10);
		desyatki_tisyach = chislo / (counter / 100);
		chislo -= desyatki_tisyach * (counter / 100);
		tisyachi = chislo / (counter / 1000);
		chislo -= tisyachi * (counter / 1000);
		sotni = chislo / (counter / 10000);
		chislo -= sotni * (counter / 10000);
		desyatki = chislo / (counter / 100000);
		chislo -= desyatki * (counter / 100000);
		edinica = chislo;
		if (sravnenie < million)  chislo = edinica * 1000000 + desyatki * 100000 + sotni * 10000 + tisyachi * 1000 + desyatki_tisyach * 100 + sotni_tisyach * 10 + million;
		else if (sravnenie < sotni_tisyach) chislo = edinica * 100000 + desyatki * 10000 + sotni * 1000 + tisyachi * 100 + desyatki_tisyach * 10 + sotni_tisyach;
		else if (sravnenie < desyatki_tisyach) chislo = edinica * 10000 + desyatki * 1000 + sotni * 100 + tisyachi * 10 + desyatki_tisyach;
		else if (sravnenie < tisyachi) chislo = edinica * 1000 + desyatki * 100 + sotni * 10 + tisyachi;
		else if (sravnenie < sotni) chislo = edinica * 100 + desyatki * 10 + sotni;
		else if (sravnenie < desyatki) chislo = edinica * 10 + desyatki;
		else cout << "�� ����� ����� ������ 10, ��� �� ����� ���� �����������\n";
		cout << startovoe_znachenie << "=" << chislo << endl;
		if (startovoe_znachenie == chislo) cout << "������ ����� �������� �����������.\n";
		else cout << "������ ����� ����������� �� ��������.\n";
		cout << "�� ������ ���������? ������� 0\n"; cin >> i;
	} while (i==0);
#endif // TASK_1
#ifdef TASK_2
	unsigned int chislo;
	int edinica;
	int desyatki;
	int sotni;
	int tisyachi;
	int desyatki_tisyach;
	int sotni_tisyach;
	int counter;
	int i;
	int utility;
	const int sravnenie = 0;
	int startovoe_znachenie;
	int summ_1;
	int summ_2;
	cout << "��������� ������������ �������� �� ����� ���������� ��� ���.\n";
	do {
		cout << "������� ����� ������ � ����������: "; cin >> chislo; cout << endl;
		startovoe_znachenie = chislo;
		counter = 100000;
		sotni_tisyach = chislo / counter;
		chislo -= sotni_tisyach * counter;
		desyatki_tisyach = chislo / (counter / 10);
		chislo -= desyatki_tisyach * (counter / 10);
		tisyachi = chislo / (counter / 100);
		chislo -= tisyachi * (counter / 100);
		sotni = chislo / (counter / 1000);
		chislo -= sotni * (counter / 1000);
		desyatki = chislo / (counter / 10000);
		chislo -= desyatki * (counter / 10000);
		edinica = chislo;
		summ_1 = edinica + desyatki + sotni;
		summ_2 = tisyachi + desyatki_tisyach + sotni_tisyach;
		if (summ_1 == summ_2) cout << "��� ����� " << startovoe_znachenie << " �������� ����������!\n";
		else cout << "��� ����� " << startovoe_znachenie << " �������� �������.\n";
		cout << "�� ������ ���������? ������� 0\n"; cin >> utility;
	} while (utility==0);
#endif //TASK_2
#ifdef TASK_3
	int i;
	char brukva;
	i = 0;
	cout << "\t\t\t3Dshooter\n";
	cout << "������� �������� � ����������: \n";
		for (i; i != 50; i++)
		{
			brukva = _getch();
			switch (brukva)
			{
			case (119): cout << "�� ��������� ������.\n"; break;
			case(97): cout << "�� ��������� �����.\n"; break;
			case(115): cout << "�� ��������� �����.\n"; break;
			case(100): cout << "�� ��������� ������.\n"; break;
			case(32):cout << "�� ��������.\n"; break;
			case(13):cout << "�� ���������\n"; break;
			case(114):cout << "�� ���������������.\n"; break;
			case(101):cout << "�� ���������� ����������� �������.\n"; break;
			default:cout << "��� �� ������ �������?\n"; break;
			}
		}
	cout << "�� ��������� � ������ �� ����� �����\n ";
	cout << "\t\t\t\t\t\t\t�� ������� \n";
#endif //TASK_3
}