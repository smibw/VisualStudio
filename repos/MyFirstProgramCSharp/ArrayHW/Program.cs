using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;

namespace ArrayHW
{
    internal class ArrayHW
    {
        static void Main(string[] args)
        {
            //  Task1
            
            /*
            int[] A= new int[5];
            int[,] B = new int[3, 4];
            Random rand = new Random();
            int multiplicationA = 1;
            int multiplicationB = 1;
            int evenCounterA = 0;
            int evenCounterB = 0;
            Write("Введите значения массива А: ");
            for(int i=0;i<5;i++)
            {
                A[i] = Int32.Parse(ReadLine()); 
            }
            for (int i = 0; i < A.Length; i++)
            {
                multiplicationA *= A[i];
            }
            for(int i=0;i<A.Length;i++)
            {
                if (i%2!=0)
                {
                    evenCounterA+=A[i];
                }
                else
                {
                    evenCounterA += 0;
                }
            }
            Print("Вывод массива A", A);
            WriteLine("Максимальный элемент массива A: " + A.Max());
            WriteLine("Минимальный элемент массива A: " + A.Min());
            WriteLine("Сумма всех элементов массива A: " + A.Sum());
            WriteLine("Произведение всех элементов массива A: " + multiplicationA);
            WriteLine("Сумма всех чётных элементов массива A: " + evenCounterA);
            WriteLine("--------------------------------------------");
            for(int i=0; i<3;i++)
            {
                for(int j=0; j<4; j++)
                {
                    B[i,j] = rand.Next(0,100);
                }
            }
            for (int i = 0; i <3; i++)
            {
                for(int j=0;j<4;j++)
                {
                    multiplicationB *= B[i,j];
                }
            }
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (j % 2 == 0)
                    {
                        evenCounterB+=B[i,j];
                    }
                    else
                    {
                        evenCounterB+=0;
                    }
                }
            }
            WriteLine("Вывод двумерного массива B: ");
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    Write(B[i, j] + " ");
                }
                WriteLine();
            }
            WriteLine("Максимальный элемент массива B: " + B.Cast<int>().Max());
            WriteLine("Минимальный элемент массива B: " + B.Cast<int>().Min());
            WriteLine("Сумма всех элементов массива B: " + B.Cast<int>().Sum());
            WriteLine("Произведение всех элементов массива B: " + multiplicationB);
            WriteLine("Сумма всех элементов нечётных столбцов массива B: " + evenCounterB);
            WriteLine("--------------------------------------------");
            */

            //  Task2
            /*
            int[,] array =new int[5, 5];
            Random rand = new Random();
            int minmaxsum=0;
            bool trueArg = false;
            for(int i=0; i<5;i++)
            {
                for(int j=0;j<5;j++)
                {
                    array[i, j] = rand.Next(-100, 100);
                }
            }
            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    if (array[i, j] == array.Cast<int>().Min())
                    {
                        trueArg = true;
                        continue;
                    }
                    else if (array[i, j] == array.Cast<int>().Max())
                    {
                        trueArg = false; break;
                    }
                    else if (trueArg == true)
                    {
                        minmaxsum += array[i, j];
                    }
                    else
                    {
                        continue;
                    }
                }
            }
            WriteLine("Вывод массива arr: ");
            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    Write(array[i, j] + " ");
                }
                WriteLine();
            }
            WriteLine("Сумма элементов между min-элементом и max-элементом: " + minmaxsum);
            WriteLine("Минимальный элемент" + array.Cast<int>().Min());
            WriteLine("Максимальный элемент" + array.Cast<int>().Max());
            */

            //Task3

        }

        static void Print(string text, int[] arr)
        {
            Write(text + ": ");
            for(int i=0; i<arr.Length; i++)
            {
                Write(arr[i] + " ");
            }
            WriteLine();
        }
    }
}
