#define _USE_MATH_DEFINES
#include <iostream>
#include<Windows.h>
#include <math.h>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

namespace Geometry
{
	enum Color
	{
		red =	0x000000FF,
		green=	0x0000FF00,
		blue=	0x00FF0000,
		yellow=	0x0000FFFF,
		white=	0x00FFFFFF,
		grey=0x00AAAAAA,
		console_default = 0x07,
		console_blue = 0x99,
		console_green = 0xAA,
		console_red = 0xCC,
		console_yellow = 0xEE,

	};

	class Shape
	{
	protected:
		unsigned int start_x;
		unsigned int start_y;
		unsigned int line_width;
		Color color;
	public:
		unsigned int get_start_x()const
		{
			return start_x;
		}
		unsigned int get_start_y()const
		{
			return start_y;
		}
		unsigned int get_line_width()const
		{
			return line_width;
		}
		void set_start_x(unsigned int start_x)
		{
			if (start_x > 800)start_x = 800;
			this->start_x = start_x;
		}
		void set_start_y(unsigned int start_y)
		{
			if (start_y >500)start_y = 500;
			this->start_y = start_y;
		}
		void set_line_width(unsigned int line_width)
		{
			if (line_width > 30)line_width = 30;
			this->line_width = line_width;
		}
		Shape(unsigned int start_x, unsigned int start_y,unsigned int line_width,Color color) :color(color) 
		{
			set_start_x(start_x);
			set_start_y(start_y);
			set_line_width(line_width);
		}
		virtual ~Shape() {}
		virtual double get_area()const = 0;
		virtual double get_perimeter()const = 0;
		virtual void draw()const = 0;
		virtual void info()const
		{
			std::cout << "Площадь фигуры : " << get_area() << std::endl;
			std::cout << "Периметр фигуры: " << get_perimeter() << std::endl;
			draw();
		}
	};

