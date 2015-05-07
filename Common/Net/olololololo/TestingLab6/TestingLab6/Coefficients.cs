using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TestingLab6
{
    class Coefficient
    {
        public int Sequence { get; set; }
        public double K1 { get; set; }
        public double K2 { get; set; }
        public double K3 { get; set; }

        public override string ToString()
        {
            return K1 + "\t" + K2 + "\t" + K3;
        }
    }
}
