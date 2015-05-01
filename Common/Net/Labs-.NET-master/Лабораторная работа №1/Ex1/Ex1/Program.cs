using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ex1
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = 10;
            int[] arr = new int[n];
            Random r = new Random();
            for (int i = 0; i < n; i++){
                arr[i] = r.Next(20);
                if (r.Next(20) % 2 != 0)
                    arr[i] = -1 * r.Next(20);
            }                

            for (int i = 0; i < n; i++) 
                Console.WriteLine(arr[i]);

            int[] s = new int[3];

            for (int i = 0; i < n; i++){
                s[0] += arr[i];
                if ((i + 1) % 2 == 0)
                    s[1] += arr[i];
            }

            int j = 0;

            while (j < n && arr[j] > 0)
            {
                s[2] += arr[j];
                j++;
            }

            for (int i = 0; i < s.Length ; i++)
                Console.WriteLine("s" + i + " = " + s[i]);

            Console.ReadLine();
            
        }
    }
}
