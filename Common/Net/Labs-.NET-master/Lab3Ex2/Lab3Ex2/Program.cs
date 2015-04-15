using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab3Ex2
{
    class Person
    {
        public virtual void PrintPerson()
        {
            Console.WriteLine("Base - Person");
        }
    }

    class Boy : Person
    {
        public override void PrintPerson()
        {
            Console.WriteLine("Boy");
        }
    }

    class Girl : Person
    {
        public override void PrintPerson()
        {
            Console.WriteLine("Girl");
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Person per = new Person();
            per.PrintPerson();

            per = new Boy();
            per.PrintPerson();

            per = new Girl();
            per.PrintPerson();

            Random r = new Random();

            int n = 20;
            Person[] personMas = new Person[n];
            for (int i = 0; i < n; i++)
            {
                if (r.Next(0, 2) == 0)
                    personMas[i] = new Boy();
                else
                    personMas[i] = new Girl();
            }

            foreach(Person p in personMas)
            {
                p.PrintPerson();
            }

            Console.ReadLine();
        }
    }
}
