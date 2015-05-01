using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab5_6ClassLibrary
{
    public class HelloWorld
    {
        public static string GetHelloWorld()
        {
            return "Hello, World!";
        }
    }

    public class Sum1
    {
        public static int Sum(int a, int b)
        {
            return a + b;
        }
    }

    public class Sum2
    {
        public static int Sum(int[] arr)
        {
            int sum = 0;
            for (int i = 0; i < arr.Length; i++)
                sum += arr[i];
            return sum;
        }

        public static int Sum(int[] arr, int k)
        {
            if (k > 0 && k <= arr.Length)
            {
                int sum = 0;
                for (int i = 0; i < k; i++)
                    sum += arr[i];
                return sum;
            }
            else return -1;
        }
    }
}
