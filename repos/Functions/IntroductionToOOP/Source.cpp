#include <iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

#define tab "\t"

class Point
{
	double x;
	double y;
public:
	double get_x() const
	{
		return x;
	}
	double get_y() const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
	// Constructors:
	//				Constructors:
	/*Point()
	{
		x = y = double();
		//double() - значение по умолчанию для типа double
		cout << "DefaultConstructor:\t" << this << endl;
	}*/
	/*Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "1ArgConstructor:" << this << endl;
	}*/
	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}

	Point operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		std::cout << "CopyAssignment:\t" << this << std::endl;
		return *this;
	}

	// Methods :
	void print()const
	{
		std::cout << "X= " << x << "\tY= " << y << std::endl;
	}
	double distance(const Point other) const
	{
		/*double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;*/
		return sqrt(pow(this->x - other.x, 2) + pow(this->y - other.y, 2));
	}
};

double distance(const Point& A, const Point& B)
{
	/*double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;*/
	return sqrt(pow(A.get_x() - B.get_x(), 2) + pow(A.get_y() - B.get_y(), 2));
}

//#define Struct_Point
//#define GET_SET_CHECK
//#define DISTANCE_CHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef Struct_Point
	Point A;
	A.x = 2.2;
	A.y = 3.4;
	std::cout << A.x << tab << A.y << std::endl;

	Point* pA = &A;
	std::cout << pA->x << tab << pA->y << std::endl;
	std::cout << "Hello OOP";
	std::cout << std::endl;
#endif // Struct_Point

#ifdef GET_SET_CHECK
	Point A;
	A.set_x(2);
	A.set_y(3);
	//std::cout << A.get_x() << tab << A.get_y() << std::endl;
	A.print();
	Point B;
	B.set_x(5);
	B.set_y(9);
	//std::cout << B.get_x() << tab << B.get_y() << std::endl;
	B.print();
#endif // GET_SET_CHECK

#ifdef DISTANCE_CHECK
	Point A(2, 3);
	Point B(7, 8);
	A.print();
	B.print();
	cout << delimiter << endl;
	cout << "Расстояние от точки 'A' до точки 'B': " << A.distance(B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние от точки 'B' до точки 'A': " << B.distance(A) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками 'A' и 'B': " << distance(A, B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками 'B' и 'A': " << distance(B, A) << endl;
	cout << delimiter << endl;
#endif // DISTANCE_CHECK


	//Point A; //Default Constructor
	//A.print();
	//Point B = 5;//Single-argument Constructor
	//B.print();
	//Point C(2, 3);
	//C.print();
	//std::cout << distance();
	Point A, B, C;
	A = B = C = Point(2, 3);
}