	class Square :public Shape
	{
		double side;
	public:
		double get_side()const
		{
			return side;
		}
		void set_side(double side)
		{
			if (side < 5)side = 5;
			if (side > 20) side = 20;
			this->side = side;
		}
		//		Constructors;
		Square(double side,unsigned int start_x, unsigned int start_y,unsigned int line_width, Color color):
			Shape(start_x, start_x,line_width,color)
		{
			set_side(side);
		}
		~Square() {}
		double get_area()const override
		{
			return  side * side;
		}
		double get_perimeter()const override
		{
			return side * 4;
		}
		void draw()const override
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, color);
			for (int i = 0; i < side; i++)
			{
				for (int j = 0; j < side; j++)
				{
					std::cout << "* ";
				}
				std::cout << std::endl;
			}
			SetConsoleTextAttribute(hConsole, Color::console_default);
		}
		void info()const override
		{
			std::cout << typeid(*this).name() << std::endl;
			std::cout << "Длина стороны квадрата: " << side << " условных единиц" << std::endl;
			Shape::info();
		}
	};
	class Rectangle :public Shape
	{
		double width;
		double length;
	public:
		double get_width()const
		{
			return width;
		}
		double get_length()const
		{
			return length;
		}
		void set_width(double width)
		{
			if (width < 30)width = 30;
			if (width > 300)width = 300;
			this->width = width;
		}
		void set_length(double length)
		{
			if (length < 20)length = 20;
			if (length > 200)length = 200;
			this->length = length;
		}
		Rectangle(double width, double length, unsigned int start_x, unsigned int start_y, unsigned int line_width, Color color) :
			Shape(start_x,start_y,line_width,color)
		{
			set_width(width);
			set_length(length);
		}
		~Rectangle() {}
		double get_area()const override
		{
			return width * length;
		}
		double get_perimeter()const override
		{
			return (width + length) * 2;
		}
		void draw()const
		{
			/*
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, color);
			for (int i = 0; i < length; i++)
			{
				for (int j = 0; j < width; j++)
				{
					std::cout << "* ";
				}
				std::cout << std::endl;
			}
			SetConsoleTextAttribute(hConsole, Color::console_default);
			*/
			//1 Получаем окно консоли
			HWND hwnd = GetConsoleWindow();
			//2 Получаем контекст устройства для окна консоли
			HDC hdc = GetDC(hwnd); // это, то на чем мы будем рисовать

			//3 Создаем карандаш-это то, чем мы будем рисовать(карандаш рисует линии) и создаем кисть(заливка)
			HPEN hPen = CreatePen(PS_SOLID, line_width, color);
			HBRUSH hBrush = CreateSolidBrush(color);
			//4 Выбираем чем и на чем мы будем рисовать
			SelectObject(hdc,hPen);
			SelectObject(hdc, hBrush);


			//5 Рисуем прямоугольник
			::Rectangle(hdc, start_x, start_y, start_x+width, start_y+length);

			//Удаляем карандаш
			DeleteObject(hPen);
			DeleteObject(hBrush);

			// Освобождаем контекст устройства
			ReleaseDC(hwnd, hdc);
		}
		void info()const override
		{
			std::cout << typeid(*this).name() << std::endl;
			std::cout << "Ширина: " << width << std::endl;
			std::cout << "Длина: " << length << std::endl;
			Shape::info();

		}
	};
	class Triangle :public Shape
	{
	public:
		Triangle(unsigned int start_x, unsigned int start_y, unsigned int line_width, Color color)
			:Shape(start_x, start_y ,line_width, color) {}
		~Triangle() {}
		virtual double get_height()const = 0;
		void info()const
		{
			std::cout << "Высота: " << get_height() << std::endl;
			Shape::info();
		}
	};
	class EquilateralTriangle :public Triangle
	{
		double side;
	public:
		double get_side()const
		{
			return side;
		}
		void set_side(double side)
		{
			if (side < 20)side = 20;
			if (side > 200)side = 200;
			this->side = side;
		}
		EquilateralTriangle(double side, unsigned int start_x, unsigned int start_y, unsigned int line_width, Color color)
			:Triangle(start_x, start_y, line_width, color)
		{
			set_side(side);
		}
		~EquilateralTriangle() {}
		double get_height()const override
		{
			return 2 * get_area() / side;
		}
		double get_area()const override
		{
			return side * side * sqrt(3) / 4;
		}
		double get_perimeter()const override
		{
			return side * 3;
		}
		void draw()const override
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);
			HPEN  hPen = CreatePen(PS_SOLID, line_width, color);
			HBRUSH hBrush = CreateSolidBrush(color);
			SelectObject(hdc,hPen);
			SelectObject(hdc,hBrush);
			POINT vert[] =
			{
				{start_x,start_y + side},
				{start_x + side,start_y + side},
				{start_x + side / 2,start_y + side - get_height()}
			};
			::Polygon(hdc, vert, 3);
			DeleteObject(hBrush);
			DeleteObject(hPen);
			ReleaseDC(hwnd, hdc);
		}
		void info()const 
		{
			std::cout << typeid(*this).name() << std::endl;
			std::cout << "Сторона равностороннего треугольника: " <<side<< std::endl;
			Triangle::info();
		}
	};
	class IsoscelesTriagnle :public Triangle
	{
		double side;
		double isosceles_side;
	public:
		double get_side()const
		{
			return side;
		}
		double get_isosceles_side()const
		{
			return isosceles_side;
		}
		void set_side(double side)
		{
			if (side < 20)side = 20;
			if (side > 220)side = 220;
			this->side = side;
		}
		void set_isosceles_side(double isosceles_side)
		{
			if (isosceles_side < 20)isosceles_side = 20;
			if (isosceles_side > 220)isosceles_side = 220;
			this->isosceles_side = isosceles_side;
		}
		IsoscelesTriagnle(double side, double isosceles_side, unsigned int start_x, unsigned int start_y, unsigned int line_width, Color color)
			:Triangle(start_x, start_y, line_width,color)
		{
			set_side(side);
			set_isosceles_side(isosceles_side);
		}
		~IsoscelesTriagnle() {};
		double get_height()const override
		{
			return 2 * get_area() / side;
		}
		double get_area()const override
		{
			return sqrt(get_perimeter() / 2 * (get_perimeter() / 2 - isosceles_side) * (get_perimeter() / 2 - isosceles_side) * (get_perimeter() / 2 - side));
		}
		double get_perimeter()const override
		{
			return isosceles_side * 2 + side;
		}
		void draw()const override
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);
			HPEN hPen = CreatePen(PS_SOLID, line_width, color);
			HBRUSH hBrush = CreateSolidBrush(color);
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);
			POINT verty[] =
			{
				{start_x,start_y + isosceles_side},
				{start_x + side,start_y + isosceles_side},
				{start_x + side / 2,start_y + isosceles_side - get_height()}
			};
			::Polygon(hdc, verty, 3);
			DeleteObject(hBrush);
			DeleteObject(hPen);
			ReleaseDC(hwnd, hdc);
		}
		void info()const
		{
			std::cout << typeid(*this).name() << std::endl;
			std::cout << "Равнобедренная сторона: " << isosceles_side<<std::endl;
			std::cout << "Третья сторона равнобедренного треугольника: " << side << std::endl;
			Shape::info();
		}
	};
	class RectangularTriangle :public Triangle
	{
		double akatet;
		double bkatet;
		double hypotenuse;
	public:
		double get_akatet()const
		{
			return akatet;
		}
		double get_bkatet()const
		{
			return bkatet;
		}
		double get_hypotenuse()const
		{
			return hypotenuse;
		}
		void set_akatet(double akatet)
		{
			if (akatet < 20)akatet = 20;
			if (akatet > 220)akatet = 220;
			this->akatet = akatet;
		}
		void set_bkatet(double bkatet)
		{
			if (bkatet < 20)bkatet = 20;
			if (bkatet > 220)bkatet = 220;
			this->bkatet = bkatet;
		}
		void set_hypotenuse(double hypotenuse)
		{
			if (hypotenuse < 40)hypotenuse = 40;
			if (hypotenuse > 440)hypotenuse = 440;
			this->hypotenuse = hypotenuse;
		}
		RectangularTriangle(double akatet, double bkatet, double hypotenuse, unsigned int start_x, unsigned int start_y, unsigned int line_width, Color color)
			:Triangle(start_x, start_y, line_width, color)
		{
			set_akatet(akatet);
			set_bkatet(bkatet);
			set_hypotenuse(hypotenuse);
		}
		~RectangularTriangle() {}
		double get_height()const override
		{
			return 2 * get_area() / hypotenuse;
		}
		double get_area()const override
		{
			return akatet * bkatet / 2;
		}
		double get_perimeter()const override
		{
			return akatet + bkatet + hypotenuse;
		}
		void draw()const
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);
			HPEN hPen = CreatePen(PS_SOLID, line_width, color);
			HBRUSH hBrush = CreateSolidBrush(color);
			SelectObject(hdc,hPen);
			SelectObject(hdc,hBrush);
			POINT vetr[] =
			{
				{start_x,start_y},
				{start_x,start_y+akatet},
				{start_x+bkatet,start_y+akatet}
			};
			::Polygon(hdc, vetr, 3);
			DeleteObject(hBrush);
			DeleteObject(hPen);
			ReleaseDC(hwnd, hdc);
		}
		void info()const
		{
			std::cout << typeid(*this).name() << std::endl;
			std::cout << "Первый катет: " << akatet << std::endl;
			std::cout << "Второй катет: " << bkatet << std::endl;
			std::cout << "Гипотенуза: " << hypotenuse << std::endl;
			Shape::info();
		}
	};
	/*
		double get_aside()const
		{
			return aside;
		}
		double get_bside()const
		{
			return bside;
		}
		double get_cside()const
		{
			return cside;
		}
		void set_aside(double aside)
		{
			//if (aside > bside + cside)aside = (bside + cside)/2; Попытка сделать защиту от дурака, чтобы нельзя было сделать треугольник
			//с стороной, которая больше суммы двух других сторон. Почему-то выдает дичь полнейшую...
			if (aside < 3)aside = 3;
			if (aside > 15)aside = 15;
			this->aside = aside;
		}
		void set_bside(double bside)
		{
			//if (bside > aside + cside)bside = (aside + cside)/2;
			if (bside < 4)bside = 4;
			if (bside > 15)bside = 15;
			this->bside = bside;
		}
		void set_cside(double cside)
		{
			//if (cside > aside +bside)cside = (aside +bside)/2;
			if (cside < 5)cside = 5;
			if (cside > 15)cside = 15;
			this->cside = cside;
		}
		Triangle(double aside, double bside, double cside, Color color) :Shape(color)
		{
			set_aside(aside);
			set_bside(bside);
			set_cside(cside);
		}
		~Triangle() {}
		double area()const override
		{
			return sqrt(((aside+bside+cside)/2)*(((aside + bside + cside) / 2)-aside)*(((aside + bside + cside) / 2)-bside)*(((aside + bside + cside) / 2)-cside));
		}
		double perimeter()const override
		{
			return aside + bside + cside;
		}
		void draw()const
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);
			HPEN hPen = CreatePen(PS_SOLID, 5, color);
			HBRUSH hBrush = CreateSolidBrush(color);
			SelectObject(hdc,hPen);
			SelectObject(hdc,hBrush);
			//::Polygon(hdc, 100, 3);
			DeleteObject(hPen);
			DeleteObject(hBrush);
		}
		void info()const override
		{
			std::cout << typeid(*this).name() << std::endl;
			std::cout << "Сторона А: " << aside << std::endl;
			std::cout << "Сторона Б: " << bside << std::endl;
			std::cout << "Сторона С: " << cside << std::endl;
			Shape::info();
		}
	
	*/
	class Circle :public Shape
	{
		double radius;
	public:
		double get_radius()const
		{
			return radius;
		}
		void set_radius(double radius)
		{
			if (radius < 20)radius = 20;
			if (radius > 220)radius = 220;
			this->radius = radius;
		}
		Circle(double radius,unsigned int start_x, unsigned int start_y,unsigned int line_width, Color(color)):
			Shape(start_x, start_y,line_width, color)
		{
			set_radius(radius);
		}
		~Circle() {}
		double get_area()const override
		{
			return M_PI * radius * radius;
		}
		double get_perimeter()const override
		{
			return 2* M_PI* radius;
		}
		void draw()const override
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);
			HPEN hPen = CreatePen(PS_SOLID, line_width, color);
			HBRUSH hBrush = CreateSolidBrush(color);
			SelectObject(hdc,hPen);
			SelectObject(hdc,hBrush);
			::Ellipse(hdc, start_x, start_y, start_x+radius*2, start_y+radius*2);
			DeleteObject(hBrush);
			DeleteObject(hPen);
			ReleaseDC(hwnd, hdc);

		}
		void info()const
		{
			std::cout << typeid(*this).name() << std::endl;
			std::cout << "Радиус: " << radius << std::endl;
			Shape::info();
		}
	};
}

void main()
{
	setlocale(LC_ALL, "");

	//Shape shape;

	Geometry::Square square(8,100,100,11, Geometry::Color::console_red);
	square.info();
	std::cout << std::endl;
	Geometry::Rectangle rect(150, 70, 200,100,11, Geometry::Color::grey);
	rect.info();
	//Geometry::Triangle tri(15, 9, 9, Geometry::Color::console_blue);
	//tri.info();
	Geometry::Circle circ(100,500,100,11, Geometry::Color::yellow);
	circ.info();
	Geometry::EquilateralTriangle e_try(170, 700, 200, 8, Geometry::Color::green);
	e_try.info();
	Geometry::IsoscelesTriagnle i_try(150, 90, 500, 500, 8, Geometry::Color::red);
	i_try.info();
	Geometry::RectangularTriangle r_try(150, 180, 300, 400, 300, 10, Geometry::Color::blue);
	r_try.info();
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
}