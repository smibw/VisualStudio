using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;

namespace Strings_pw223
{
    class Strings_pw223
    {
        static void Main(string[] args)
        {
            //************примеры создания строк*****************
            string str1 = "Hello world!";
            char[] chrArr = { 'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd', '!' };
            string str2 = new string(chrArr);
            string str3 = new string(chrArr, 6, 5);
            string str4 = new string('$', 10);
            WriteLine("str1: " + str1);
            WriteLine("str2: " + str2);
            WriteLine("str3: " + str3);
            WriteLine("str4: " + str4);

            string strPath1 = "C:\\Users\\Machenike\\source\\repos";
            string strPath2 = @"C:\Users\Machenike\source\repos";
            WriteLine(strPath1);
            WriteLine(strPath2);

            string str5 = "I ";
            string str6 = "learn ";
            string str7 = "C#";
            string str8 = str5 + str6 + str7;

            //форматированная строка. в {} передаются индексы аргументов, которые перечисляются в заданном порядке после строки
            WriteLine("{0} + {1} + {2} = {3}", str5, str6, str7, str8);

            str8 = str8.Replace("learn", "like");
            WriteLine(str8.ToUpper());

            str8 = str8.PadLeft(15, '*');
            str8 = str8.PadRight(31, '*');
            WriteLine(str8);

            str8 = str8.TrimStart("*".ToCharArray());
            WriteLine(str8);

            int number1 = 56, number2 = 78;

            WriteLine("Число №1 равно {0}. Число №2 равно {1}.", number1, number2);
            WriteLine($"Число №1 равно {number1}. Число №2 равно {number2}");

        }
    }
}