using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Laba1._2
{
    class Cube
    {
        public int One = 0, Two = 0, Three = 0, Four = 0, Five = 0, Six = 0;
        public void ThrowCube(int n)
        {
            Random r = new Random();
            for(int i = 0; i < n; i++)
            {
                int o = r.Next(6);
                //Console.WriteLine(o);
                switch (o)
                {
                    case 0: One++; break;
                    case 1: Two++; break;
                    case 2: Three++; break;
                    case 3: Four++; break;
                    case 4: Five++; break;
                    case 5: Six++; break;
                    default: Console.WriteLine("WTF??? 0_o"); break;
                }
            }
        }
        public override string ToString()
        {
            return "1: " + One + " 2: " + Two + " 3: " + Three + " 4: " + Four + " 5: " + Five + " 6: " + Six;
        }
        public void Draw(int n)
        {
            for (int i = 0; i < n; i++)
            {
                Console.Write("*");
            }
            Console.WriteLine("");
        }
    }
}
