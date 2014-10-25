using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
namespace WindowsFormsApplication1
{
    struct Time
    {
        int hours, minutes, seconds;

        public string getHour()
        {
            if (hours / 10 == 0)
            {
                return ("0" + hours.ToString());
            }
            else return hours.ToString();
        }

        public string getMinutes()
        {
            if (minutes / 10 == 0)
            {
                return ("0" + minutes.ToString());
            }
            else return minutes.ToString();
        }

        public string getSeconds()
        {
            if (seconds / 10 == 0)
            {
                return ("0" + seconds.ToString());
            }
            else return seconds.ToString();
        }

        public void set(int h, int m, int s)
        {
            hours = h;
            minutes = m;
            seconds = s;
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
}