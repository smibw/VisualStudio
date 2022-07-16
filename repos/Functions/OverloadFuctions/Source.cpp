#include <iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;
#define tab "\t"
#define delimiter "------------------------------------\n"
#define INT
#define FLOAT
#define DOUBLE
#define CHAR
void FillRand(int arr[], const int n);
void FillRand(float arr[], const int n);
void FillRand(double arr[], const int n);
void FillRand(char arr[], const int n);

void Print(int arr[], const int n);
void Print(float arr[], const int n);
void Print(double arr[], const int n);
void Print(char arr[], const int n);

void Sort(int arr[], const int n);
void Sort(float arr[], const int n);
void Sort(double arr[], const int n);
void Sort(char arr[], const int n);

int Sum(int arr[], const int n);
float Sum(float arr[], const int n);
double Sum(double arr[], const int n);
char Sum(char arr[], const int n);

int Avg(int arr[], const int n);
float Avg(float arr[], const int n);
double Avg(double arr[], const int n);
char Avg(char arr[], const int n);

int minValueIn(int arr[], const int n);
float minValueIn(float arr[], const int n);
double minValueIn(double arr[], const int n);
char minValueIn(char arr[], const int n);

int maxValueIn(int arr[], const int n);
float maxValueIn(float arr[], const int n);
double maxValueIn(double arr[], const int n);
char maxValueIn(char arr[], const int n);

void ShiftLeft(int arr[], const int n);
void ShiftLeft(float arr[], const int n);
void ShiftLeft(double arr[], const int n);
void ShiftLeft(char arr[], const int n);

void ShiftRight(int arr[], const int n);
void ShiftRight(float arr[], const int n);
void ShiftRight(double arr[], const int n);
void ShiftRight(char arr[], const int n);

void main()
{
	setlocale(LC_ALL, "");
	const int n = 5;
#ifdef INT
	int arr[n];
	FillRand(arr, n);
	std::cout << delimiter;
	std::cout << tab << "Работа с массивом с int заполнением." << std::endl;
	Print(arr, n);
	std::cout << delimiter;
	std::cout << "Сортируем массив." << std::endl;
	Sort(arr, n);
	std::cout << delimiter;
	Print(arr, n);
	std::cout << delimiter;
	std::cout << "Сумма элементов массива = " << Sum(arr, n) << std::endl;
	std::cout << delimiter;
	std::cout << "Среднее-арифметическое значение массива = " << Avg(arr, n) << std::endl;
	std::cout << delimiter;
	std::cout << "Минимальное значение элемента массива = " << minValueIn(arr, n) << std::endl;
	std::cout << delimiter;
	std::cout << "Максимальное значение элемента массива = " << maxValueIn(arr, n) << std::endl;
	std::cout << delimiter;
	ShiftLeft(arr, n);
	Print(arr, n);
	std::cout << delimiter;
	ShiftRight(arr, n);
	Print(arr, n);
	std::cout << std::endl;
	std::cout << std::endl;
#endif // INT

#ifdef FLOAT

	std::cout << delimiter;
	std::cout << tab << "Работа с массивом с float заполнением." << std::endl;
	float brr[n];
	FillRand(brr, n);
	Print(brr, n);
	std::cout << delimiter;
	std::cout << "Сортируем массив." << std::endl;
	Sort(brr, n);
	std::cout << delimiter;
	Print(brr, n);
	std::cout << delimiter;
	std::cout << "Сумма элементов массива = " << Sum(brr, n) << std::endl;
	std::cout << delimiter;
	std::cout << "Среднее-арифметическое значение массива = " << Avg(brr, n) << std::endl;
	std::cout << delimiter;
	std::cout << "Минимальное значение элемента массива = " << minValueIn(brr, n) << std::endl;
	std::cout << delimiter;
	std::cout << "Максимальное значение элемента массива = " << maxValueIn(brr, n) << std::endl;
	std::cout << delimiter;
	ShiftLeft(brr, n);
	Print(brr, n);
	std::cout << delimiter;
	ShiftRight(brr, n);
	Print(brr, n);
	std::cout << std::endl;
	std::cout << std::endl;
#endif // FLOAT

#ifdef DOUBLE
	std::cout << delimiter;
	std::cout << tab << "Работа с массивом с double заполнением." << std::endl;
	double crr[n];
	FillRand(crr, n);
	Print(crr, n);
	std::cout << delimiter;
	std::cout << "Сортируем массив." << std::endl;
	Sort(crr, n);
	std::cout << delimiter;
	Print(crr, n);
	std::cout << delimiter;
	std::cout << "Сумма элементов массива = " << Sum(crr, n) << std::endl;
	std::cout << delimiter;
	std::cout << "Среднее-арифметическое значение массива = " << Avg(crr, n) << std::endl;
	std::cout << delimiter;
	std::cout << "Минимальное значение элемента массива = " << minValueIn(crr, n) << std::endl;
	std::cout << delimiter;
	std::cout << "Максимальное значение элемента массива = " << maxValueIn(crr, n) << std::endl;
	std::cout << delimiter;
	ShiftLeft(crr, n);
	Print(crr, n);
	std::cout << delimiter;
	ShiftRight(crr, n);
	Print(crr, n);
	std::cout << std::endl;
	std::cout << std::endl;
#endif // DOUBLE

#ifdef CHAR
	std::cout << delimiter;
	std::cout << tab << "Работа с массивом с char заполнением." << std::endl;
	char drr[n];
	FillRand(drr, n);
	Print(drr, n);
	std::cout << delimiter;
	std::cout << "Сортируем массив." << std::endl;
	Sort(drr, n);
	std::cout << delimiter;
	Print(drr, n);
	std::cout << "Сумма элементов массива = " << Sum(drr, n) << std::endl;
	std::cout << delimiter;
	std::cout << "Среднее-арифметическое значение массива = " << Avg(drr, n) << std::endl;
	std::cout << delimiter;
	std::cout << "Минимальное значение элемента массива = " << minValueIn(drr, n) << std::endl;
	std::cout << delimiter;
	std::cout << "Максимальное значение элемента массива = " << maxValueIn(drr, n) << std::endl;
	std::cout << delimiter;
	ShiftLeft(drr, n);
	Print(drr, n);
	std::cout << delimiter;
	ShiftRight(drr, n);
	Print(drr, n);
	std::cout << std::endl;
	std::cout << std::endl;
#endif // CHAR

}
void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand()%100 ;
	}
}
void FillRand(float arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand()%100000;
		arr[i] /= 10000;
	}
}
void FillRand(double arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 10000;
		arr[i] /= 100;
	}
}
void FillRand(char arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i]=rand();
	}
}

