using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace laba7cons
{

    delegate void CubeEventHandler();

    class MaxEvent
    {
        public event CubeEventHandler CubeEvent;

        public void OnMyEvent()
        {
            if (CubeEvent != null)
                CubeEvent();
        }
    }

    class MinEvent
    {
        public event CubeEventHandler CubeEvent;

        public void OnMyEvent()
        {
            if (CubeEvent != null)
                CubeEvent();
        }
    }

    class Cube
    {
        int x;

        public Cube(int x)
        {
            this.x = x;
        }

        public bool isMax()
        {
            return x == 6;
        }

        public bool isMin()
        {
            return x == 1;
        }
    }

    class Program
    {
        public static void MaxHandler()
        {
            Console.Write("(max) ");
        }

        public static void MinHandler()
        {
            Console.Write("(min) ");
        }

        static void Main(string[] args)
        {
            MaxEvent myMaxEvent = new MaxEvent();
            MinEvent myMinEvent = new MinEvent();
            myMaxEvent.CubeEvent += MaxHandler;
            myMinEvent.CubeEvent += MinHandler;
            Random r = new Random();
            Console.WriteLine("Введіть кількість разів, яку потрібно кинути кубик!");
            int n = Convert.ToInt32(Console.ReadLine());
            Cube[] kubiks = new Cube[n];
            for (int i = 0; i < n; i++)
            {
                int x = r.Next(1, 7);
                kubiks[i] = new Cube(x);
                Console.Write(" " + x);
                if (kubiks[i].isMax())
                    myMaxEvent.OnMyEvent();
                else if (kubiks[i].isMin())
                    myMinEvent.OnMyEvent();
                Console.WriteLine();
            }
            Console.ReadKey();
        }
    }
}
