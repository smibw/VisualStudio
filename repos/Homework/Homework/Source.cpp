#include<iostream>
using namespace std;
//#define Task1
//#define Task2
//#define Task3
//#define Task4
void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef Task1
	double drobnoe_chislo;
	int celoe_chislo;
	double ostatok;
	cout << "�������������� ����� � �������� ������.\n";
		cout << "������� ������� �����-> "; cin >> drobnoe_chislo;
		celoe_chislo = drobnoe_chislo;
		ostatok = (drobnoe_chislo - celoe_chislo)*100;
		cout << drobnoe_chislo << "���.-��� " << celoe_chislo << "���." << ostatok << "���.";
#endif
#ifdef Task2
		double cena_tetradi;
		int kolichestvo_tetradey;
		double cena_karandasha;
		int kolichestvo_karandashey;
		double stoimost_pokupki;
		cout << "���������� ��������� �������.\n";
		cout << "������� ���� �������: "; cin >> cena_tetradi;
		cout << "������� ���������� ��������: "; cin >> kolichestvo_tetradey;
		cout << "������� ���� ��������: "; cin >> cena_karandasha;
		cout << "������� ���������� ���������: "; cin >> kolichestvo_karandashey;
		stoimost_pokupki = cena_tetradi * kolichestvo_tetradey + cena_karandasha * kolichestvo_karandashey;
		cout << "��������� �������: " << stoimost_pokupki;
#endif
#ifdef Task3
		double cena_tetradi;
		double cena_oblozhki;
		int kolichestvo_komplectov;
		double stoimost_pokupki;
		cout << "���������� ��������� �������.\n";
		cout << "������� �������� ������: \n";
		cout << "���� �������: "; cin >> cena_tetradi;
		cout << "���� �������: "; cin >> cena_oblozhki;
		cout << "���������� ����������: "; cin >> kolichestvo_komplectov;
		stoimost_pokupki = (cena_tetradi + cena_oblozhki) * kolichestvo_komplectov;
		cout << "��������� �������: " << stoimost_pokupki;

#endif
#ifdef Task4
		int rasstoyanie_do_dachi_km;
		double rashod_benzina_na_100_km;
		double cena_odnogo_litra_benzina;
		double stoimost_poezdki;
		cout << "���������� ��������� ������� �� ���� � �������.\n";
		cout << "���������� �� ����(��): "; cin >> rasstoyanie_do_dachi_km;
		cout << "������ �������(������ �� 100 �� �������): "; cin >> rashod_benzina_na_100_km;
		cout << "���� ����� �������(���.): "; cin >> cena_odnogo_litra_benzina;
		stoimost_poezdki = rashod_benzina_na_100_km / 100 * cena_odnogo_litra_benzina * rasstoyanie_do_dachi_km;
		cout << "��������� ������� �� ����: " << stoimost_poezdki << "���.";
#endif
}