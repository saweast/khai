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
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }

        Class2 MyTime = new Class2();
        Class2.Time struTime = new Class2.Time();

        void refreshTime()
        {
            if (MyTime.getHour(struTime) / 10 == 0)
            {
                textBox1.Text = "0" + MyTime.getHour(struTime).ToString();
            }
            else textBox1.Text = MyTime.getHour(struTime).ToString();

            if (MyTime.getMinutes(struTime) / 10 == 0)
            {
                textBox2.Text = "0" + MyTime.getMinutes(struTime).ToString();
            }
            else textBox2.Text = MyTime.getMinutes(struTime).ToString();

            if (MyTime.getSeconds(struTime) / 10 == 0)
            {
                textBox3.Text = "0" + MyTime.getSeconds(struTime).ToString();
            }
            else textBox3.Text = MyTime.getSeconds(struTime).ToString();
        }

        private void button7_Click(object sender, EventArgs e)
        {
            if (Convert.ToInt32(textBox1.Text) < 24 && Convert.ToInt32(textBox2.Text) < 60 && Convert.ToInt32(textBox3.Text) < 60)
            {
                struTime = MyTime.set(Convert.ToInt32(textBox1.Text), Convert.ToInt32(textBox2.Text), Convert.ToInt32(textBox3.Text), struTime);
                refreshTime();
            }
            else
            {
                textBox1.Text = "23";
                textBox2.Text = "59";
                textBox3.Text = "59";
                struTime = MyTime.set(23, 59, 59, struTime);
            }
            MessageBox.Show("Час встановлено: " + textBox1.Text + ":" + textBox2.Text + ":" + textBox3.Text);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            struTime = MyTime.addHours(struTime);
            refreshTime();
        }

        private void Form2_Load(object sender, EventArgs e)
        {
            struTime = MyTime.initialize(struTime);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            struTime = MyTime.addMinutes(struTime);
            refreshTime();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            struTime = MyTime.addSeconds(struTime);
            refreshTime();
        }

        private void button6_Click(object sender, EventArgs e)
        {
            struTime = MyTime.minHours(struTime);
            refreshTime();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            struTime = MyTime.minMinutes(struTime);
            refreshTime();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            struTime = MyTime.minSeconds(struTime);
            refreshTime();
        }
    }
}
