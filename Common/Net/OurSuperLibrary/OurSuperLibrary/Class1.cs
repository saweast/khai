using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OurSuperLibrary
{
    public class Class_HelloWorld
    {
        const string strHelloWorld = "Вадим, Віталій, Катерина, Ярослав";
        public static string HelloWorld() { return strHelloWorld; }
    }
    public class Class_Sum1
    {
        public static double sum1(double a, double b)
        {
            return a + b;
        }
    }
    public class Class_Sum2
    {
        public static double sum1(double[] a)
        {
            double summ = 0;
            for (int i = 0; i < a.Length - 1; i++)
                summ += a[i];
            return summ;
        }
        public static double sum1(double[] a, int k)
        {
            double summ = 0;
            if (k < a.Length)
            {
                for (int i = 0; i < k; i++)
                    summ += a[i];
                return summ;
            }
            else
            {
                for (int i = 0; i < a.Length-1; i++)
                    summ += a[i];
                return summ;
            }
        }
    }
}
