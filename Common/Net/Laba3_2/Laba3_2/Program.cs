using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Laba3_2
{
    class Person
    {
        public virtual void PrintPerson()
        {
            Console.WriteLine("Person");
        }
    }

    class Boy : Person
    {
        public override void PrintPerson()
        {
            Console.WriteLine("Malchik");
        }
    }

    class Girl : Person
    {
        public override void PrintPerson()
        {
            Console.WriteLine("Devochka");
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Random r = new Random();
            int n = 10;
            Person[] persons = new Person[n];
            for (int i = 0; i < n; i++)
            {
                if (r.Next(0, 2) == 0)
                    persons[i] = new Boy();
                else
                    persons[i] = new Girl();
            }
            for (int i = 0; i < persons.Length; i++)
                persons[i].PrintPerson();
            Console.ReadLine();
        }
    }
}
