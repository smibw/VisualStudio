#include <iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;
#define tab "\t"
#define delimiter "------------------------------------\n"
#define INT
//#define FLOAT
//#define DOUBLE
//#define CHAR
//#define INT2D
//#define FLOAT2D
//#define DOUBLE2D
//#define CHAR2D
const int x = 3;
const int y = 4;
void FillRand(int arr[], const int n);
void FillRand(float arr[], const int n);
void FillRand(double arr[], const int n);
void FillRand(char arr[], const int n);
void FillRand(int arr[x][y], const int x, const int y);
void FillRand(float arr[x][y], const int x, const int y);
void FillRand(double arr[x][y], const int x, const int y);
void FillRand(char arr[x][y], const int x, const int y);

void Print(int arr[], const int n);
void Print(float arr[], const int n);
void Print(double arr[], const int n);
void Print(char arr[], const int n);
void Print(int arr[x][y], const int x, const int y);
void Print(float arr[x][y], const int x, const int y);
void Print(double arr[x][y], const int x, const int y);
void Print(char arr[x][y], const int x, const int y);

void Sort(int arr[], const int n);
void Sort(float arr[], const int n);
void Sort(double arr[], const int n);
void Sort(char arr[], const int n);
//У меня пока не получилось отсортировать двумерные массивы.

int Sum(int arr[], const int n);
float Sum(float arr[], const int n);
double Sum(double arr[], const int n);
char Sum(char arr[], const int n);
int Sum(int arr[x][y], const int x,const int y);
float Sum(float arr[x][y], const int x,const int y);
double Sum(double arr[x][y], const int x,const int y);
char Sum(char arr[x][y], const int x,const int y);

int Avg(int arr[], const int n);
float Avg(float arr[], const int n);
double Avg(double arr[], const int n);
char Avg(char arr[], const int n);
int Avg(int arr[x][y], const int x, const int y);
float Avg(float arr[x][y], const int x, const int y);
double Avg(double arr[x][y], const int x, const int y);
char Avg(char arr[x][y], const int x, const int y);

int minValueIn(int arr[], const int n);
float minValueIn(float arr[], const int n);
double minValueIn(double arr[], const int n);
char minValueIn(char arr[], const int n);
int minValueIn(int arr[x][y], const int x,const int y);
float minValueIn(float arr[x][y], const int x,const int y);
double minValueIn(double arr[x][y], const int x,const int y);
char minValueIn(char arr[x][y], const int x,const int y);

int maxValueIn(int arr[], const int n);
float maxValueIn(float arr[], const int n);
double maxValueIn(double arr[], const int n);
char maxValueIn(char arr[], const int n);
int maxValueIn(int arr[x][y], const int x,const int y);
float maxValueIn(float arr[x][y], const int x,const int y);
double maxValueIn(double arr[x][y], const int x,const int y);
char maxValueIn(char arr[x][y], const int x,const int y);

void ShiftLeft(int arr[], const int n);
void ShiftLeft(float arr[], const int n);
void ShiftLeft(double arr[], const int n);
void ShiftLeft(char arr[], const int n);
void ShiftLeft(int arr[x][y], const int x,const int y);
void ShiftLeft(float arr[x][y], const int x,const int y);
void ShiftLeft(double arr[x][y], const int x,const int y);
void ShiftLeft(char arr[x][y], const int x,const int y);

void ShiftRight(int arr[], const int n);
void ShiftRight(float arr[], const int n);
void ShiftRight(double arr[], const int n);
void ShiftRight(char arr[], const int n);
void ShiftRight(int arr[x][y], const int x,const int y);
void ShiftRight(float arr[x][y], const int x,const int y);
void ShiftRight(double arr[x][y], const int x,const int y);
void ShiftRight(char arr[x][y], const int x,const int y);

