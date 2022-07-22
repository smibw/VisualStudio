#include"stdafx.h"
#define INT
//#define FLOAT
//#define DOUBLE
//#define CHAR
//#define INT2D
//#define FLOAT2D
//#define DOUBLE2D
//#define CHAR2D
#include "Constants.h"
#include"FillRand.h"
#include"Print.h"
#include"Sort.h"
#include"Statistics.h"
#include"Shift.h"
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