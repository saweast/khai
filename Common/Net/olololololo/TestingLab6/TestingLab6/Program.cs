using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

namespace TestingLab6
{
    class Program
    {
        static void Main(string[] args)
        {
            List<IntervalDate> intervalDates = WorkWithFile.GetData();
            List<Coefficient> coefs = ProcessingData.GetCoefficients(intervalDates);

            WorkWithDB workWithDB = new WorkWithDB();
            workWithDB.DeleteCoefficientsFromDB();
            workWithDB.InsertCoefficients(coefs);
            coefs = workWithDB.GetUniqueCoefficients();

            WorkWithFile.SaveDataInFile(coefs);
            Console.WriteLine("Data successfully saved!");

            Console.ReadLine();
        }
    }
}
