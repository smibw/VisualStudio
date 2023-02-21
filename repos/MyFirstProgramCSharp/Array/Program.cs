using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;

namespace Array
{
    internal class Array
    {
        static void Main(string[] args)
        {
            //**********двумерный массив***************
            /*float[,] myArr = new float[2, 3];
            int[,] myArr1 = new int[2, 3] { { 1, 2, 3 }, { 3, 4, 5 } };
            int[,] myArr2 = new int[,] { { 1, 2, 3 }, { 4, 5, 6 } };
            int[,] myArr3 = { { 1, 2, 3 }, { 4, 5, 6 } };

            myArr1[1, 2] = 100;
            WriteLine(myArr1[1, 2]);*/
            //*******************конец*************

            //*****************трехмерный массив**************
            /*int[,,] array = new int[2, 2, 3] { { { 1, 2, 3 }, { 4, 5, 6 } }, { { 7, 8, 9 }, { 10, 11, 12 } } };*/
            //*******************конец*************************


            //*********************методы работы с массивами**************
            /*int[] array1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
            PrintArr("Массив array1", array1);
            int[] array2 = (int[])array1.Clone();
            Array.Reverse(array1, 3, 4);
            PrintArr("Массив array1 после реверсирования: ", array1);
            array1 = array2;
            PrintArr("Массив array1 после восстановления: ", array1);

            int[] array3 = new int[20];
            PrintArr("Массив array3 до копирования: ", array3);
            array1.CopyTo(array3, 5);
            PrintArr("Массив array3 после копирования: ", array3);
            Array.Clear(array3, 0, array3.GetLength(0));
            PrintArr("Массив array3 после очистки: ", array3);
            Array.Resize(ref array3, 10);
            PrintArr("Массив array3 после изменения размера: ", array3);
            array3 = new[] { 1, 5, 7, 9, 4, 2, 8, 6, 3, 10 };
            PrintArr("Массив array3 до сортировки: ", array3);
            Array.Sort(array3);
            PrintArr("Массив array3 после сортировки: ", array3);
            WriteLine("Число 5 находится в массиве на " + Array.BinarySearch(array3, 5) + " позиции");
            WriteLine("Максимальный элемент массива array3: " + array3.Max());
            WriteLine("Среднее арифметическое элементов array3: " + array3.Average());*/
            //****************конец********

            //***********************зубчатые массивы**************
            /*int[][] jaggedArr = new int[2][];
            jaggedArr[0] = new int[] { 1, 2 };
            jaggedArr[1] = new int[] { 3, 4, 5, 6 };
            WriteLine(jaggedArr[1][2]);*/

            int size = 5;
            int[][] jArr = new int[size][];
            for (int i = 0; i < jArr.Length; i++)
            {
                jArr[i] = new int[i + 1];
            }
            for (int i = 0; i < jArr.Length; i++)
            {
                for (int j = 0; j < jArr[i].Length; j++)
                {
                    jArr[i][j] = i + j + 1;
                    Write(jArr[i][j] + " ");
                }
                WriteLine();
            }

        }
        static void PrintArr(string text, int[] arr)
        {
            Write(text + ": ");
            for (int i = 0; i < arr.Length; i++)
            {
                Write(arr[i] + " ");
            }
            WriteLine();
        }
    }
}
