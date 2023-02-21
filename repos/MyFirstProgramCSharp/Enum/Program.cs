using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;

namespace Enum
{
    class Enums
    {
        enum CommodityType
        {
            FrozenFood, Food, DomesticChemistry, BuildingMaterials, Petrol
        }

        enum TransportType
        {
            SemiTrailer, Coupling, Refrigerator, OpenSideTruck, FuelTruck
        }

        enum DistanceSun : ulong
        {
            Sun = 0,
            Mercury = 57900000,
            Venus = 108200000,
            Earth = 149600000,
            Mars = 227900000,
            Jupiter = 7783000000,
            Saturn = 1427000000,
            Uranus = 2870000000,
            Neptune = 4496000000,
            Pluto = 5946000000
        }


        static void Main(string[] args)
        {
            string moon = "Moon";

            if (!Enum.IsDefined(typeof(DistanceSun), moon))
            {
                WriteLine($"\tЗначения {moon} нет в перечислении DistanceSun.");
            }

            WriteLine("\n\tФорматированный вывод всех значений констант указанного перечисления.");
            foreach (DistanceSun item in Enum.GetValues(typeof(DistanceSun)))
            {
                WriteLine("{0,-10} {1,-10} {2,20}", Enum.Format(typeof(DistanceSun), item, "G"), Enum.Format(typeof(DistanceSun), item, "D"), Enum.Format(typeof(DistanceSun), item, "X"));
            }
            WriteLine("\n\tВсе значения констант указанного перечисления");

            foreach (string str in Enum.GetNames(typeof(DistanceSun)))
            {
                WriteLine(str);
            }

            ulong dis = 227900000;
            WriteLine($"\n\tИмя константы со значением {dis} из указанного перечисления.\n");
            WriteLine(Enum.GetName(typeof(DistanceSun), dis));



            WriteLine("Введите число от 1 до 5");
            int number = Int32.Parse(ReadLine());
            if (number > 0 && number < 6)
            {
                CommodityType commodity = (CommodityType)Enum.GetValues(typeof(CommodityType)).GetValue(number - 1);

                TransportType transport = TransportType.SemiTrailer;

                switch (commodity)
                {
                    case CommodityType.FrozenFood:
                        transport = TransportType.Refrigerator;
                        break;
                    case CommodityType.Food:
                        transport = TransportType.SemiTrailer;
                        break;
                    case CommodityType.DomesticChemistry:
                        transport = TransportType.Coupling;
                        break;
                    case CommodityType.BuildingMaterials:
                        transport = TransportType.OpenSideTruck;
                        break;
                    case CommodityType.Petrol:
                        transport = TransportType.FuelTruck;
                        break;
                }
                WriteLine($"Для товара - {commodity} необходим транспорт - {transport}.");
            }
            else
            {
                WriteLine("Ошибка ввода");
            }
        }
    }
}
