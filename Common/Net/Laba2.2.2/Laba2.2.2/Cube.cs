using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Laba2._2._2
{
    class Cube
    {
        public int One = 0, Two = 0, Three = 0, Four = 0, Five = 0, Six = 0;
        public int Sev = 0, Ei = 0, Nine = 0, Ten = 0, Elev = 0, Tw = 0;
        public void ThrowCube(int n, int m)
        {
            int olx = 0;
            Random r = new Random();
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    olx += r.Next(5)+1;
                }
                switch (olx)
                {
                    case 2: Two++;
                        break;
                    case 3: Three++;
                        break;
                    case 4: Four++;
                        break;
                    case 5: Five++;
                        break;
                    case 6: Six++;
                        break;
                    case 7: Sev++;
                        break;
                    case 8: Ei++;
                        break;
                    case 9: Nine++;
                        break;
                    case 10: Ten++;
                        break;
                    case 11: Elev++;
                        break;
                    case 12: Tw++;
                        break;
                    default: Console.WriteLine("WTF??? 0_o"); break;
                }
            }
        }
        public override string ToString()
        {
            return "2: " + Two + " 3: " + Three + " 4: " + Four + " 5: " + Five + " 6: " + Six + " 7: " + Sev + " 8: " + Ei + " 9: " + Nine + " 10: " + Ten + " 11: " + Elev + " 12: " + Tw;
        }
        public void Draw(int n, string name)
        {
            Console.Write(name + "\t");
            for (int i = 0; i < n; i++)
            {
                Console.Write("*");
            }
            Console.WriteLine("");
        }
    }
}