void main()
{
	setlocale(LC_ALL, "");
	const int n = 5;
#ifdef INT
	int arr[n];
	FillRand(arr, n);
	std::cout << delimiter;
	std::cout  << "Работа с массивом с int заполнением." << std::endl;
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
	std::cout  << "Работа с массивом с float заполнением." << std::endl;
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
	std::cout  << "Работа с массивом с double заполнением." << std::endl;
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
	std::cout << "Работа с массивом с char заполнением." << std::endl;
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

#ifdef INT2D
	int arr_2[x][y]{};
	FillRand(arr_2, x, y);
	std::cout << delimiter;
	std::cout << "Работа с двумерным массивом с int заполнением." << std::endl;
	std::cout << delimiter;
	Print(arr_2, x, y);
	std::cout << delimiter;
	std::cout << "Сумма элементов массива = " << Sum(arr_2, x, y) << std::endl;
	std::cout << delimiter;
	std::cout << "Среднее-арифметическое значение массива = " << Avg(arr_2, x, y) << std::endl;
	std::cout << delimiter;
	std::cout << "Минимальное значение элемента массива = " << minValueIn(arr_2, x, y) << std::endl;
	std::cout << delimiter;
	std::cout << "Максимальное значение элемента массива = " << maxValueIn(arr_2, x, y) << std::endl;
	std::cout << delimiter;
	ShiftLeft(arr_2, x, y);
	Print(arr_2, x, y);
	std::cout << delimiter;
	ShiftRight(arr_2, x, y);
	Print(arr_2, x, y);
	std::cout << std::endl;
	std::cout << std::endl;
#endif // INT2D

#ifdef FLOAT2D
	float brr_2[x][y]{};
	FillRand(brr_2, x, y);
	std::cout << delimiter;
	std::cout << "Работа с двумерным массивом с float заполнением." << std::endl;
	std::cout << delimiter;
	Print(brr_2, x, y);
	std::cout << delimiter;
	std::cout << "Сумма элементов массива = " << Sum(brr_2, x, y) << std::endl;
	std::cout << delimiter;
	std::cout << "Среднее-арифметическое значение массива = " << Avg(brr_2, x, y) << std::endl;
	std::cout << delimiter;
	std::cout << "Минимальное значение элемента массива = " << minValueIn(brr_2, x, y) << std::endl;
	std::cout << delimiter;
	std::cout << "Максимальное значение элемента массива = " << maxValueIn(brr_2, x, y) << std::endl;
	std::cout << delimiter;
	ShiftLeft(brr_2, x, y);
	Print(brr_2, x, y);
	std::cout << delimiter;
	ShiftRight(brr_2, x, y);
	Print(brr_2, x, y);
	std::cout << std::endl;
	std::cout << std::endl;
#endif // FLOAT2D

#ifdef DOUBLE2D
	double crr_2[x][y]{};
	FillRand(crr_2, x, y);
	std::cout << delimiter;
	std::cout << "Работа с двумерным массивом с double заполнением." << std::endl;
	std::cout << delimiter;
	Print(crr_2, x, y);
	std::cout << delimiter;
	std::cout << "Сумма элементов массива = " << Sum(crr_2, x, y) << std::endl;
	std::cout << delimiter;
	std::cout << "Среднее-арифметическое значение массива = " << Avg(crr_2, x, y) << std::endl;
	std::cout << delimiter;
	std::cout << "Минимальное значение элемента массива = " << minValueIn(crr_2, x, y) << std::endl;
	std::cout << delimiter;
	std::cout << "Максимальное значение элемента массива = " << maxValueIn(crr_2, x, y) << std::endl;
	std::cout << delimiter;
	ShiftLeft(crr_2, x, y);
	Print(crr_2, x, y);
	std::cout << delimiter;
	ShiftRight(crr_2, x, y);
	Print(crr_2, x, y);
	std::cout << std::endl;
	std::cout << std::endl;
#endif // DOUBLE2D

#ifdef CHAR2D
	char drr_2[x][y];
	FillRand(drr_2, x, y);
	std::cout << delimiter;
	std::cout << "Работа с двумерным массивом с char заполнением." << std::endl;
	std::cout << delimiter;
	Print(drr_2, x, y);
	std::cout << delimiter;
	std::cout << "Сумма элементов массива = " << Sum(drr_2, x, y) << std::endl;
	std::cout << delimiter;
	std::cout << "Среднее-арифметическое значение массива = " << Avg(drr_2, x, y) << std::endl;
	std::cout << delimiter;
	std::cout << "Минимальное значение элемента массива = " << minValueIn(drr_2, x, y) << std::endl;
	std::cout << delimiter;
	std::cout << "Максимальное значение элемента массива = " << maxValueIn(drr_2, x, y) << std::endl;
	std::cout << delimiter;
	ShiftLeft(drr_2, x, y);
	Print(drr_2, x, y);
	std::cout << delimiter;
	ShiftRight(drr_2, x, y);
	Print(drr_2, x, y);
	std::cout << std::endl;
	std::cout << std::endl;
#endif // CHAR2D

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
void FillRand(int arr[x][y], const int x, const int y)
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			arr[i][j] = rand();
		}
	}
}
void FillRand(float arr[x][y], const int x, const int y)
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			arr[i][j] = rand()%100000;
			arr[i][j] /= 10000;
		}
	}
}
void FillRand(double arr[x][y], const int x, const int y)
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			arr[i][j] = rand()%10000;
			arr[i][j] /= 100;
		}
	}
}
void FillRand(char arr[x][y], const int x, const int y)
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			arr[i][j] = rand();
		}
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
void Print(int arr[x][y], const int x, const int y)
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			std::cout << arr[i][j] << tab;
		}
		std::cout << std::endl;
	}
}
void Print(float arr[x][y], const int x, const int y)
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			std::cout << arr[i][j] << tab;
		}
		std::cout << std::endl;
	}
}
void Print(double arr[x][y], const int x, const int y)
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			std::cout << arr[i][j] << tab;
		}
		std::cout << std::endl;
	}
}
void Print(char arr[x][y], const int x, const int y)
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			std::cout << arr[i][j] << tab;
		}
		std::cout << std::endl;
	}
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
int Sum(int arr[x][y], const int x, const int y)
{
	int Sum = 0;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			Sum += arr[i][j];
		}
	}
	return Sum;
}
float Sum(float arr[x][y], const int x, const int y)
{
	float Sum = 0;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			Sum += arr[i][j];
		}
	}
	return Sum;
}
double Sum(double arr[x][y], const int x, const int y)
{
	double Sum = 0;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			Sum += arr[i][j];
		}
	}
	return Sum;
}
char Sum(char arr[x][y], const int x, const int y)
{
	char Sum = 0;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			Sum += arr[i][j];
		}
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
int Avg(int arr[x][y], const int x, const int y)
{
	return Sum(arr, x, y) / (x * y);
}
float Avg(float arr[x][y], const int x, const int y)
{
	return Sum(arr, x, y) / (x * y);
}
double Avg(double arr[x][y], const int x, const int y)
{
	return Sum(arr, x, y) / (x * y);
}
char Avg(char arr[x][y], const int x, const int y)
{
	return Sum(arr, x, y) / (x * y);
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
int minValueIn(int arr[x][y], const int x, const int y)
{
	int minValueIn = arr[0][0];
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			if (minValueIn > arr[i][j])	minValueIn = arr[i][j];
		}
	}
	return minValueIn;
}
float minValueIn(float arr[x][y], const int x, const int y)
{
	float minValueIn = arr[0][0];
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			if (minValueIn > arr[i][j])	minValueIn = arr[i][j];
		}
	}
	return minValueIn;
}
double minValueIn(double arr[x][y], const int x, const int y)
{
	double minValueIn = arr[0][0];
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			if (minValueIn > arr[i][j])	minValueIn = arr[i][j];
		}
	}
	return minValueIn;
}
char minValueIn(char arr[x][y], const int x, const int y)
{
	char minValueIn = arr[0][0];
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			if (minValueIn > arr[i][j])	minValueIn = arr[i][j];
		}
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
int maxValueIn(int arr[x][y], const int x, const int y)
{
	int maxValueIn = 0;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			if (maxValueIn < arr[i][j])	maxValueIn = arr[i][j];
		}
	}
	return maxValueIn;
}
float maxValueIn(float arr[x][y], const int x, const int y)
{
	float maxValueIn = 0;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			if (maxValueIn < arr[i][j])	maxValueIn = arr[i][j];
		}
	}
	return maxValueIn;
}
double maxValueIn(double arr[x][y], const int x, const int y)
{
	double maxValueIn = 0;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			if (maxValueIn < arr[i][j])	maxValueIn = arr[i][j];
		}
	}
	return maxValueIn;
}
char maxValueIn(char arr[x][y], const int x, const int y)
{
	char maxValueIn = 0;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			if (maxValueIn < arr[i][j])	maxValueIn = arr[i][j];
		}
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
void ShiftLeft(int arr[x][y], const int x, const int y)
{
	int shift;
	std::cout << "Введите значение смещения: "; std::cin >> shift;
	for (int i = 0; i < shift; i++)
	{
		int buffer = arr[0][0];
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
			arr[i][j] = arr[i][j+1];
			}
		}
		arr[x - 1][y-1] = buffer;
	}
}
void ShiftLeft(float arr[x][y], const int x, const int y)
{
	int shift;
	std::cout << "Введите значение смещения: "; std::cin >> shift;
	for (int i = 0; i < shift; i++)
	{
		float buffer = arr[0][0];
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
			arr[i][j] = arr[i][j+1];
			}
		}
		arr[x - 1][y-1] = buffer;
	}
}
void ShiftLeft(double arr[x][y], const int x, const int y)
{
	int shift;
	std::cout << "Введите значение смещения: "; std::cin >> shift;
	for (int i = 0; i < shift; i++)
	{
		double buffer = arr[0][0];
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
			arr[i][j] = arr[i][j+1];
			}
		}
		arr[x - 1][y-1] = buffer;
	}
}
void ShiftLeft(char arr[x][y], const int x, const int y)
{
	int shift;
	std::cout << "Введите значение смещения: "; std::cin >> shift;
	for (int i = 0; i < shift; i++)
	{
		char buffer = arr[0][0];
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
			arr[i][j] = arr[i][j+1];
			}
		}
		arr[x - 1][y-1] = buffer;
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
void ShiftRight(int arr[x][y], const int x, const int y)
{
	int shift;
	std::cout << "Введите значение смещения: "; std::cin >> shift;
	for (int i = 0; i < shift; i++)
	{
		int buffer = arr[x - 1][y-1];
		int buffer_2 = arr[x - 2][y-1];
		int buffer_3 = arr[x - 3][y-1];
	
		for (int i = x - 1; i >= 0; i--)
		{
			for (int j = y - 1; j > 0; j--)
			{
			arr[i][j] = arr[i][j-1];
			}
		}
		arr[0][0] = buffer;
		arr[2][0] = buffer_2;
		arr[1][0] = buffer_3;
	}
}
void ShiftRight(float arr[x][y], const int x, const int y)
{
	int shift;
	std::cout << "Введите значение смещения: "; std::cin >> shift;
	for (int i = 0; i < shift; i++)
	{
		float buffer = arr[x - 1][y-1];
		float buffer_2 = arr[x - 2][y-1];
		float buffer_3 = arr[x - 3][y-1];
	
		for (int i = x - 1; i >= 0; i--)
		{
			for (int j = y - 1; j > 0; j--)
			{
			arr[i][j] = arr[i][j-1];
			}
		}
		arr[0][0] = buffer;
		arr[2][0] = buffer_2;
		arr[1][0] = buffer_3;
	}
}
void ShiftRight(double arr[x][y], const int x, const int y)
{
	int shift;
	std::cout << "Введите значение смещения: "; std::cin >> shift;
	for (int i = 0; i < shift; i++)
	{
		double buffer = arr[x - 1][y-1];
		double buffer_2 = arr[x - 2][y-1];
		double buffer_3 = arr[x - 3][y-1];
	
		for (int i = x - 1; i >= 0; i--)
		{
			for (int j = y - 1; j > 0; j--)
			{
			arr[i][j] = arr[i][j-1];
			}
		}
		arr[0][0] = buffer;
		arr[2][0] = buffer_2;
		arr[1][0] = buffer_3;
	}
}
void ShiftRight(char arr[x][y], const int x, const int y)
{
	int shift;
	std::cout << "Введите значение смещения: "; std::cin >> shift;
	for (int i = 0; i < shift; i++)
	{
		char buffer = arr[x - 1][y-1];
		char buffer_2 = arr[x - 2][y-1];
		char buffer_3 = arr[x - 3][y-1];
	
		for (int i = x - 1; i >= 0; i--)
		{
			for (int j = y - 1; j > 0; j--)
			{
			arr[i][j] = arr[i][j-1];
			}
		}
		arr[0][0] = buffer;
		arr[2][0] = buffer_2;
		arr[1][0] = buffer_3;
	}
}