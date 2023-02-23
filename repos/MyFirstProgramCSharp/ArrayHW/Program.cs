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

            //Task4

            //int[,] matrixC = new int[,] { };
            int i, j, a, b;
            int number;
            int answer=0;
            WriteLine("Добро пожаловать в калькулятор матриц.");
            WriteLine("Выберите действие, чтобы продолжить!");
            WriteLine("1.Умножение числа на матрицу.");
            WriteLine("2.Сложение матриц.");
            WriteLine("3.Умножение матрицы на матрицу.");
            do
            {

                answer = Int32.Parse(ReadLine());
                switch (answer)
                {
                    case 1:
                        {
                            WriteLine("Введите размерность матрицы: ");
                            WriteLine("Количество строк: ");
                            i = Int32.Parse(ReadLine());
                            WriteLine("Количество столбцов: ");
                            j = Int32.Parse(ReadLine());
                            int[,] matrixA = new int[i, j];
                            Matrix(i, j, matrixA);
                            WriteLine("Введите число для умножения матрицы на него: ");
                            number = Int32.Parse(ReadLine());
                            for (int k = 0; k < i; k++)
                            {
                                for (int h = 0; h < j; h++)
                                {
                                    matrixA[k, h] *= number;
                                }
                            }
                            WriteLine("Матрица + " + number +" =");
                            PrintMatrix(i, j, matrixA);
                            break;
                        }
                    case 2:
                        {
                            WriteLine("Введите размерность матриц: ");
                            WriteLine("Количество строк: ");
                            i = Int32.Parse(ReadLine());
                            WriteLine("Количество столбцов: ");
                            j = Int32.Parse(ReadLine());
                            int[,] matrixA = new int[i, j];
                            int[,] matrixB = new int[i, j];
                            Matrix(i, j, matrixA);
                            Matrix(i, j, matrixB);
                            int[,] matrixC = new int[i, j];
                            for (int k=0; k<i;k++)
                            {
                                for(int h=0; h<j;h++)
                                {
                                    matrixC[k, h] = matrixA[k, h] + matrixB[k,h];
                                }
                            }
                            
                            WriteLine("Результат сложения двух матриц =");
                            PrintMatrix(i, j, matrixC);
                            break;
                        }
                    case 3:
                        {
                            WriteLine("Введите размерность матрицы: ");
                            WriteLine("Количество строк: ");
                            i = Int32.Parse(ReadLine());
                            WriteLine("Количество столбцов: ");
                            j = Int32.Parse(ReadLine());
                            int[,] matrixA = new int[i, j];
                            WriteLine("Введите размерность матрицы: ");
                            WriteLine("Количество строк: " + j);
                            WriteLine("Количество столбцов: ");
                            b = Int32.Parse(ReadLine());
                            int[,] matrixB = new int[j, b];
                            Matrix(i, j, matrixA);
                            Matrix(j, b, matrixB);
                            int[,] matrixC = new int[i, b];
                            for (int k = 0; k < i; k++)
                            {
                                for (int h = 0; h < b; h++)
                                {
                                    for(int n=0; n<j; n++)
                                    {
                                        matrixC[k, h] += matrixA[k, n] * matrixB[n, h];
                                    }
                                }
                            }
                            WriteLine("Результат перемножения двух матриц = ");
                            PrintMatrix(i, b, matrixC);
                            break;
                        }
                }
                WriteLine("Выберите действие, чтобы продолжить!");
                WriteLine("Для выхода из калькулятора введите 0");
            } while(answer!=0);

        }


        static void PrintMatrix(int z, int x, int[,] matrix)
        {
            for (int k = 0; k < z; k++)
            {
                for (int h = 0; h < x; h++)
                {
                    Write(matrix[k, h]+" ");
                }
                WriteLine();
            }
        }
        static void Matrix(int z, int x, int[,] matrix)
        {
            WriteLine("Введите значения матрицы: ");
            for (int k = 0; k < z; k++)
            {
                for (int h = 0; h < x; h++)
                {
                    matrix[k, h] = Int32.Parse(ReadLine());
                }
            }
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
