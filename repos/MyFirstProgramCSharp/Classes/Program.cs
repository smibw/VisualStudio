using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;

namespace Classes
{

    class Mathematic
    {
        public static int Sum(int a, int b)
        {
            return a + b;
        }
        public static int Sum(int a, int b, int c)
        {
            return a + b + c;
        }

        public static double Sum(double da, double db)
        {
            return da +db;
        }
    }
    /*
    class Student
    {
        static string _academyName = "Компьютерная академия \"ТОП\"";
        string _firstName = "Анатолий";

        public void ShowName()
        {
            WriteLine(_firstName);
        }

        public static void ShowAcademy()
        {
            WriteLine(_academyName);
        }

    }
    */
    //---------------------------------------------------------------------
    /*
    public class ClassA
    {

        public void MethodA(ClassB obj)
        {
            obj.MethodB(this);
        }
    }

    public class ClassB
    {
        public void MethodB(ClassA obj)
        {
            WriteLine("Работа с классом " + obj.GetType().Name);
        }
    }
    class Student
    {
        string _firstName;
        string _lasttName;
        
        public Student (string firstName, string lasttName)
        {
           this._firstName = firstName;
           this._lasttName = lasttName;
        }
    }

    class Car
    {
        private string _driverName;
        private int _currSpeed;

        public Car():this("Нет водителя", 0) { }
        public Car(string driverName) : this(driverName, 0) { }

        public Car(string driverName, int speed)
        {
            _driverName = driverName;
            _currSpeed= speed;
        }

        public void SetDriver(string driverName)
        {
            _driverName = driverName;
        }
        public void PrintState()
        {
            WriteLine($"{_driverName} едет со скоростью {_currSpeed} км/ч.");
        }

        public void SpeedUp(int delta)
        {
            _currSpeed += delta;
        }
            
    }
    */
    internal class Classes
    {
        /*
        static void MyFunction(int[] MyArr, int i)
        {
            MyArr[0] = 100;
            i = 100;
        }
        */
        static void Main(string[] args)
        {
            /*
            ClassA a=new ClassA();
            ClassB b = new ClassB();
            a.MethodA(b);

            Car myCar = new Car();
            for(int i=0;i<10;i++)
            {
                myCar.SpeedUp(15);
                myCar.PrintState();
            }
            */
            /*
            Student student1 = new Student();
            student1.ShowName();
            Student.ShowAcademy();

            int i = 0;
            int[] MyArr = { 0, 1, 2, 3, 4 };
            WriteLine("i= " + i);
            WriteLine("MyArr[0] = " + MyArr[i]);
            WriteLine("Выозов MyFunction");
            MyFunction(MyArr, i);
            WriteLine("i = " + i);
            WriteLine("MyArr[0] = " + MyArr[0]);
            */

            int a = 10, b = 20, c = 30;
            double da = 3.3, db = 6.7;
            WriteLine($"{a}+{b} = {Mathematic.Sum(a,b)}");
            WriteLine($"{a}+{b}+{c} = {Mathematic.Sum(a,b,c)}");
            WriteLine($"{da}+{db} = {Mathematic.Sum(da,db)}");
        }
    }
}
