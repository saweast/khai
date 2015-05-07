using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TestingLab6
{
    class IntervalDate
    {
        public DateTime DateFrom { get; set; }
        public DateTime DateTo { get; set; }
        public double K1 { get; set; }

        public override string ToString()
        {
            return DateFrom.ToString("dd.MM.yy") + "\t" + DateTo.ToString("dd.MM.yy") + "\t" + K1;
        }
    }
}
