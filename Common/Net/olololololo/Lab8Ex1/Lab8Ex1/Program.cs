using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab8Ex1
{
    delegate void MyEventHandler();

    class MyEventMax
    {
        public event MyEventHandler SomeEvent;

        public void OnSomeEvent()
        {
            if (SomeEvent != null)
                SomeEvent();
        }
    }

    class MyEventMin
    {
        public event MyEventHandler SomeEvent;

        public void OnSomeEvent()
        {
            if (SomeEvent != null)
                SomeEvent();
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
            Console.WriteLine("This is max");
        }

        public static void MinHandler()
        {
            Console.WriteLine("This is min");
        }

        static void Main(string[] args)
        {
            Random r = new Random();
            int n = r.Next(1, 21);
            Cube[] cubes = new Cube[n];
            Console.WriteLine("n=" + n);
            for (int i = 0; i < n; i++)
            {
                int x = r.Next(1, 7);
                cubes[i] = new Cube(x);
                Console.Write(x + " ");
            }
            Console.WriteLine();

            MyEventMax myEventMax = new MyEventMax();
            MyEventMin myEventMin = new MyEventMin();

            myEventMax.SomeEvent += MaxHandler;
            myEventMin.SomeEvent += MinHandler;

            for(int i = 0; i < n; i++)
            {
                if(cubes[i].isMax()) 
                    myEventMax.OnSomeEvent();
                else if(cubes[i].isMin()) 
                    myEventMin.OnSomeEvent();
            }

            Console.ReadKey();
        }
    }
}
