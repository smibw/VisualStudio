using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

//----------------Модификаторы доступа------------------------
/*
private - данные доступны только внутри класса и вложенным классам
protected - данные доуступны только внутри класса и вложенным классам или в любом из производных классов
internal - данные доступны только методам в текущей сборке
protected internal - данные доступны только методам вложенных и дочерних классов внутри сборки
public - данные доступны везде и всем
*/

namespace Structures
{
    class MyClass
    {
        public readonly int Width = 10;
        public readonly int Length = 20;

        public readonly int[] myArr = { 1, 2, 3 };


        public MyClass(int width, int length)
        {
            Width = width;
            Length = length;
        }

        public void Print()
        {
            Console.WriteLine($"Длина {Length}, ширина {Width}.");
        }
    }

    internal class Structures
    {
        class Dimensions
        {
            private double length;
            private double width;

            public Dimensions(double length, double width)
            {
                this.length = length;
                this.width = width;

            }
            public void Print()
            {
                Console.WriteLine($"Длина {length}, ширина {width}.");
            }
        };


        class Student
        {
            int _studentID;
            string _firstname = "John";
            string _lastName = "Connor";
            string _group;

            public void Print()
            {
                Console.WriteLine($"Студент, {_firstname}, {_lastName}");
            }
        }
        static void Main(string[] args)
        {
            Student st1;
            st1 = new Student();
            st1.Print();

            Student st2 = new Student();
            st2.Print();

            double length = 3.456, width = 6.789;
            Dimensions dimention = new Dimensions(length, width);
            dimention.Print();

            MyClass obj = new MyClass(40,30);
            //obj.myArr = new int[10]; Инициализировать новый массив нельзя
            //obj.myArr[0] = 11; А поменять можно
            obj.Print();

            
        }
    }

}
