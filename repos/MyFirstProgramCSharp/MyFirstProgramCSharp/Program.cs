using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MyFirstProgramCSharp
{
    internal class Quiz
    {
        static void Main(string[] args)
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
                        }
                        else
                        {
                            help = false;
                        }
                        if(help)
                        {
                            Console.WriteLine(UsefulHelper[i]);
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
    }
}
