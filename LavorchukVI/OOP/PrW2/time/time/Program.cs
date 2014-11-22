using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace time
{
    class Program
    {
        class clockTime
        {
            private int hours = 0, minutes = 0, seconds = 0;
            // конструктори
            public clockTime() 
            {
                hours = 5;
                minutes = 30;
                seconds = 30;
            }
            public clockTime(int hours, int minutes, int seconds)
            {
                this.hours = hours;
                this.minutes = minutes;
                this.seconds = seconds;
            }
            public clockTime(clockTime copy)
            {
                this.hours = copy.getHoursClockTime();
                this.minutes = copy.getMinutesClockTime();
                this.seconds = copy.getSecondsClockTime();
            }
            // задання часу
            private void setHoursClockTime()
            {
                Console.Write("Введiть години (вiд 0 до 23): ");
                try
                {
                    hours = Convert.ToInt32(Console.ReadLine());
                    if ((hours >= 0) && (hours < 24))
                    {
                        Console.WriteLine("Успiшно. Години встановленно.");
                    }
                    else
                    {
                        hours = 23;
                        Console.WriteLine("Ви перевищили заданий інтервал, значення встановленно по замовченню (23)");
                    }
                }
                catch
                {
                    Console.WriteLine("Навіщо ви так робите?!");
                    hours = 23;
                    Console.WriteLine("Ви перевищили заданий інтервал, значення встановленно по замовченню (23)");
                }
            }
            private void setMinutesClockTime()
            {
                Console.Write("Введiть хвилини (вiд 0 до 59): ");
                try
                {
                    minutes = Convert.ToInt32(Console.ReadLine());
                    if ((minutes >= 0) && (minutes < 60))
                    {
                        Console.WriteLine("Успiшно. Хвилини встановленно.");
                    }
                    else
                    {
                        minutes = 59;
                        Console.WriteLine("Ви перевищили заданий інтервал, значення встановленно по замовченню (59)");
                    }
                }
                catch
                {
                    Console.WriteLine("Навіщо ви так робите?!");
                    minutes = 59;
                    Console.WriteLine("Ви перевищили заданий інтервал, значення встановленно по замовченню (59)");
                }
            }
            private void setSecondsClockTime()
            {
                Console.Write("Введiть секунди (вiд 0 до 59): ");
                try
                {
                    seconds = Convert.ToInt32(Console.ReadLine());
                    if ((seconds >= 0) && (seconds < 60))
                    {
                        Console.WriteLine("Успiшно. секунди встановленно.");
                    }
                    else
                    {
                        seconds = 59;
                        Console.WriteLine("Ви перевищили заданий інтервал, значення встановленно по замовченню (59)");
                    }
                }
                catch
                {
                    Console.WriteLine("Навіщо ви так робите?!");
                    seconds = 59;
                    Console.WriteLine("Ви перевищили заданий інтервал, значення встановленно по замовченню (59)");
                }
            }
            private void setClockTime()
            {
                setHoursClockTime();
                setMinutesClockTime();
                setSecondsClockTime();
            }
            // додавання і віднімання часу
            private void incHoursClockTime()
            {
                if (hours > 22)
                    hours = 0;
                else
                    hours++;
            }
            private void decrHoursClockTime()
            {
                if (hours < 1)
                    hours = 23;
                else 
                    hours--;
            }
            private void incMinutesClockTime()
            {
                if (minutes > 58)
                {
                    incHoursClockTime();
                    minutes = 0;
                }
                else
                    minutes++;
            }
            private void decrMinutesClockTime()
            {
                if (minutes < 1)
                {
                    decrHoursClockTime();
                    minutes = 59;
                }
                else
                    minutes--;
            }
            private void incSecondsClockTime()
            {
                if (seconds > 58)
                {
                    incMinutesClockTime();
                    seconds = 0;
                }
                else
                    seconds++;
            }
            private void decrSecondsClockTime()
            {
                if (seconds < 1)
                {
                    setMinutesClockTime();
                    seconds = 59;
                }
                else
                    seconds--;
            }
            // для роботи з часом
            public int getHoursClockTime()
            {
                return hours;
            }
            public int getMinutesClockTime()
            {
                return minutes;
            }
            public int getSecondsClockTime()
            {
                return seconds;
            }
            // для виводу
            public void getClockTime()
            {
                Console.WriteLine("Поточний час:\n" + getHoursClockTime() + " : " + getMinutesClockTime() + " : " + getSecondsClockTime());
            }
<<<<<<< HEAD:Лаворчук ВІ/ООП/PrW2/time/time/Program.cs
            // перегрузка операторів
            public static clockTime operator +(clockTime t1, clockTime t2) 
            {
                int h = 0,
                    m = 0,
                    s = 0;
                if ((t1.getSecondsClockTime() + t2.getSecondsClockTime()) > 59)
                {
                    s = t1.getSecondsClockTime() + t2.getSecondsClockTime() - 60;
                    m++;
                }
                else
                    m = t1.getSecondsClockTime() + t2.getSecondsClockTime();

                if ((t1.getMinutesClockTime() + t2.getMinutesClockTime()) > 59)
                {
                    m += t1.getMinutesClockTime() + t2.getMinutesClockTime() - 60;
                    h++;
                }
                else
                    m = t1.getMinutesClockTime() + t2.getMinutesClockTime();

                if ((t1.getHoursClockTime() + t2.getHoursClockTime()) > 23)
                {
                    h += t1.getHoursClockTime() + t2.getHoursClockTime() - 24;                    
                }
                else
                    h = t1.getHoursClockTime() + t2.getHoursClockTime();

                return new clockTime(h, m, s);
            }
            public static clockTime operator +(clockTime t1, int number)
            {
                int s = t1.seconds,
                    m = t1.minutes,
                    h = t1.hours;
                if ((s + number) > 60)
                {
                    s = s + number - 60;
                    m++;
                }
                s = s + number;

                return new clockTime(h, m, s);    
            }
=======

            
>>>>>>> 905f2c7feb6ff69f2adc3d56922c01e948561334:LavorchukVI/OOP/PrW2/time/time/Program.cs
            
        }
        static void Main(string[] args)
        {
<<<<<<< HEAD:Лаворчук ВІ/ООП/PrW2/time/time/Program.cs
            clockTime myClock = new clockTime(0, 0, 0);
            //myClock.getClockTime();            
            clockTime hisClock = new clockTime(myClock);
            //hisClock.getClockTime();
            //insert methods:D
            myClock = myClock + 5;
            myClock.getClockTime();    
            
=======
            clockTime myClock = new clockTime(15, 30, 47);
            myClock.getClockTime();            
            clockTime hisClock = new clockTime(myClock);
            hisClock.getClockTime();
>>>>>>> 905f2c7feb6ff69f2adc3d56922c01e948561334:LavorchukVI/OOP/PrW2/time/time/Program.cs
            Console.ReadKey();
        }
    }
}
