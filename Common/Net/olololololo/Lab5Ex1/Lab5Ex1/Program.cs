using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Lab5_6ClassLibrary;

namespace Lab5Ex1
{
    class Program
    {
        static void Main(string[] args)
        {
            Random rand = new Random();

            Console.WriteLine(HelloWorld.GetHelloWorld());

            int a = rand.Next(100), b = rand.Next(100);
            Console.WriteLine("{0}+{1}={2}", a, b, Sum1.Sum(a, b));
            
            int n = rand.Next(21);
            int[] arr = new int[n];
            for (int i = 0; i < n; i++)
            {
                arr[i] = rand.Next(100);
                Console.Write(arr[i] + "  ");
            }

            Console.WriteLine("\nSum = " + Sum2.Sum(arr));

            int k = rand.Next(1, (n + 1));
            Console.WriteLine("k = {0} Sum = {1}", k, Sum2.Sum(arr, k));
            Console.ReadKey();
        }
    }
}
