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
	cout << "Преобразование числа в денежный формат.\n";
		cout << "Введите дробное число-> "; cin >> drobnoe_chislo;
		celoe_chislo = drobnoe_chislo;
		ostatok = (drobnoe_chislo - celoe_chislo)*100;
		cout << drobnoe_chislo << "руб.-это " << celoe_chislo << "руб." << ostatok << "коп.";
#endif
#ifdef Task2
		double cena_tetradi;
		int kolichestvo_tetradey;
		double cena_karandasha;
		int kolichestvo_karandashey;
		double stoimost_pokupki;
		cout << "Вычисление стоимости покупки.\n";
		cout << "Введите цену тетради: "; cin >> cena_tetradi;
		cout << "Введите количество тетрадей: "; cin >> kolichestvo_tetradey;
		cout << "Введите цену карадаша: "; cin >> cena_karandasha;
		cout << "Введите количество карандаша: "; cin >> kolichestvo_karandashey;
		stoimost_pokupki = cena_tetradi * kolichestvo_tetradey + cena_karandasha * kolichestvo_karandashey;
		cout << "Стоимость покупки: " << stoimost_pokupki;
#endif
#ifdef Task3
		double cena_tetradi;
		double cena_oblozhki;
		int kolichestvo_komplectov;
		double stoimost_pokupki;
		cout << "Вычисление стоимости покупки.\n";
		cout << "Введите исходные данные: \n";
		cout << "Цена тетради: "; cin >> cena_tetradi;
		cout << "Цена обложки: "; cin >> cena_oblozhki;
		cout << "Количество комплектов: "; cin >> kolichestvo_komplectov;
		stoimost_pokupki = (cena_tetradi + cena_oblozhki) * kolichestvo_komplectov;
		cout << "Стоимость покупки: " << stoimost_pokupki;

#endif
#ifdef Task4
		int rasstoyanie_do_dachi_km;
		double rashod_benzina_na_100_km;
		double cena_odnogo_litra_benzina;
		double stoimost_poezdki;
		cout << "Вычисление стоимости поездки на дачу и обратно.\n";
		cout << "Расстояние до дачи(км): "; cin >> rasstoyanie_do_dachi_km;
		cout << "Расход бензина(литров на 100 км пробега): "; cin >> rashod_benzina_na_100_km;
		cout << "Цена литра бензина(руб.): "; cin >> cena_odnogo_litra_benzina;
		stoimost_poezdki = rashod_benzina_na_100_km / 100 * cena_odnogo_litra_benzina * rasstoyanie_do_dachi_km;
		cout << "Стоимость поездки на дачу: " << stoimost_poezdki << "руб.";
#endif
}