void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << tab;
	}
	std::cout << endl;
}
void Print(float arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << tab;
	}
	std::cout << endl;
}
void Print(double arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << tab;
	}
	std::cout << endl;
}
void Print(char arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << tab;
	}
	std::cout << endl;
}

void Sort(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] > arr[j])
			{
				int buffer = arr[i];
				arr[i] = arr[j];
				arr[j] = buffer;
			}

		}
	}
}
void Sort(float arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] > arr[j])
			{
				float buffer = arr[i];
				arr[i] = arr[j];
				arr[j] = buffer;
			}

		}
	}
}
void Sort(double arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] > arr[j])
			{
				double buffer = arr[i];
				arr[i] = arr[j];
				arr[j] = buffer;
			}

		}
	}
}
void Sort(char arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] > arr[j])
			{
				char buffer = arr[i];
				arr[i] = arr[j];
				arr[j] = buffer;
			}

		}
	}
}

int Sum(int arr[], const int n)
{
	int Sum = 0;
	for (int i = 0; i < n; i++)
	{
		Sum	+= arr[i];
	}
	return Sum;
}
float Sum(float arr[], const int n)
{
	float Sum = 0;
	for (int i = 0; i < n; i++)
	{
		Sum	+= arr[i];
	}
	return Sum;
}
double Sum(double arr[], const int n)
{
	double Sum = 0;
	for (int i = 0; i < n; i++)
	{
		Sum	+= arr[i];
	}
	return Sum;
}
char Sum(char arr[], const int n)
{
	char Sum = 0;
	for (int i = 0; i < n; i++)
	{
		Sum	+= arr[i];
	}
	return Sum;
}

int Avg(int arr[], const int n)
{
	return Sum(arr, n) / n;
}
float Avg(float arr[], const int n)
{
	return Sum(arr, n) / n;
}
double Avg(double arr[], const int n)
{
	return Sum(arr, n) / n;
}
char Avg(char arr[], const int n)
{
	return Sum(arr, n) / n;
}

