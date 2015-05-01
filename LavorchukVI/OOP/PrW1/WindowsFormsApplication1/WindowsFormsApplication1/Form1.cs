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
            if(time.getHour() / 10 == 0)
            {
                textBox1.Text = "0" + time.getHour().ToString();
            }
            else textBox1.Text = time.getHour().ToString();

            if(time.getMinutes() / 10 == 0)
            {
                textBox2.Text = "0" + time.getMinutes().ToString();
            }
            else textBox2.Text = time.getMinutes().ToString();

            if (time.getSeconds() / 10 == 0)
            {
                textBox3.Text = "0" + time.getSeconds().ToString();
            }
            else textBox3.Text = time.getSeconds().ToString();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            time.addHours();
            refreshTime();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            time.addMinutes();
            refreshTime();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            time.addSeconds();
            refreshTime();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            time.initialize();
        }

        private void button6_Click(object sender, EventArgs e)
        {
            time.minHours();
            refreshTime();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            time.minMinutes();
            refreshTime();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            time.minSeconds();
            refreshTime();
        }

        private void button7_Click(object sender, EventArgs e)
        {
            if (Convert.ToInt32(textBox1.Text) < 24 && Convert.ToInt32(textBox2.Text) < 60 && Convert.ToInt32(textBox3.Text) < 60)
            {
                time.set(Convert.ToInt32(textBox1.Text), Convert.ToInt32(textBox2.Text), Convert.ToInt32(textBox3.Text));
                refreshTime();
            }
            else
            {
                textBox1.Text = "23";
                textBox2.Text = "59";
                textBox3.Text = "59";
                time.set(23, 59, 59);
            }
            MessageBox.Show("Час встановлено: " + textBox1.Text + ":" + textBox2.Text + ":" + textBox3.Text);
        }

        private void button8_Click(object sender, EventArgs e)
        {
            Form2 form2 = new Form2();
            form2.Show();
        }
    }
}