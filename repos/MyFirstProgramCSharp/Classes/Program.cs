using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;

namespace Classes
{


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
    internal class Classes
    {
        static void Main(string[] args)
        {

            ClassA a=new ClassA();
            ClassB b = new ClassB();
            a.MethodA(b);

            Car myCar = new Car();
            for(int i=0;i<10;i++)
            {
                myCar.SpeedUp(15);
                myCar.PrintState();
            }
        }
    }
}
