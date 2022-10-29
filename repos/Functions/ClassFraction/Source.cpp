#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n------------------------------------------------\n"

class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator+(Fraction left, Fraction right);
Fraction operator/(const Fraction& left, const Fraction& right);

class Fraction
{
	int integer;
	int numerator;
	int denominator;
public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}

	//					Constructors:
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefConstructor:\t" << this << endl;
	}
	 explicit/*(запрещает неявные преобразования типов)*/ Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "1ArgConstructor:" << this << endl;
	}
	 Fraction(double decimal)
	 {
		 integer = decimal;
		 denominator = 1e+9;
		 numerator = (decimal - integer) * denominator;
		 cout << "DoubleConstractor:" << endl;
	 }
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constructor:\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constructor:\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t" << this << endl;
	}

	//				Operators:
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	Fraction& operator*=(const Fraction& other)
	{
		return *this = *this * other;
	}
	Fraction& operator+=(const Fraction& other)
	{
		return *this = *this + other;
	}
	Fraction& operator/=(const Fraction& other)
	{
		return *this = *this / other;
	}

	Fraction& operator++()
	{
		integer++;
		return *this;
	}
	Fraction operator++(int)
	{
		Fraction old = *this;
		integer++;
		return old;
	}
	Fraction operator()(int integer, int numerator, int denominator)
	{
		set_integer(integer);
		set_numerator(numerator);
		set_denominator(denominator);
		return *this;
	}

	operator int() const
	{
		return integer;
	}
	operator double() const
	{
		return integer + (double)numerator / denominator;
	}

	//				Methods
	Fraction& to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction& to_proper()
	{
		integer = numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction inverted()const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		/*int buffer = inverted.numerator;
		inverted.numerator = inverted.denominator;
		inverted.denominator = buffer;*/
		swap(inverted.numerator, inverted.denominator);
		return inverted;
	}
	Fraction& reduce()
	{
		int more, less, rest;
		if (numerator > denominator)
		{
			more = numerator;
			less = denominator;
		}
		else
		{
			more = denominator;
			less = numerator;
		}
		do
		{
			rest = more % less;
			more = less;
			less = rest;
		} while (rest);
		int GCD=more;
		if (GCD == 0)return *this;
		numerator /= GCD;
		denominator /= GCD;
		return *this;
	}
};

ostream& operator<<(ostream& os, const Fraction& obj)
{
	if (obj.get_integer())os << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer())os << "(";
		os << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer())os << ")";
	}
	else if (obj.get_integer() == 0) os << 0;
	return os;
}

Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	/*Fraction result;
	result.set_numerator(left.get_numerator()*right.get_numerator());
	result.set_denominator(left.get_denominator()*right.get_denominator());*/
	/*Fraction result
	(
		left.get_numerator()*right.get_numerator(),
		left.get_denominator()*right.get_denominator()
	);
	return result;*/

	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper();
}
Fraction operator/(const Fraction& left, const Fraction& right)
{
	/*left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator()*right.get_denominator(),
		right.get_numerator()*left.get_denominator()
	).to_proper();*/
	return left * right.inverted();
}
Fraction operator+(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator() * right.get_denominator() + right.get_numerator() * left.get_denominator(),
		left.get_denominator() * right.get_denominator()
	).to_proper();
}
	//					Comparison operators:
	bool operator==(Fraction left, Fraction right)
	{
		left.to_improper();
		right.to_improper();
		return 
			left.get_numerator() * right.get_denominator() ==
			right.get_numerator() * left.get_denominator();
	}
	bool operator!=(const Fraction left, const Fraction right)
	{
		return !(left == right);
	}
	bool operator>(Fraction left, Fraction right)
	{
		left.to_improper();
		right.to_improper();
		return
			left.get_numerator() * right.get_denominator() >
			right.get_numerator() * left.get_denominator();
	}
	bool operator<(Fraction left, Fraction right)
	{
		left.to_improper();
		right.to_improper();
		return
			left.get_numerator() * right.get_denominator() <
			right.get_numerator() * left.get_denominator();
	}
	bool operator>=(const Fraction& left, const Fraction& right)
	{
		return left > right || left == right;
	}
	bool operator<=(const Fraction& left, const Fraction& right)
	{
		return !(left > right);
	}


