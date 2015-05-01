using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab4Ex1
{
    class Workers
    {
        List<Worker> workers;
        Random r;
        public Workers(){
            workers = new List<Worker>();
            r = new Random();
         
        }

        public void Generate()
        {
            int count = r.Next(10, 30);

            for (int i = 0; i < count; i++)
                workers.Add(new Worker("FirstName" + i, "LastName" + i, r.Next(0, 101)));
        }

        public void Clear()
        {
            workers.Clear();
        }

        public Worker this[int index]
        {
            get
            {
                return workers[index];
            }
            private set { }
        }

        public int Count { get { return workers.Count; } private set { } }
    }
}