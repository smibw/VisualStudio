using static System.Console;
/*
//TASK 1
try
{
    int checkOut;
    checkOut = 0;
    int checkOut1;
    checkOut1 = 0;
    Write("Введите любое число от 1 до 100: ");
    int number =Convert.ToInt32(ReadLine());
    if(number>0&&number<100)
    {
        checkOut = number % 3;
        checkOut1 = number % 5;
        if (checkOut == 0&&checkOut1!=0)
        {
            WriteLine("Fizz");
        } 
        else if(checkOut!=0&&checkOut1  ==0)
        {
            WriteLine("Buzz");
        } 
        else if(checkOut == 0 && checkOut1 == 0)
        {
            WriteLine("Fizz Buzz");
        }
        else
        {
            WriteLine($"{number}");
        }
    }
    else
    {
        WriteLine("Error!");
    }
}
catch(Exception ex)
{
    WriteLine($"Исключение {ex.Message}");
    WriteLine($"Метод: {ex.TargetSite}");
    WriteLine($"Трассировка стека: {ex.StackTrace}");
}
*/
/*
        TASK 2
try
{
    Write("Введите любое число: ");
    int number = Convert.ToInt32(ReadLine());
    Write("Введите процент, который необходимо посчитать: ");
    double proportion = Convert.ToInt32(ReadLine());
    if(proportion>0&&proportion<100&&number>0)
    {
        double result = number * (proportion/100);
        WriteLine($"Результат вычислений: {result}");
    }
    else if(proportion==100)
    {
        WriteLine($"Значение остается неизменным... {number}");
    }
    else if(proportion>100)
    {
        double result = number * (proportion / 100);
     WriteLine($"Результат вычислений: {result}");
    }
    else
    {
     WriteLine("Error!");
    }
}
catch (Exception ex)
{
    WriteLine($"Исключение {ex.Message}");
    WriteLine($"Метод: {ex.TargetSite}");
    WriteLine($"Трассировка стека: {ex.StackTrace}");
}
*/

    Console.Write("N = ");
    int n = Convert.ToInt32(Console.ReadLine());
    int[] a = new int[n];
    for (int i = 0; i < n; i++)
    {
        Console.Write($"A[{i + 1}] = ");
        a[i] = Convert.ToInt32(Console.ReadLine());
    }
   for(int i=0; i<n; i++)
    {
        WriteLine(a[i]);
    }
