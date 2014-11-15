using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace WindowsFormsApplication1
{
    class Class2
    {
        public struct Time
        {
            public int hours, minutes, seconds;
        }
            public int getHour(Time t)
            {
                return t.hours;
            }

            public int getMinutes(Time t)
            {
                return t.minutes;
            }

            public int getSeconds(Time t)
            {
                return t.seconds;
            }

            public Time set(int h, int m, int s, Time t)
            {
                if ((h >= 0 && h < 24) && (m >= 0 && m < 60) && (s >= 0 && s < 60))
                {
                    t.hours = h;
                    t.minutes = m;
                    t.seconds = s;
                }
                else
                {
                    t.hours = 23;
                    t.minutes = 59;
                    t.seconds = 59;
                }
                return t;
            }

            public void input(Time t)
            {
                try
                {
                    Console.Write("input hours=");
                    int h = Convert.ToInt32(Console.ReadLine());
                    Console.Write("input minutes=");
                    int m = Convert.ToInt32(Console.ReadLine());
                    Console.Write("input seconds=");
                    int s = Convert.ToInt32(Console.ReadLine());
                    t=set(h, m, s, t);
                }
                catch
                {
                    Console.WriteLine("input error");
                }
            }

            public void output(Time t)
            {
                Console.WriteLine("Time: " + t.hours + ":" + t.minutes + ":" + t.seconds);
            }

            public Time addHours(Time t)
            {
                if (t.hours > 22)
                    t.hours = 0;
                else
                    t.hours++;
                return t;
            }

            public Time minHours(Time t)
            {
                if (t.hours < 1)
                    t.hours = 23;
                else
                    t.hours--;
                return t;
            }

            public Time addMinutes(Time t)
            {
                if (t.minutes > 58)
                {
                   t = addHours(t);
                    t.minutes = 0;
                }
                else t.minutes++;
                return t;
            }

            public Time minMinutes(Time t)
            {
                if (t.minutes < 1)
                {
                    t = minHours(t);
                    t.minutes = 59;
                }
                else t.minutes--;
                return t;
            }

            public Time addSeconds(Time t)
            {
                if (t.seconds > 58)
                {
                    t = addMinutes(t);
                    t.seconds = 0;
                }
                else t.seconds++;
                return t;
            }

            public Time minSeconds(Time t)
            {
                if (t.seconds < 1)
                {
                    t = minMinutes(t);
                    t.seconds = 59;
                }
                else t.seconds--;
                return t;
            }

            public Time initialize(Time t)
            {
                t.hours = 0;
                t.minutes = 0;
                t.seconds = 0;
                return t;
            }
        }
}
