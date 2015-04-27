using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Reflection;

namespace Lab6E
{
    class Program
    {
        static void Main(string[] args)
        {
            Random rand = new Random();

            Type[] arrT = Assembly.LoadFrom("../../OurSuperLibrary.dll").GetTypes();
            Type type = Assembly.LoadFrom("../../OurSuperLibrary.dll").GetType("OurSuperLibrary.Class_HelloWorld", true);
            Console.WriteLine(type.GetMethod("HelloWorld").Invoke(null, null));

            int a = rand.Next(100), b = rand.Next(100);
            type = Assembly.LoadFrom("../../OurSuperLibrary.dll").GetType("OurSuperLibrary.Class_Sum1", true);
            Console.WriteLine("{0} + {1} = {2}", a, b, type.GetMethod("sum1").Invoke(null, new object[] { a, b }));

            double[] array = new double[10];
            for (int i = 0; i < 10; i++)
            {
                array[i] = rand.Next(10);
                Console.Write(array[i] + "  ");
            }

            type = Assembly.LoadFrom("../../OurSuperLibrary.dll").GetType("OurSuperLibrary.Class_Sum2", true);
            Console.WriteLine("\nSum = " + type.GetMethod("sum1", new Type[] { typeof(double[]) }).Invoke(null, new object[] { array }));
            int count = 5;
            int nArrT = arrT.Length;
            MethodInfo[][] arrMI = new MethodInfo[nArrT][];
            for (int i = 0; i < nArrT; i++)
                arrMI[i] = arrT[i].GetMethods();
            Console.WriteLine("k = {0} Sum = {1}", count, type.GetMethod("sum1", new Type[] { typeof(double[]), typeof(int) }).Invoke(null, new object[] { array, count }));

            Console.ReadKey();
        }
    }
}
