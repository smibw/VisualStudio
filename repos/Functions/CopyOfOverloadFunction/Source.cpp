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
#define INT2D
#define FLOAT2D
#define DOUBLE2D
#define CHAR2D
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

template<typename T>void Print(T arr[], const int n);
template<typename T>void Print(T arr[x][y], const int x, const int y);

template<typename T>void Sort(T arr[], const int n);
//У меня пока не получилось отсортировать двумерные массивы.

template<typename T>T Sum(T arr[], const int n);
template<typename T>T Sum(T arr[x][y], const int x, const int y);

double Avg(int arr[], const int n);
double Avg(float arr[], const int n);
double Avg(double arr[], const int n);
double Avg(char arr[], const int n);
double Avg(int arr[x][y], const int x, const int y);
double Avg(float arr[x][y], const int x, const int y);
double Avg(double arr[x][y], const int x, const int y);
double Avg(char arr[x][y], const int x, const int y);

template<typename T>T minValueIn(T arr[], const int n);
template<typename T>T minValueIn(T arr[x][y], const int x, const int y);

template<typename T>T maxValueIn(T arr[], const int n);
template<typename T>T maxValueIn(T arr[x][y], const int x, const int y);

template<typename T>void ShiftLeft(T arr[], const int n);
template<typename T>void ShiftLeft(T arr[x][y], const int x, const int y);

template<typename T>void ShiftRight(T arr[], const int n);
template<typename T>void ShiftRight(T arr[x][y], const int x, const int y);

void main()
{
	setlocale(LC_ALL, "");
	const int n = 5;
#ifdef INT
	int arr[n];
	FillRand(arr, n);
	std::cout << delimiter;
	std::cout << "Работа с массивом с int заполнением." << std::endl;
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
	std::cout << std::endl;
#endif // INT

#ifdef FLOAT

	std::cout << delimiter;
	std::cout << "Работа с массивом с float заполнением." << std::endl;
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
	std::cout << std::endl;
#endif // FLOAT

#ifdef DOUBLE
	std::cout << delimiter;
	std::cout << "Работа с массивом с double заполнением." << std::endl;
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
	std::cout << std::endl;
#endif // CHAR2D

}
void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}
void FillRand(float arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100000;
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
		arr[i] = rand();
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
			arr[i][j] = rand() % 100000;
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
			arr[i][j] = rand() % 10000;
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

template<typename T>void Print(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << tab;
	}
	std::cout << endl;
}
template<typename T>void Print(T arr[x][y], const int x, const int y)
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

template<typename T>void Sort(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] > arr[j])
			{
				T buffer = arr[i];
				arr[i] = arr[j];
				arr[j] = buffer;
			}

		}
	}
}

template<typename T>T Sum(T arr[], const int n)
{
	T Sum = 0;
	for (int i = 0; i < n; i++)
	{
		Sum += arr[i];
	}
	return Sum;
}
template<typename T>T Sum(T arr[x][y], const int x, const int y)
{
	T Sum = 0;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			Sum += arr[i][j];
		}
	}
	return Sum;
}

double Avg(int arr[], const int n)
{
	return (double)Sum(arr, n) / n;
}
double Avg(float arr[], const int n)
{
	return (double)Sum(arr, n) / n;
}
double Avg(double arr[], const int n)
{
	return (double)Sum(arr, n) / n;
}
double Avg(char arr[], const int n)
{
	return (double)Sum(arr, n) / n;
}
double Avg(int arr[x][y], const int x, const int y)
{
	return (double)Sum(arr, x, y) / (x * y);
}
double Avg(float arr[x][y], const int x, const int y)
{
	return (double)Sum(arr, x, y) / (x * y);
}
double Avg(double arr[x][y], const int x, const int y)
{
	return (double)Sum(arr, x, y) / (x * y);
}
double Avg(char arr[x][y], const int x, const int y)
{
	return (double)Sum(arr, x, y) / (x * y);
}

template<typename T>T minValueIn(T arr[], const int n)
{
	T minValueIn = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (minValueIn > arr[i])	minValueIn = arr[i];
	}
	return minValueIn;
}
template<typename T>T minValueIn(T arr[x][y], const int x, const int y)
{
	T minValueIn = arr[0][0];
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			if (minValueIn > arr[i][j])	minValueIn = arr[i][j];
		}
	}
	return minValueIn;
}

template<typename T>T maxValueIn(T arr[], const int n)
{
	T maxValueIn = 0;
	for (int i = 0; i < n; i++)
	{
		if (maxValueIn < arr[i]) maxValueIn = arr[i];
	}
	return maxValueIn;
}
template<typename T>T maxValueIn(T arr[x][y], const int x, const int y)
{
	T maxValueIn = 0;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			if (maxValueIn < arr[i][j])	maxValueIn = arr[i][j];
		}
	}
	return maxValueIn;
}

template<typename T>void ShiftLeft(T arr[], const int n)
{
	int shift;
	std::cout << "Введите значение смещения: "; std::cin >> shift;
	for (int i = 0; i < shift; i++)
	{
		T buffer = arr[0];
		for (int i = 0; i < n; i++)
		{
			arr[i] = arr[i + 1];
		}
		arr[n - 1] = buffer;
	}
}
template<typename T>void ShiftLeft(T arr[x][y], const int x, const int y)
{
	int shift;
	std::cout << "Введите значение смещения: "; std::cin >> shift;
	for (int i = 0; i < shift; i++)
	{
		T buffer = arr[0][0];
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				arr[i][j] = arr[i][j + 1];
			}
		}
		arr[x - 1][y - 1] = buffer;
	}
}

template<typename T>void ShiftRight(T arr[], const int n)
{
	int shift;
	std::cout << "Введите значение смещения: "; std::cin >> shift;
	for (int i = 0; i < shift; i++)
	{
		T buffer = arr[n - 1];
		for (int i = n - 1; i > 0; i--)
		{
			arr[i] = arr[i - 1];
		}
		arr[0] = buffer;
	}
}
template<typename T>void ShiftRight(T arr[x][y], const int x, const int y)
{
	int shift;
	std::cout << "Введите значение смещения: "; std::cin >> shift;
	for (int i = 0; i < shift; i++)
	{
		T buffer = arr[x - 1][y - 1];
		T buffer_2 = arr[x - 2][y - 1];
		T buffer_3 = arr[x - 3][y - 1];

		for (int i = x - 1; i >= 0; i--)
		{
			for (int j = y - 1; j > 0; j--)
			{
				arr[i][j] = arr[i][j - 1];
			}
		}
		arr[0][0] = buffer;
		arr[2][0] = buffer_2;
		arr[1][0] = buffer_3;
	}
}