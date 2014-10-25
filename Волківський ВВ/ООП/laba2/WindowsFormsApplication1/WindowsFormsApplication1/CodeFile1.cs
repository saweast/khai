using System;

class Time
{
    int hours, minutes, seconds;

    public Time()
    {
        hours = minutes = seconds = 0;
    }

    public Time(int hours, int minutes, int seconds)
    {
        if ((hours >= 0 && hours < 24) && (minutes >= 0 && minutes < 60) && (seconds >= 0 && seconds < 60))
        {
            this.hours = hours;
            this.minutes = minutes;
            this.seconds = seconds;
        }
        else
        {
            this.hours = 23;
            this.minutes = 59;
            this.seconds = 59;
        }
        
    }

    public Time(Time t)
    {
        this.hours = t.getHour();
        this.minutes = t.getMinutes();
        this.seconds = t.getSeconds();
    }

    public static Time operator +(Time t1, Time t2)
    {
        int dH = 0, dM = 0, dS = 0;
        if ((t1.getSeconds() + t2.getSeconds()) > 59)
        {
            dS = t1.getSeconds() + t2.getSeconds() - 60;
            dM++;
        }
        else dS = t1.getSeconds() + t2.getSeconds();

        if ((t1.getMinutes() + t2.getMinutes()) > 59)
        {
            dM += t1.getMinutes() + t2.getMinutes() - 60;
            dH++;
        }
        else dM += t1.getMinutes() + t2.getMinutes();

        if ((t1.getHour() + t2.getHour()) > 23)
        {
            dH += t1.getHour() + t2.getHour() - 24;
        }
        else dH += t1.getHour() + t2.getHour();

        return new Time(dH, dM, dS);
    }

    public static Time operator +(Time t1, int s)
    {
        Time tR = new Time();
        int dS = 0;
        if ((t1.getSeconds() + s) > 59)
        {
            dS = t1.getSeconds() + s - 60;
            tR.set(t1.getHour(), t1.getMinutes(), dS);
            tR.addMinutes();
        }
        else
        {
            dS = t1.getSeconds() + s;
            tR.set(t1.getHour(), t1.getMinutes(), dS);
        }
        return tR;
    }

    public static Time operator -(Time t1, Time t2)
    {
        int dH = 0, dM = 0, dS = 0;
        if ((t1.getSeconds() - t2.getSeconds()) < 0)
        {
            dS = (t1.getSeconds() - t2.getSeconds()) + 60;
            dM--;
        }
        else dS = t1.getSeconds() - t2.getSeconds();
        if ((t1.getMinutes() - t2.getMinutes()) < 0)
        {
            dM += (t1.getMinutes() - t2.getMinutes()) + 60;
            dH--;
        }
        else dM += t1.getMinutes() - t2.getMinutes();
        if((t1.getHour() - t2.getHour()) < 0)
        {
            dH += (t1.getHour() - t2.getHour()) + 24;
        }
        else dH += t1.getHour() - t2.getHour();
        return new Time(dH, dM, dS);
    }

    public static Time operator -(Time t1, int s)
    {
        Time tR = new Time();
        int dS = 0;
        if ((t1.getSeconds() - s) < 0)
        {
            dS = (t1.getSeconds() - s) + 60;
            tR.set(t1.getHour(), t1.getMinutes(), dS);
            tR.minMinutes();
        }
        else
        {
            dS = t1.getSeconds() - s;
            tR.set(t1.getHour(), t1.getMinutes(), dS);
        }
        return tR;
    }

    public static Time operator ++(Time t1)
    {
        t1.addSeconds();
        return t1;
    }

    public static Time operator --(Time t1)
    {
        t1.minSeconds();
        return t1;
    }

    public static bool operator ==(Time t1, Time t2)
    {
        if ((t1.getHour() == t2.getHour()) && (t1.getMinutes() == t2.getMinutes()) && (t1.getSeconds() == t2.getSeconds()))
            return true;
        else return false;
    }
    public static bool operator !=(Time t1, Time t2)
    {
        if(!(t1==t2))    
            return true;
        else return false;
    }

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
}