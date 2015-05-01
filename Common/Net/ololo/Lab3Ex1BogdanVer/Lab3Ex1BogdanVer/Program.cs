using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab3Ex1BogdanVer {

    /// <summary>
    /// Base class
    /// </summary>
    class Worker
    {
        public void say()
        {
            Console.Write("Здравствуйте босс \n");
        }

        public void say2()
        {
            Console.Write("Здравствуйте босс \n");
        }

        public virtual void say3()
        {
            Console.Write("Здравствуйте босс \n");
        }
    }

    class Boss : Worker
    {
        public void say()
        {
            Console.Write("Привет подчиненный \n");
        }

        new public void say2()
        {
            Console.Write("Привет подчиненный \n");
        }

        public override void say3()
        {
            Console.Write("Привет подчиненный \n");
        }
    }

    class Program {
        static void Main(string[] args) {

            Worker w = new Boss();

            w.say();
            w.say2();
            w.say3();

            Console.ReadKey();
        }
    }
}
