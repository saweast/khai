using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Reflection;

namespace Lab6Ex1
{
    class Program
    {
        /// <summary>
        /// Generate array dynamically
        /// </summary>
        /// <param name="rand">Reference by object of type Random</param>
        /// <param name="n">Count elements in array</param>
        /// <returns>Generated array</returns>
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

            Type[] arrT = Assembly.LoadFrom("../../Lab5_6ClassLibrary.dll").GetTypes();

            #region All dynamically
            MethodInfo[] bufArrMI = null;
            ParameterInfo[] bufArrPI = null;
            foreach(Type _type in arrT)
            {
                bufArrMI = _type.GetMethods();
                foreach(MethodInfo mi in bufArrMI)
                {
                    bufArrPI = mi.GetParameters();
                    int nArrPI = bufArrPI.Length;
                    Object[] arrObj = new Object[nArrPI];
                    int number = rand.Next(3, 11);
                    for (int j = 0; j < nArrPI; j++)
                    {
                        if (bufArrPI[j].ParameterType == typeof(int))
                            arrObj[j] = rand.Next(1, (number + 1));
                        if (bufArrPI[j].ParameterType == typeof(int[]))
                            arrObj[j] = getArrInt(rand, number);
                    }
                    if(mi.Name != "Equals" && mi.Name != "GetHashCode" && mi.Name != "GetType" && mi.Name != "ToString")
                    {
                        if (nArrPI == 0)
                            Console.WriteLine(mi.Invoke(null, null) + "\n");
                        else if (nArrPI == 1)
                        {
                            int[] arr = arrObj[0] as int[];
                            if(arr != null)
                            {
                                PrintArr(arr);
                                Console.WriteLine("Sum = " + mi.Invoke(null, arrObj) + "\n");
                            }
                        }
                        else if (nArrPI == 2 && bufArrPI[0].ParameterType == typeof(int) && bufArrPI[1].ParameterType == typeof(int))
                        {
                            Console.WriteLine(
                                arrObj[0].ToString() + " + " + arrObj[1].ToString()
                                + " = " + mi.Invoke(null, arrObj) + "\n"
                            );
                        }

                        else if (nArrPI == 2 && bufArrPI[0].ParameterType == typeof(int[]) && bufArrPI[1].ParameterType == typeof(int))
                        {
                            int[] arr = arrObj[0] as int[];
                            if (arr != null)
                            {
                                Console.WriteLine("k = " + arrObj[1]);
                                PrintArr(arr);
                                Console.WriteLine("Sum = " + mi.Invoke(null, arrObj) + "\n");
                            }
                        }
                    }
                }
            }
            #endregion

            Type type = Assembly.LoadFrom("../../Lab5_6ClassLibrary.dll").GetType("Lab5_6ClassLibrary.HelloWorld", true);
            Console.WriteLine(type.GetMethod("GetHelloWorld").Invoke(null, null));

            int a = rand.Next(100), b = rand.Next(100);
            type = Assembly.LoadFrom("../../Lab5_6ClassLibrary.dll").GetType("Lab5_6ClassLibrary.Sum1", true);
            Console.WriteLine("{0} + {1} = {2}", a, b, type.GetMethod("Sum").Invoke(null, new object[] { a, b }));

            int n = rand.Next(3, 11);
            int[] array = new int[n];
            for (int i = 0; i < n; i++)
            {
                array[i] = rand.Next(10);
                Console.Write(array[i] + "  ");
            }

            type = Assembly.LoadFrom("../../Lab5_6ClassLibrary.dll").GetType("Lab5_6ClassLibrary.Sum2", true);
            Console.WriteLine("\nSum = " + type.GetMethod("Sum", new Type[] { typeof(int[]) }).Invoke(null, new object[] { array }));

            int count = rand.Next(1, (n + 1));

            int nArrT = arrT.Length;
            MethodInfo[][] arrMI = new MethodInfo[nArrT][];
            for (int i = 0; i < nArrT; i++)
                arrMI[i] = arrT[i].GetMethods();

            //Call by index
            Console.WriteLine("k = {0} Sum = {1}", count, arrMI[2][1].Invoke(null, new object[] { array, count }));

            //Call by method name
            Console.WriteLine("k = {0} Sum = {1}", count, type.GetMethod("Sum", new Type[] { typeof(int[]), typeof(int) }).Invoke(null, new object[] { array, count }));

            Console.ReadKey();
        }
    }
}
