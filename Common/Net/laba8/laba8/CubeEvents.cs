using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace laba8
{
    class CubeEvents
    {
        public delegate void HumanDamageEventHandler(object sender, CubeSideArgs e);
        public delegate void HumanEventHandler(object sender, CubeSidesArgs e);
        public delegate void ThrowCubeEventHandler();
        public static void max()
        {
            Console.WriteLine("Випало 6, максимальне число!");
        }
        public static void min()
        {
            Console.WriteLine("Випало 1, мінімальне число!");
        }
        public static void showResult(FunkDelegate funk)
        {
            funk();
        }
        public void onThrow(int n)
        {
            FunkDelegate funk;
            if (r.Next(1, 7) == 1)
            {
                funk = min;
                showResult(funk);
            }
            else if (r.Next(1, 7) == 6)
            {
                funk = max;
                showResult(funk);
            }
            else Console.WriteLine("Щось інше!");
        }
    }
}
