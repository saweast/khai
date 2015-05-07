using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TestingLab6
{
    static class ProcessingData
    {
        public static List<Coefficient> GetCoefficients(List<IntervalDate> intervalDates)
        {
            Random rand = new Random();
            List<Coefficient> coefs = new List<Coefficient>();
            Coefficient bufCoef;
            int sequence = 0;
            foreach (IntervalDate intervalDate in intervalDates)
            {
                for(DateTime dt = intervalDate.DateFrom; dt <= intervalDate.DateTo; dt = dt.AddDays(1))
                {
                    bufCoef = new Coefficient();
                    bufCoef.K1 = intervalDate.K1;

                    if (dt.DayOfWeek == DayOfWeek.Tuesday || dt.DayOfWeek == DayOfWeek.Wednesday)
                        bufCoef.K2 = 0.9;
                    else if (dt.DayOfWeek == DayOfWeek.Friday || dt.DayOfWeek == DayOfWeek.Sunday)
                        bufCoef.K2 = 1.1;
                    else
                        bufCoef.K2 = 1;

                    int result = rand.Next(0, 2);
                    if (result == 0)
                        bufCoef.K3 = 1;
                    else
                        bufCoef.K3 = 0.5;

                    bufCoef.Sequence = sequence;

                    coefs.Add(bufCoef);
                }
                sequence++;
            }
            return coefs;
        }
    }
}
