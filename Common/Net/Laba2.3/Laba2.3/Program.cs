using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Laba2._3
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = 0, m = 0, cubes = 0;
            Random rand = new Random();
            n = Convert.ToInt32(Console.ReadLine());
            m = Convert.ToInt32(Console.ReadLine());
            int[] results = new int[m];
            for (int j = 0; j < m; j++)
            {
                cubes = 0;
                for (int i = 0; i < n; i++)
                {
                    cubes += rand.Next(6) + 1;
                }
                results[j] = cubes;
            }
            int[] uniq = new int[m*n*6];
            for (int i = 0; i < n*6+1; i++)
            {
                for(int j = 0; j < m; j++)
                {
                    if (results[j] == i)
                        uniq[i]++;
                }
            }
            for (int i = 1; i < n * 6 + 1; i++)
                Draw(uniq[i], i);
            Console.ReadLine();
        }
        public static void Draw(int k, int name)
        {
            Console.Write(name + "\t");
            for (int i = 0; i < k; i++)
            {
                Console.Write("*");
            }
            Console.WriteLine("");
        }
    }
}
