using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;

namespace MyFirstProgramCSharp
{
    internal class Program
    {
        static void startQuiz()
        {
            string[] question =
            {
                "Зимой и летом одним цветом?",
                "Самая высокая гора?",
                "Самая длинная река?",
                "Самый большой океан?",
                "Самая большая планета?"
            };
            string[] answers =
            {
                "ёлка",
                "эверест",
                "амазонка",
                "тихий",
                "юпитер",
            };
            string[] ExtraAnswers =
            {
                "сосна",
                "джомолунгма",
                "нил",
                "великий",
                "экзопланета wasp-17 b"
            };
            string[] Helper =
            {
                "**** или *****",
                "******* или ***********",
                "******** или ***",
                "***** или *******",
                "****** или *********** ****-** *"
            };
            string[] UsefulHelper =
            {
                "Вечнозеленое растение",
                "Входит в горную систему Гималаи",
                "Южноамериканская река или африканская река",
                "Расположен между Евразией, Австралией на западе и Америками на востоке",
                "5я планета в Солнечной системе или первая ретроградная планета"
            };
            string userAnswer;
            int counterOfRightAnswers = 0;
            bool restart = false;
            bool help = false;
            do
            {

                for (int i = 0; i < question.Length; i++)
                {
                    Console.WriteLine(question[i]);
                    userAnswer = Console.ReadLine();
                    if (
                        userAnswer == answers[i] || userAnswer == ExtraAnswers[i]
                        || userAnswer.ToLower() == answers[i] || userAnswer.ToLower() == ExtraAnswers[i]
                       )
                    {
                        counterOfRightAnswers++;
                        Console.WriteLine("Ответ верный!");
                    }
                    else
                    {
                        Console.WriteLine("Ответ неверный!");
                        Console.WriteLine(Helper[i]);
                        Console.WriteLine("Вам необходима более точная подсказка?");
                        userAnswer = Console.ReadLine();
                        if(userAnswer == "ДА" || userAnswer == "да" || userAnswer == "Да")
                        {
                            help = true;
                            if (help)
                            {
                                Console.WriteLine(UsefulHelper[i]);
                            }
                            i--;
                        }
                        else
                        {
                            help = false;
                        }
                        
                    }
                }
                Console.WriteLine("Хотите начать заново?");
                userAnswer = Console.ReadLine();
                if (userAnswer == "ДА" || userAnswer == "да" || userAnswer == "Да")
                {
                    restart = true;
                }
                else
                {
                    restart = false;
                }
                Console.WriteLine("Правильных ответов: " + counterOfRightAnswers);
                if (counterOfRightAnswers == 5)
                {
                    Console.WriteLine("А вы отлично знаете основы!");
                    Console.WriteLine("Ваша оценка: 5");
                }
                else if (counterOfRightAnswers == 4)
                {
                    Console.WriteLine("Неплохое знание матчасти!");
                    Console.WriteLine("Ваша оценка: 4");
                }
                else if (counterOfRightAnswers == 3)
                {
                    Console.WriteLine("Посредственное знание предмета!");
                    Console.WriteLine("Ваша оценка: 3");
                }
                else
                {
                    Console.WriteLine("Вы вообще хоть что-то знаете о мире?");
                    Console.WriteLine("Ваша оценка: 2");
                }
            } while (restart);
        }

        static void guessNumber()
        {
            Random rand = new Random();
            int magicNumber = rand.Next(0, 100);
            int userNumber = 0;
            int count = 0;
            int maxTries = 7;

            do
            {
                Write("Введи число: ");
                userNumber = Int32.Parse(ReadLine());
                count++;
                if (maxTries == 0)
                {
                    WriteLine("Вы проиграли...");
                    WriteLine("*звучит грустная музыка*");
                    break;
                }
                if (userNumber < magicNumber)
                {
                    WriteLine("Загаданное число больше!");
                    maxTries--;
                    WriteLine("У вас осталось " + maxTries + " попыток");
                }
                else if (userNumber > magicNumber)
                {
                    WriteLine("Загаданное число меньше!");
                    maxTries--;
                    WriteLine("У вас осталось " + maxTries + " попыток");
                }
                else if (userNumber == magicNumber)
                {
                    WriteLine("Ты угадал! Тебе понадобилось " + count + " попыток");
                    break;
                }
            } while (userNumber != magicNumber||maxTries!=0);
        }

        static void MainMenu()
        {
                int userMessage = 0;
            do
            {
                WriteLine("\t\tГлавное меню");
                WriteLine("1. startQuiz");
                WriteLine("2. guessNumber");
                WriteLine("Чтобы выйти нажмите 0.");
                WriteLine("\nВыберите игру.");
                userMessage = Int32.Parse(ReadLine());
                if (userMessage == 1)
                {
                    startQuiz();
                }
                else if (userMessage == 2)
                {
                    guessNumber();
                }
                else if (userMessage == 0)
                {
                    WriteLine("Уже покидаете нас?");
                }
                else
                {
                    WriteLine("Команда не распознана!");
                }
            } while (userMessage != 0);
        }

        static void Main(string[] args)
        {
            MainMenu();
        }
    }
}
