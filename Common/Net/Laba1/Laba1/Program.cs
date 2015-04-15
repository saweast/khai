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
            int[] mas = {1, 1, 1, 1, 1, -4};

                for (int i = 0; i < mas.Length; i++)
                {
                    if (i % 2 == 0)
                        sum += mas[i];
                }
                while (g < mas.Length && mas[g] >= 0)
                    //while (mas[g] >= 0 && g < mas.Length)
                {
                    sum2 += mas[g];
                    g++;
                }
                Console.WriteLine("Sum do vid: " + sum2);
            Console.WriteLine("Parn miscya: " + sum);
            Console.ReadKey();
        }
    }
}
