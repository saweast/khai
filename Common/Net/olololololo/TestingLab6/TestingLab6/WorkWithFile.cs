using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TestingLab6
{
    static class WorkWithFile
    {
        public static List<IntervalDate> GetData()
        {
            List<IntervalDate> intervalDates = new List<IntervalDate>();
            IntervalDate intervalDate;

            string line = "";

            string[] splitReadString = new string[2];
            string[] splitDateFromAndTo = new string[2];
            string[] splitDayAndMonth = new string[2];

            using(StreamReader sr = new StreamReader("data.txt"))
            {
                while ((line = sr.ReadLine()) != null)
                {
                    intervalDate = new IntervalDate();

                    splitReadString = line.Split('*');
                    splitDateFromAndTo = splitReadString[0].Split('-');

                    if (splitDateFromAndTo.Length == 2)
                    {
                        splitDayAndMonth = splitDateFromAndTo[0].Split('.');
                        intervalDate.DateFrom = new DateTime(2012, Int32.Parse(splitDayAndMonth[1]), Int32.Parse(splitDayAndMonth[0]));

                        splitDayAndMonth = splitDateFromAndTo[1].Split('.');
                        intervalDate.DateTo = new DateTime(2012, Int32.Parse(splitDayAndMonth[1]), Int32.Parse(splitDayAndMonth[0]));
                    }
                    else
                    {
                        splitDayAndMonth = splitReadString[0].Split('.');
                        intervalDate.DateFrom = new DateTime(2012, Int32.Parse(splitDayAndMonth[1]), Int32.Parse(splitDayAndMonth[0]));
                        intervalDate.DateTo = intervalDate.DateFrom;
                    }
                    intervalDate.K1 = Double.Parse(splitReadString[1]);
                    intervalDates.Add(intervalDate);
                }
            }
            
            return intervalDates;
        }

        public static void SaveDataInFile(List<Coefficient> coefs)
        {
            using(StreamWriter sw = new StreamWriter("Coefficients.txt"))
            {
                sw.WriteLine("K1\tK2\tK3");
                foreach (Coefficient coef in coefs)
                {
                    sw.WriteLine(coef);
                }
            }
        }
    }
}
