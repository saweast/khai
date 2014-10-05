using System;

    public struct Time
    {
        public int hours, minutes, seconds;

        public int getHour()
        {
            return hours;
        }

        public int getMinutes()
        {
            return minutes;
        }

        public int getSeconds()
        {
            return seconds;
        }

        public void set(int h, int m, int s)
        {
            if ((h >= 0 && h < 24) && (m >= 0 && m < 60) && (s >= 0 && s < 60))
            {
                hours = h;
                minutes = m;
                seconds = s;
            }
            else
            {
                hours = 23;
                minutes = 59;
                seconds = 59;
            }
        }

        public void input()
        {
            try
            {
                Console.Write("input hours=");
                int h = Convert.ToInt32(Console.ReadLine());
                Console.Write("input minutes=");
                int m = Convert.ToInt32(Console.ReadLine());
                Console.Write("input seconds=");
                int s = Convert.ToInt32(Console.ReadLine());
                set(h, m, s);
            }
            catch
            {
                Console.WriteLine("input error");
            }
        }

        public void output()
        {
            Console.WriteLine("Time: " + hours + ":" + minutes + ":" + seconds);
        }

        public void addHours()
        {
            if (hours > 22)
                hours = 0;
            else
                hours++;
        }

        public void minHours()
        {
            if (hours < 1)
                hours = 23;
            else
                hours--;
        }

        public void addMinutes()
        {
            if (minutes > 58)
            {
                addHours();
                minutes = 0;
            }
            else minutes++;
        }

        public void minMinutes()
        {
            if (minutes < 1)
            {
                minHours();
                minutes = 59;
            }
            else minutes--;
        }

        public void addSeconds()
        {
            if (seconds > 58)
            {
                addMinutes();
                seconds = 0;
            }
            else seconds++;
        }

        public void minSeconds()
        {
            if (seconds < 1)
            {
                minMinutes();
                seconds = 59;
            }
            else seconds--;
        }

        public void initialize()
        {
            hours = 0;
            minutes = 0;
            seconds = 0;
        }
};