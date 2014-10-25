using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace WindowsFormsApplication1
{    
    public partial class Form1 : Form
    {
        Time time;
        public Form1()
        {
            InitializeComponent();
        }

        void refreshTime()
        {
            textBox1.Text = time.getHour();
            textBox2.Text = time.getMinutes();
            textBox3.Text = time.getSeconds();
        }

        //void funHMS(string typeTime)
        //{
        //    if (typeTime == "hours")
        //    {
        //        if ((Convert.ToInt32(time.getHour()) / 10) == 0)
        //        {
        //            label1.Text = "0" + time.getHour();
        //        }
        //        else refreshTime();
        //    }
        //    else if (typeTime == "minutes")
        //    {
        //        if ((Convert.ToInt32(time.getMinutes()) / 10) == 0)
        //        {
        //            label2.Text = "0" + time.getMinutes();
        //        }
        //        else refreshTime(); 
        //    }
        //    else if (typeTime == "seconds")
        //    {
        //        if ((Convert.ToInt32(time.getSeconds()) / 10) == 0)
        //        {
        //            label3.Text = "0" + time.getSeconds();
        //        }
        //        else refreshTime(); 
        //    }
        //}

        private void button1_Click(object sender, EventArgs e)
        {
            time.addHours();
            refreshTime();
            //funHMS("hours");
        }

        private void button2_Click(object sender, EventArgs e)
        {
            time.addMinutes();
            refreshTime();
            //funHMS("minutes");
        }

        private void button3_Click(object sender, EventArgs e)
        {
            time.addSeconds();
            refreshTime();
            //funHMS("seconds");
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            time.initialize();
        }

        private void button6_Click(object sender, EventArgs e)
        {
            time.minHours();
            refreshTime();
            //funHMS("hours");
        }

        private void button5_Click(object sender, EventArgs e)
        {
            time.minMinutes();
            refreshTime();
            //funHMS("minutes");
        }

        private void button4_Click(object sender, EventArgs e)
        {
            time.minSeconds();
            refreshTime();
            //funHMS("seconds");
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            try
            {
                time.set(Convert.ToInt32(textBox1.Text), Convert.ToInt32(textBox2.Text), Convert.ToInt32(textBox3.Text));
            }
            catch
            {
            }
        }

        private void button7_Click(object sender, EventArgs e)
        {
            MessageBox.Show(time.getHour() + time.getMinutes() + time.getSeconds());
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {
            try
            {
                time.set(Convert.ToInt32(textBox1.Text), Convert.ToInt32(textBox2.Text), Convert.ToInt32(textBox3.Text));
            }
            catch
            {
            }
        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {
            try
            {
                time.set(Convert.ToInt32(textBox1.Text), Convert.ToInt32(textBox2.Text), Convert.ToInt32(textBox3.Text));
            }
            catch
            {
            }
        }
    }
}