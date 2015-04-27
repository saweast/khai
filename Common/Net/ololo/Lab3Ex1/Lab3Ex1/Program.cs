using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab3Ex1
{
    class Worker
    {
        public virtual void Print()
        {
            Console.WriteLine("Worker");
        }
    }

    class Boss : Worker
    {
      
        /*public void Print()
        {
            Console.WriteLine("Boss");
        }*/

        /*public new void Print()
        {
            Console.WriteLine("Boss");
        }*/

        public override void Print()
        {
            Console.WriteLine("Boss");
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Worker wr = new Boss();

            wr.Print();

            Console.ReadLine();
        }
    }
}
