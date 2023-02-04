
using static System.Console;
// инверсия массива
/*int[] numbers = { -4, -3, -2, -1, 0, 1, 2, 3, 4 };//4,3,2,1,0,-1,-2, -3,-4
int n=numbers.Length;
int k = (n - 1) / 2;
int temp;
for (int i = 0;i<k;i++)
{
    temp = numbers[i];
    numbers[i] = numbers[n-i-1];
    numbers[n-i-1] = temp;
}
foreach (int i in numbers)
    Write($"{i} \t");*/
//Сортировка массива
/*int[] nums = { 77, 9, -55, 5, 4, 2, 99, 44, -7, 15 };
int temp;
for(int i=0; i<nums.Length-1; i++)
{
    for (int j = i + 1; j < nums.Length; j++)
    {
        if (nums[i] > nums[j])
        {
            temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
        if (nums[i] < nums[j])
        {
            temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
    }
}
WriteLine("Вывод отсортированного массива");
for(int  j=0; j<nums.Length; j++)
    WriteLine(nums[j]);*/
//Visual Studio 2022
/*string hello = "Hello World";
Print(hello);
void Print(string message)
{
    WriteLine(message);
}*/
//до Visual Studio 2022
/*class Program
{
    static void Main(string[] args)
    {
        string hello = "Hello World";
        Print(hello);
        void Print(string message)
        {
            WriteLine(message);
        }
    }
}*/
//Struct
/*Person Ivan=new Person();//Person Ivan =new();//new Person{name="Ivan", age=22}
Ivan.name = "Ivan";
Ivan.Print();
struct Person
{
    public string name;
    public int age;
    public void Print()
    {
        WriteLine($"Имя: {name} Возраст: {age}");
    }
}*/
/*Person Ivan;
Ivan.name = "Ivan";
Ivan.age = 29;
Ivan.Print();
    struct Person
{
    public string name;
    public int age;
    public void Print()
    {
        WriteLine($"Имя: {name} Возраст: {age}");
    }
}*/
//Иницилизация полей по умолчанию
/*Person Ivan=new Person();
Ivan.Print();
struct Person
{
    public string name="Ivan";
    public int age=1;
    public Person() { }
    public void Print()
    {
        WriteLine($"Имя: {name} Возраст: {age}");
    }
}*/
//Конструкторы структуры
/*Person Ivan = new();
Person Petor = new("Petor");
Person Maksim = new("Maksim", 27);
Ivan.Print();
Petor.Print();
Maksim.Print();
struct Person
{
    public string name;
    public int age;
    public Person(string name="Ivan", int age=1)
    {
        this.name = name;
        this.age = age;
    }
    public void Print() => WriteLine($"Имя: {name} Возраст: {age}");
}*/
//C# 11 .Net 7
/*Person Ivan = new();
Person Petor = new("Petor");
Person Maksim = new("Maksim", 27);
Ivan.Print();
Petor.Print();
Maksim.Print();
struct Person
{
    public string name;
    public int age;
    public Person() : this("Ivan")
    { }
    public Person(string name) : this(name, 1)
    { }
    public Person(string name, int age)
    {
        this.name = name;
        this.age = age;
    }
    public void Print() => WriteLine($"Имя: {name} Возраст: {age}");
}*/
//Копирования структуры с помощью with
Person Ivan = new Person() { name = "Ivan", age = 34 };
Person Petor = Ivan with { name = "Petor" };
Petor.Print();
struct Person
{
    public string name;
    public int age;
    public void Print()
    {
        WriteLine($"Имя: {name} Возраст: {age}");
    }
}
/*private
private protected
file
protected
internal
protected internal
public
*/