int minValueIn(int arr[], const int n)
{
	int minValueIn = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (minValueIn > arr[i])	minValueIn = arr[i];
	}
	return minValueIn;
}
float minValueIn(float arr[], const int n)
{
	float minValueIn = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (minValueIn > arr[i])	minValueIn = arr[i];
	}
	return minValueIn;
}
double minValueIn(double arr[], const int n)
{
	double minValueIn = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (minValueIn > arr[i])	minValueIn = arr[i];
	}
	return minValueIn;
}
char minValueIn(char arr[], const int n)
{
	char minValueIn = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (minValueIn > arr[i])	minValueIn = arr[i];
	}
	return minValueIn;
}

int maxValueIn(int arr[], const int n)
{
	int maxValueIn = 0;
	for (int i = 0; i < n; i++)
	{
		if (maxValueIn < arr[i]) maxValueIn = arr[i];
	}
	return maxValueIn;
}
float maxValueIn(float arr[], const int n)
{
	float maxValueIn = 0;
	for (int i = 0; i < n; i++)
	{
		if (maxValueIn < arr[i]) maxValueIn = arr[i];
	}
	return maxValueIn;
}
double maxValueIn(double arr[], const int n)
{
	double maxValueIn = 0;
	for (int i = 0; i < n; i++)
	{
		if (maxValueIn < arr[i]) maxValueIn = arr[i];
	}
	return maxValueIn;
}
char maxValueIn(char arr[], const int n)
{
	char maxValueIn = 0;
	for (int i = 0; i < n; i++)
	{
		if (maxValueIn < arr[i]) maxValueIn = arr[i];
	}
	return maxValueIn;
}

void ShiftLeft(int arr[], const int n)
{
	int shift;
	std::cout << "Введите значение смещения: "; std::cin >> shift;
	for (int i = 0; i < shift; i++)
	{
		int buffer=arr[0];
		for (int i = 0; i < n; i++)
		{
			arr[i] = arr[i + 1];
		}
		arr[n - 1] = buffer;
	}
}
void ShiftLeft(float arr[], const int n)
{
	int shift;
	std::cout << "Введите значение смещения: "; std::cin >> shift;
	for (int i = 0; i < shift; i++)
	{
		float buffer=arr[0];
		for (int i = 0; i < n; i++)
		{
			arr[i] = arr[i + 1];
		}
		arr[n - 1] = buffer;
	}
}
void ShiftLeft(double arr[], const int n)
{
	int shift;
	std::cout << "Введите значение смещения: "; std::cin >> shift;
	for (int i = 0; i < shift; i++)
	{
		double buffer=arr[0];
		for (int i = 0; i < n; i++)
		{
			arr[i] = arr[i + 1];
		}
		arr[n - 1] = buffer;
	}
}
void ShiftLeft(char arr[], const int n)
{
	int shift;
	std::cout << "Введите значение смещения: "; std::cin >> shift;
	for (int i = 0; i < shift; i++)
	{
		char buffer=arr[0];
		for (int i = 0; i < n; i++)
		{
			arr[i] = arr[i + 1];
		}
		arr[n - 1] = buffer;
	}
}

void ShiftRight(int arr[], const int n)
{
	int shift;
	std::cout << "Введите значение смещения: "; std::cin >> shift;
	for (int i = 0; i < shift; i++)
	{
		int buffer = arr[n - 1];
		for (int i = n-1; i > 0; i--)
		{
			arr[i] = arr[i - 1];
		}
		arr[0] = buffer;
	}
}
void ShiftRight(float arr[], const int n)
{
	int shift;
	std::cout << "Введите значение смещения: "; std::cin >> shift;
	for (int i = 0; i < shift; i++)
	{
		float buffer = arr[n - 1];
		for (int i = n-1; i > 0; i--)
		{
			arr[i] = arr[i - 1];
		}
		arr[0] = buffer;
	}
}
void ShiftRight(double arr[], const int n)
{
	int shift;
	std::cout << "Введите значение смещения: "; std::cin >> shift;
	for (int i = 0; i < shift; i++)
	{
		double buffer = arr[n - 1];
		for (int i = n-1; i > 0; i--)
		{
			arr[i] = arr[i - 1];
		}
		arr[0] = buffer;
	}
}
void ShiftRight(char arr[], const int n)
{
	int shift;
	std::cout << "Введите значение смещения: "; std::cin >> shift;
	for (int i = 0; i < shift; i++)
	{
		char buffer = arr[n - 1];
		for (int i = n-1; i > 0; i--)
		{
			arr[i] = arr[i - 1];
		}
		arr[0] = buffer;
	}
}