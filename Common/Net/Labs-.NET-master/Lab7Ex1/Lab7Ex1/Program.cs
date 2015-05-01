using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab7Ex1
{
    
    class Program
    {
        public delegate double getFunc(double x);
        
        static void Main(string[] args)
        {
            Random r = new Random();

            Console.WriteLine("getXPow5:");
            int n = r.Next(1, 12);
            getFunc get_func = new getFunc(getXPow5);
            printTable(r.NextDouble() * r.Next(1, 21), r.NextDouble() * r.Next(1, 21), n, get_func);

            Console.WriteLine();

            Console.WriteLine("getXSin:");
            get_func = new getFunc(getXSin);
            n = r.Next(1, 12);
            printTable(r.NextDouble() * r.Next(1, 21), r.NextDouble() * r.Next(1, 21), n, get_func);

            Console.ReadKey();
        }

        public static double getXPow5(double x)
        {
            return Math.Pow(x, 5);
        }

        public static double getXSin(double x)
        {
            return Math.Sin(x);
        }

        public static void printTable(double x0, double dx, int count, getFunc get_func) {

            Console.WriteLine("xi \t\t\t\t\t fi");
            for(int i=0; i < count; i++) {
                Console.WriteLine(x0 + "\t\t\t" + get_func(x0));
                x0 += dx;
            }
        }
    }
}
