using static System.Console;

//Статическое поле класса
/*
Person bob = new(68);
bob.CheckAge();

Person bred = new(34);
bred.CheckAge();
WriteLine(Person.retirementAge);
Person.retirementAge = 67;
WriteLine(Person.retirementAge);

class Person
{
    int age;
    public static int retirementAge = 65;
    public Person(int age)
    {
        this.age = age;
    }
    public void CheckAge()
    {
        if (age >= retirementAge)
            WriteLine("Уже на пенсии");
        else
            WriteLine($"Сколько лет осталось до пенсии: {retirementAge - age}");
    }
}
*/

/*
//Статические свойства
Person ted = new(70);
ted.CheckAge();
WriteLine(Person.RetirementAge);
Person.RetirementAge = 72;
WriteLine(Person.RetirementAge);
class Person
{
    int age;
    public static int retirementAge = 65;
    public static int RetirementAge
    {
        get { return retirementAge; }
        set { if (value > 1 && value < 100) retirementAge = value; }
    }
    public Person(int age)
    {
        this.age = age;
    }
    public void CheckAge()
    {
        if (age >= retirementAge)
            WriteLine("Уже на пенсии");
        else
            WriteLine($"Сколько лет осталось до пенсии: {retirementAge - age}");
    }
}
*/

/*
//Статические методы
Person ted = new(71);
Person.CheckRetirementStatus(ted);
class Person
{
    public int Age { get; set;}
    static int retirementAge = 65;
    public Person(int age) => Age = age;
    public static void CheckRetirementStatus(Person person)
    {
        if (person.Age >= retirementAge)
            WriteLine("Уже на пенсии");
        else
            WriteLine($"Сколько лет осталось до пенсии: {retirementAge}");
    }
}
*/

//Статический конструктор

class Person
{
    static int retirementAgeM = 65;
    static int retirementAgeW = 55;
    bool gender;
    int age;
    public void SetAge (int age )
    {
        this.age = age;
    }
    public int Age()
    {
        return age;
    }
    public void SetFemale(bool female)
    {
        this.gender = gender;
    }
    public bool Gender()
    {
        return gender;
    }
  public Person(int age, bool gender)
    {
        SetAge(age);
        SetGender(gender);
    }
}