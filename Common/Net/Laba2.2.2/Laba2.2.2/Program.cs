using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Laba2._2._2
{
    class Program
    {
        static void Main(string[] args)
        {
            Cube cube1 = new Cube();
            cube1.ThrowCube(350, 5);
            cube1.Draw(cube1.Two, " 2 ");
            cube1.Draw(cube1.Three, " 3 ");
            cube1.Draw(cube1.Four, " 4 ");
            cube1.Draw(cube1.Five, " 5 ");
            cube1.Draw(cube1.Six, " 6 ");
            cube1.Draw(cube1.Sev, " 7 ");
            cube1.Draw(cube1.Ei, " 8 ");
            cube1.Draw(cube1.Nine, " 9 ");
            cube1.Draw(cube1.Ten, " 10 ");
            cube1.Draw(cube1.Elev, " 11 ");
            cube1.Draw(cube1.Tw, " 12 ");
            Console.ReadKey();
        }
    }
}