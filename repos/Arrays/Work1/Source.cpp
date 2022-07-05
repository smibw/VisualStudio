#include <iostream>
#include<windows.h>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

#define VIVOD_MASSIVA
#define SDVIG_MASSIVA
#define VIVOD_SDVINUTOGO_MASSIVA

void main()
{
	setlocale(LC_ALL, "");
	int const n = 10;
	int arr[n] = { 1,2,3,4,5,6,7,8,9,10 };
#ifdef VIVOD_MASSIVA
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << "\t";
	}
	std::cout << endl;
#endif // VIVOD_MASSIVA
#ifdef SDVIG_MASSIVA
	int shift;
	std::cout << "¬ведите значение сдвига: "; std::cin >> shift;
	for (int i = 0; i < shift; i++)
	{
	int buffer = arr[0];
	for (int i = 0; i < n; i++)
	{
		arr[i] = arr[i + 1];
	}
	arr[n - 1] = buffer;
	}
#endif // SDVIG_MASSIVA

#ifdef VIVOD_SDVINUTOGO_MASSIVA
	system("CLS"); //clear screen

	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << "\t";
	}
	std::cout << endl;
	Sleep(400); //delay

#endif // VIVOD_SDVINUTOGO_MASSIVA
}