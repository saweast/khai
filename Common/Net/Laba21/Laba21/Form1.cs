using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Laba21
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {

        }
        Random r = new Random();
        private void добавитьToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (radioButton1.Checked)
                checkedListBox1.Items.Add(Convert.ToString(r.Next(1,11)));
            if (radioButton2.Checked)
                checkedListBox1.Items.Add(Convert.ToString(r.Next(11,21)));
        }

        private void button1_Click(object sender, EventArgs e)
        {

            int sCount = checkedListBox1.Items.Count;
            int summ = 0;
            for(int i = 0; i < sCount; i++)
            {
                if(checkedListBox1.GetItemChecked(i) == true)
                    summ += Convert.ToInt32(checkedListBox1.Items[i]);
            }
            MessageBox.Show("Сума обраних елементів = " + summ);
        }

        private void видалитиToolStripMenuItem_Click(object sender, EventArgs e)
        {
            checkedListBox1.Items.Remove(checkedListBox1.SelectedItem);
        }
    }
}
