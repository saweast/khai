using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Laba3_1
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
        public override void Print()
        {
            Console.WriteLine("Boss");
        }
    }

    class Program
    {
        static void Main(string[] args)
        {

            Worker worker = new Boss();
            worker.Print();
            Console.ReadLine();
        }
    }
}