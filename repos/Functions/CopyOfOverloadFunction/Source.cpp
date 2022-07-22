#include"stdfxa.h"
#include"Constant.h"
#define INT
#define FLOAT
#define DOUBLE
#define CHAR
#define INT2D
#define FLOAT2D
#define DOUBLE2D
#define CHAR2D
#include"FillRand.h"
#include"Print.h"
#include"Print.cpp"
#include"Sort.h"
#include"Sort.cpp"
#include"vg.h"
#include"Statistics.h"
#include"Statistics.cpp"
#include"Shift.h"
#include"Shift.cpp"
//� ���� ���� �� ���������� ������������� ��������� �������.
void main()
{
	setlocale(LC_ALL, "");
	const int n = 5;
#ifdef INT
	int arr[n];
	FillRand(arr, n);
	std::cout << delimiter;
	std::cout << "������ � �������� � int �����������." << std::endl;
	Print(arr, n);
	std::cout << delimiter;
	std::cout << "��������� ������." << std::endl;
	Sort(arr, n);
	std::cout << delimiter;
	Print(arr, n);
	std::cout << delimiter;
	std::cout << "����� ��������� ������� = " << Sum(arr, n) << std::endl;
	std::cout << delimiter;
	std::cout << "�������-�������������� �������� ������� = " << Avg(arr, n) << std::endl;
	std::cout << delimiter;
	std::cout << "����������� �������� �������� ������� = " << minValueIn(arr, n) << std::endl;
	std::cout << delimiter;
	std::cout << "������������ �������� �������� ������� = " << maxValueIn(arr, n) << std::endl;
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
	std::cout << "������ � �������� � float �����������." << std::endl;
	float brr[n];
	FillRand(brr, n);
	Print(brr, n);
	std::cout << delimiter;
	std::cout << "��������� ������." << std::endl;
	Sort(brr, n);
	std::cout << delimiter;
	Print(brr, n);
	std::cout << delimiter;
	std::cout << "����� ��������� ������� = " << Sum(brr, n) << std::endl;
	std::cout << delimiter;
	std::cout << "�������-�������������� �������� ������� = " << Avg(brr, n) << std::endl;
	std::cout << delimiter;
	std::cout << "����������� �������� �������� ������� = " << minValueIn(brr, n) << std::endl;
	std::cout << delimiter;
	std::cout << "������������ �������� �������� ������� = " << maxValueIn(brr, n) << std::endl;
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
	std::cout << "������ � �������� � double �����������." << std::endl;
	double crr[n];
	FillRand(crr, n);
	Print(crr, n);
	std::cout << delimiter;
	std::cout << "��������� ������." << std::endl;
	Sort(crr, n);
	std::cout << delimiter;
	Print(crr, n);
	std::cout << delimiter;
	std::cout << "����� ��������� ������� = " << Sum(crr, n) << std::endl;
	std::cout << delimiter;
	std::cout << "�������-�������������� �������� ������� = " << Avg(crr, n) << std::endl;
	std::cout << delimiter;
	std::cout << "����������� �������� �������� ������� = " << minValueIn(crr, n) << std::endl;
	std::cout << delimiter;
	std::cout << "������������ �������� �������� ������� = " << maxValueIn(crr, n) << std::endl;
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
	std::cout << "������ � �������� � char �����������." << std::endl;
	char drr[n];
	FillRand(drr, n);
	Print(drr, n);
	std::cout << delimiter;
	std::cout << "��������� ������." << std::endl;
	Sort(drr, n);
	std::cout << delimiter;
	Print(drr, n);
	std::cout << "����� ��������� ������� = " << Sum(drr, n) << std::endl;
	std::cout << delimiter;
	std::cout << "�������-�������������� �������� ������� = " << Avg(drr, n) << std::endl;
	std::cout << delimiter;
	std::cout << "����������� �������� �������� ������� = " << minValueIn(drr, n) << std::endl;
	std::cout << delimiter;
	std::cout << "������������ �������� �������� ������� = " << maxValueIn(drr, n) << std::endl;
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
	std::cout << "������ � ��������� �������� � int �����������." << std::endl;
	std::cout << delimiter;
	Print(arr_2, x, y);
	std::cout << delimiter;
	std::cout << "����� ��������� ������� = " << Sum(arr_2, x, y) << std::endl;
	std::cout << delimiter;
	std::cout << "�������-�������������� �������� ������� = " << Avg(arr_2, x, y) << std::endl;
	std::cout << delimiter;
	std::cout << "����������� �������� �������� ������� = " << minValueIn(arr_2, x, y) << std::endl;
	std::cout << delimiter;
	std::cout << "������������ �������� �������� ������� = " << maxValueIn(arr_2, x, y) << std::endl;
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
	std::cout << "������ � ��������� �������� � float �����������." << std::endl;
	std::cout << delimiter;
	Print(brr_2, x, y);
	std::cout << delimiter;
	std::cout << "����� ��������� ������� = " << Sum(brr_2, x, y) << std::endl;
	std::cout << delimiter;
	std::cout << "�������-�������������� �������� ������� = " << Avg(brr_2, x, y) << std::endl;
	std::cout << delimiter;
	std::cout << "����������� �������� �������� ������� = " << minValueIn(brr_2, x, y) << std::endl;
	std::cout << delimiter;
	std::cout << "������������ �������� �������� ������� = " << maxValueIn(brr_2, x, y) << std::endl;
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
	std::cout << "������ � ��������� �������� � double �����������." << std::endl;
	std::cout << delimiter;
	Print(crr_2, x, y);
	std::cout << delimiter;
	std::cout << "����� ��������� ������� = " << Sum(crr_2, x, y) << std::endl;
	std::cout << delimiter;
	std::cout << "�������-�������������� �������� ������� = " << Avg(crr_2, x, y) << std::endl;
	std::cout << delimiter;
	std::cout << "����������� �������� �������� ������� = " << minValueIn(crr_2, x, y) << std::endl;
	std::cout << delimiter;
	std::cout << "������������ �������� �������� ������� = " << maxValueIn(crr_2, x, y) << std::endl;
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
	std::cout << "������ � ��������� �������� � char �����������." << std::endl;
	std::cout << delimiter;
	Print(drr_2, x, y);
	std::cout << delimiter;
	std::cout << "����� ��������� ������� = " << Sum(drr_2, x, y) << std::endl;
	std::cout << delimiter;
	std::cout << "�������-�������������� �������� ������� = " << Avg(drr_2, x, y) << std::endl;
	std::cout << delimiter;
	std::cout << "����������� �������� �������� ������� = " << minValueIn(drr_2, x, y) << std::endl;
	std::cout << delimiter;
	std::cout << "������������ �������� �������� ������� = " << maxValueIn(drr_2, x, y) << std::endl;
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