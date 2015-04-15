using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Reflection;

namespace Laba6
{
    class Program
    {
        static void Main(string[] args)
        {
            Assembly Super;
            Super = System.Reflection.Assembly.LoadFrom("OurSuperLibrary.dll");
            MethodInfo Method = Super.GetTypes()[0].GetMethod("sum1");
            double[] arr = { 1, 2, 3, 4, 5 };
            Console.WriteLine(Class_HelloWorld.HelloWorld());
            Console.WriteLine("Enter a b");
            Console.WriteLine("summ = " + Class_Sum1.sum1(Convert.ToDouble(Console.ReadLine()),
                Convert.ToDouble(Console.ReadLine())));
            Console.WriteLine("mas = 1,2,3,4,5" + "summ = " + Class_Sum2.sum1(arr));
            Console.WriteLine("Enter k. k must be < 5");
            Console.WriteLine("mas = 1,2,3,4,5 " + "summ = " + Class_Sum2.sum1(arr, Convert.ToInt32(Console.ReadLine())));
            Console.ReadLine();
        }
    }
}
