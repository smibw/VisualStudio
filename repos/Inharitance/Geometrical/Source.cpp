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
		virtual double area()const = 0;
		virtual double perimeter()const = 0;
		virtual void draw()const = 0;
		virtual void info()const
		{
			std::cout << "Площадь фигуры : " << area() << std::endl;
			std::cout << "Периметр фигуры: " << perimeter() << std::endl;
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
		double area()const override
		{
			return  side * side;
		}
		double perimeter()const override
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
		double area()const override
		{
			return width * length;
		}
		double perimeter()const override
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
		EquilateralTriangle(double side, unsigned int start_x, unsigned int start_y, unsigned int line_width, Color color):Triangle(start_x, start_y, line_width, color)
		{
			set_side(side);
		}
		~EquilateralTriangle() {}
		double get_height()const override
		{
			return 2 * area() / side;
		}
		double area()const override
		{
			return side * side * sqrt(3) / 4;
		}
		double perimeter()const override
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
				{start_x,start_x + side},
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
		double area()const override
		{
			return M_PI * radius * radius;
		}
		double perimeter()const override
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
	Geometry::EquilateralTriangle e_try(170, 200, 200, 8, Geometry::Color::green);
	e_try.info();
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
}