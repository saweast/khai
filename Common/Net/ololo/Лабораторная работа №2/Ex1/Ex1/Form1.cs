using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Ex1
{
    public partial class Form1 : Form
    {
        Random rand;
        public Form1()
        {
            InitializeComponent();
            rand = new Random();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void checkList1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void checkList1_MouseDown(object sender, MouseEventArgs e)
        {
            if(e.Button == MouseButtons.Right)
            {
                contextMenuStrip1.Show(checkList1.Location.X + this.Location.X, checkList1.Location.Y + this.Location.Y);
            }
        }

        private void addStrip_Click(object sender, EventArgs e)
        {

            if (rb1.Checked)
                checkList1.Items.Add(rand.Next(1, 10));

            if (rb2.Checked)
                checkList1.Items.Add(rand.Next(11, 20));
        }

        private void deleteStrip_Click(object sender, EventArgs e)
        {
            if (checkList1.SelectedIndex != -1)
                checkList1.Items.RemoveAt(checkList1.SelectedIndex);
            else MessageBox.Show("Item not found!");
        }

        private void btnSumm_Click(object sender, EventArgs e)
        {
            int sum = 0;
            for (int i = 0; i < checkList1.CheckedItems.Count; i++)
                sum += Convert.ToInt32(checkList1.CheckedItems[i].ToString());
            lbSum1.Text = "Сумма: " + sum.ToString();
        }
    }
}
