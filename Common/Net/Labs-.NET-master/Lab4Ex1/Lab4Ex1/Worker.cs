using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab4Ex1
{
    class Worker
    {
        string firstName, lastName;
        int age;

        public Worker(string firstName, string lastName, int age)
        {
            this.firstName = firstName;
            this.lastName = lastName;
            if (age >= 0 && age <= 20)
                this.age = 20;
            else if (age >= 70 && age <= 100)
                this.age = 70;
            else
                this.age = age;
        }

        public int Age
        {
            set
            {
                if (value >= 0 && value <= 20)
                    age = 20;
                else if (value >= 70 && value <= 100)
                    age = 70;
                else
                    age = value;
            }
            get
            {
                return age;
            }
        }

        public string FirstName { private set { } get { return firstName; } }
        public string LastName { private set { } get { return lastName; } }

    }
       
}
