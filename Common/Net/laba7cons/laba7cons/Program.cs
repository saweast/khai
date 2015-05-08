using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace laba7cons
{
    class Program
    {
        public delegate double FunkDelegate(double X);
        public static double meth1(double x)
        {
            return Math.Pow(x, 2);
        }
        public static double meth2(double x)
        {
            return Math.Cos(x);
        }
        public static void Printable(double x, int dx, int count, FunkDelegate funk)
        {
            double y = x;
            for (double i = 0; i < count; i++)
            {
                Console.WriteLine("{0} = " + funk(y), y);
                y += dx;
            }
        }
        static void Main(string[] args)
        {
            FunkDelegate funk = meth1;
            Console.WriteLine("Vvedite znachenie x: ");
            double x = Convert.ToDouble(Console.ReadLine());
            Console.WriteLine("Vvedite znachenie shag: ");
            int dx = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Vvedite znachenie kolichestvo: ");
            int count = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Stepin");
            Printable(x, dx, count, funk);
            funk = meth2;
            Console.WriteLine("Cos");
            Printable(x, dx, count, funk);

            Console.ReadKey();
        }
    }
}
