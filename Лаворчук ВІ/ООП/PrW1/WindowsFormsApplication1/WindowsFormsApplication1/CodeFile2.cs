using System;

static class TimeFun
{
    static public int getHour(Time time)
    {
        return time.hours;
    }

    static public int getMinutes(Time time)
    {
        return time.minutes;
    }

    static public int getSeconds(Time time)
    {
        return time.seconds;
    }

    static public void set(int h, int m, int s, Time time)
    {
        if ((h >= 0 && h < 24) && (m >= 0 && m < 60) && (s >= 0 && s < 60))
        {
            time.hours = h;
            time.minutes = m;
            time.seconds = s;
        }
        else
        {
            time.hours = 23;
            time.minutes = 59;
            time.seconds = 59;
        }
    }

    static public void input(Time time)
    {
        try
        {
            Console.Write("input hours=");
            int h = Convert.ToInt32(Console.ReadLine());
            Console.Write("input minutes=");
            int m = Convert.ToInt32(Console.ReadLine());
            Console.Write("input seconds=");
            int s = Convert.ToInt32(Console.ReadLine());
            set(h, m, s, time);
        }
        catch
        {
            Console.WriteLine("input error");
        }
    }

    static public void output(Time time)
    {
        Console.WriteLine("Time: " + time.hours + ":" + time.minutes + ":" + time.seconds);
    }

    static public void addHours(Time time)
    {
        if (time.hours > 22)
            time.hours = 0;
        else
            time.hours++;
    }

    static public void minHours(Time time)
    {
        if (time.hours < 1)
            time.hours = 23;
        else
            time.hours--;
    }

    static public void addMinutes(Time time)
    {
        if (time.minutes > 58)
        {
            time.addHours();
            time.minutes = 0;
        }
        else time.minutes++;
    }

    static public void minMinutes(Time time)
    {
        if (time.minutes < 1)
        {
            time.minHours();
            time.minutes = 59;
        }
        else time.minutes--;
    }

    static public void addSeconds(Time time)
    {
        if (time.seconds > 58)
        {
            time.addMinutes();
            time.seconds = 0;
        }
        else time.seconds++;
    }

    static public void minSeconds(Time time)
    {
        if (time.seconds < 1)
        {
            time.minMinutes();
            time.seconds = 59;
        }
        else time.seconds--;
    }

    static public void initialize(Time time)
    {
        time.hours = 0;
        time.minutes = 0;
        time.seconds = 0;
    }
}