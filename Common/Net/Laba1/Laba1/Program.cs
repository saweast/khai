using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Laba1
{
    class Program
    {
        static void Main(string[] args)
        {
            int sum = 0, sum2 = 0, g = 0;
            int[] mas = {5, 10, 15, 15, 48, 50, -30, 20, 7, 50};
            try
            {
                for (int i = 0; i < mas.Length; i++)
                {
                    if (i % 2 == 0)
                        sum += mas[i];
                }
                while (mas[g] >= 0)
                {
                    sum2 += mas[g];
                    g++;
                }
                Console.WriteLine("Sum do vid: " + sum2);
            }
            catch { Console.WriteLine("Немає від'ємних!"); Console.ReadKey(); }
            Console.WriteLine("Parn miscya: " + sum);
            Console.ReadKey();
        }
    }
}
