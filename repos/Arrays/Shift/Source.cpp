//Shift
#include <iostream>
#include <windows.h>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

#define tab "\t"
#define VIVOD_MASSIVA
#define SDVIG_MASSIVA
#define VIVOD_SDVINUTOGO_MASSIVA

//#define LEFT_SHIFT
//#define RIGHT_SHIFT
#define UNIQUE_RANDOM

int main()
{
	setlocale(LC_ALL, "");

#ifdef LEFT_SHIFT
	int sdvig = 0;
	int buffer = 0;
	int const n = 10;
	int arr[n] = { 1,2,3,4,5,6,7,8,9,10 };
	setlocale(LC_ALL, "");
#ifdef VIVOD_MASSIVA
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << "\t";
	}
	std::cout << endl;
#endif // VIVOD_MASSIVA

#ifdef SDVIG_MASSIVA
	std::cout << "¬ведите значение сдвига: "; std::cin >> sdvig;
	for (int i = 0; i < sdvig; i++)
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
	//system("CLS"); //clear screen
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << "\t";
	}
	std::cout << endl;
#endif //VIVOD_SDVINUTOGO_MASSIVA  
#endif // LEFT_SHIFT

#ifdef RIGHT_SHIFT
	const int n = 10;
	int sdvig = 0;
	int buffer = 0;
	int buffer_2 = 0;
	int arr[n] = { 1,2,3,4,5,6,7,8,9,10 };

#ifdef VIVOD_MASSIVA
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << tab;
	}
	std::cout << endl;
#endif // VIVOD_MASSIVA

#ifdef SDVIG_MASSIVA
	std::cout << "¬ведите значение сдвига массива: "; std::cin >> sdvig;
		for(int i=0;i<sdvig;i++)
		{
			buffer = arr[9];
			for (int i = 9 ; i > 0; i--)
			{
			arr[i] = arr[i -1];
			}
			arr[0] = buffer;
		}
#endif // SDVIG_MASSIVA

#ifdef VIVOD_SDVINUTOGO_MASSIVA
		for (int i = 0; i < n; i++)
		{
			std::cout << arr[i] << tab;
		}
		std::cout << endl;
#endif // VIVOD_SDVINUTOGO_MASSIVA

#endif //RIGHT_SHIFT

#ifdef UNIQUE_RANDOM
		const int n = 10;
		int arr[n];

		for (int i = 0; i < n; i++)
		{
			bool unique;
			do
			{
				arr[i] = rand() % n;
				unique = true;
				for (int j = 0; j < i; j++)
				{
					if (arr[i] == arr[j])
					{
						unique = false;
						break;
					}

				}
			} while (!unique);
		}

		for (int i = 0; i < n; i++)
		{
			std::cout << arr[i] << tab;
		}
#endif //UNIQUE_RANDOM
}