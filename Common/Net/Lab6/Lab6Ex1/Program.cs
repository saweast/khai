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
        static int[] getArrInt(Random rand, int n)
        {
            int[] a = new int[n];
            for (int i = 0; i < n; i++) a[i] = rand.Next(10);
            return a;
        }

        static void PrintArr(int[] a)
        {
            string s = "";
            for (int i = 0; i < a.Length; i++) s += a[i] + "  ";
            Console.WriteLine("Array: " + s);
        }

        static void Main(string[] args)
        {
            Random rand = new Random();

            Type[] arrT = Assembly.LoadFrom("../../OurSuperLibrary.dll").GetTypes();
            Type type = Assembly.LoadFrom("../../OurSuperLibrary.dll").GetType("OurSuperLibrary.Class_HelloWorld", true);
            Console.WriteLine(type.GetMethod("HelloWorld").Invoke(null, null));

            int a = rand.Next(100), b = rand.Next(100);
            type = Assembly.LoadFrom("../../OurSuperLibrary.dll").GetType("OurSuperLibrary.Class_Sum1", true);
            Console.WriteLine("{0} + {1} = {2}", a, b, type.GetMethod("sum1").Invoke(null, new object[] { a, b }));

            int n = rand.Next(3, 11);
            double[] array = new double[n];
            for (int i = 0; i < n; i++)
            {
                array[i] = rand.Next(10);
                Console.Write(array[i] + "  ");
            }

            type = Assembly.LoadFrom("../../OurSuperLibrary.dll").GetType("OurSuperLibrary.Class_Sum2", true);
            Console.WriteLine("\nSum = " + type.GetMethod("sum1", new Type[] { typeof(double[]) }).Invoke(null, new object[] { array }));

            int count = rand.Next(1, (n + 1));

            int nArrT = arrT.Length;
            MethodInfo[][] arrMI = new MethodInfo[nArrT][];
            for (int i = 0; i < nArrT; i++)
                arrMI[i] = arrT[i].GetMethods();
            Console.WriteLine("k = {0} Sum = {1}", count, type.GetMethod("sum1", new Type[] { typeof(double[]), typeof(int) }).Invoke(null, new object[] { array, count }));

            Console.ReadKey();
        }
    }
}
