using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Laba1._2
{
    class Program
    {
        static void Main(string[] args)
        {
            Cube cube1 = new Cube();
            cube1.ThrowCube(1000);
            Console.WriteLine(cube1.ToString());
            cube1.Draw(cube1.One);
            cube1.Draw(cube1.Two);
            cube1.Draw(cube1.Three);
            cube1.Draw(cube1.Four);
            cube1.Draw(cube1.Five);
            cube1.Draw(cube1.Six);
            
            Console.ReadKey();
        }
    }
}
