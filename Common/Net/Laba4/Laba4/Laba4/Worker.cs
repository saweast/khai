using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Laba4
{
    class Worker
    {
        public String FirstName = "";
        public String LastName = "";
        private int Age = 0;
        public void setAge(int digit)
        {
            if (0 < digit && digit < 20)
                Age = 20;
            else
                if (70 < digit && digit < 100)
                    Age = 20;
                else Age = digit;
        }
        public int getAge() { return Age; }
    }
}