//#define CONSTRUCTORS_CHECK
//#define ARITHMETICALS_OPERATORS_CHECK
//#define COMPOUND_ASSIGNMENTS_CHECK
//#define COMPARISON_OPERATORS_CHECK
//#define TYPE_CONVERSION_BASICS
//#define CONVERSION_FROM_OTHER_TO_CLASS
//#define REDUCE_HOW
void main()
{
	setlocale(LC_ALL, "");

#ifdef CONSTRUCTORS_CHECK
	Fraction A;		//Default constructor
	cout << A << endl;

	double b = 5;
	Fraction B = 5;	//Single-argument constructor
	cout << B << endl;

	Fraction C(2, 3);
	cout << C << endl;

	Fraction D(2, 3, 4);
	cout << D << endl;
#endif // CONSTRUCTORS_CHECK

#ifdef ARITHMETICAL_OPERATORS_CHECK
	Fraction A(1, 2, 3);
	Fraction B(3, 4, 5);
	Fraction C = A * B;
	cout << C << endl;
	cout << A / B << endl;
	cout << A + B << endl;

	for (double i = 0.25; i < 10; i++)
	{
		cout << i << "\t";
	}
	cout << endl;
	for (Fraction i(3, 4); i.get_integer() < 10; i++)
	{
		cout << i << "\t";
	}
	cout << endl;
#endif // ARITHMETICAL_OPERATORS_CHECK

#ifdef COMPOUND_ASSIGNMENTS_CHECK
	Fraction A(1, 2, 3);
	Fraction B(3, 4, 5);
	//A += B;
	//cout << A << endl;
	A *= B;
	cout << A << endl;
#endif // COMPOUND_ASSIGNMENTS_CHECK

#ifdef COMPARISON_OPERATORS_CHECK
	Fraction A(1, 2);
	Fraction B(5, 10);
	/*
	if (A == B)
	{
		cout << "Дроби равны"<<endl;
	}
	else
	{
		cout << "Дроби разные"<<endl;
	}*/
	//cout << (A == B) << endl;
	cout << (Fraction(1, 2) <= Fraction(5, 10)) << endl;
	//cout << (2 == 2) << endl;  
#endif // COMPARISON_OPERATORS_CHECK

#ifdef TYPE_CONVERSION_BASICS
	//(type)value// C-like notation(C- подобная форма записи)
	//type(value) //Functional notation (Функциональная форма записи(напоминает вызов функции)) при конвертации возможны потери данных
	int a = 2;
	double b = 3;	//Conversion from less to more
	int c = b;		//Conversion from more to less with no data loss
	int d = 2.5;	//Conversion from more to less with data loss
#endif // TYPE_CONVERSION_BASICS

#ifdef CONVERSION_FROM_OTHER_TO_CLASS

	/*
		1. From other tp Class:
			Single-Argument constructor;
			Assignment operator;
		2. From Class to other;
			operator type()const
			{
				.....;
				coversion-algorithm;
				.....;
			}

			explicit
	*/
	Fraction A = (Fraction)5; // Conversion from 'int' to 'Fraction'
	cout << A << endl;
	cout << delimiter << endl;
	Fraction B;
	cout << delimiter << endl;
	B = (Fraction)8;
	cout << B << endl;
#endif // CONVERSION_FROM_OTHER_TO_CLASS

#ifdef HOMEWORK1
	Fraction A(2, 3, 4);
	int a = (int)A;
	cout << a << endl;
	double b = A;
	cout << b << endl;
#endif // HOMEWORK1

#ifdef REDUCE_HOW
	Fraction A(0, 48, 88);
	A.reduce();
	cout << A;

#endif // REDUCE_HOW


}
