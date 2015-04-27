using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SqlClient;

namespace laba9
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        public List<Student> StudentsList = new List<Student>();
        public Form2 frm2 = new Form2();
        Student studen1 = new Student();

        public void loadAll(bool reload = false, int stID = 0)
        {
            if (reload)
                comboBox1.Items.Clear();
            if (comboBox1.Items.Count == 0)
            foreach(Student st in StudentsList)
            {
                comboBox1.Items.Add(st.FirstName + " " + st.LastName);
            }
            label2.Text = ((Student)StudentsList[stID]).Date.ToString();

            try
            {
                pictureBox1.Image = Image.FromFile(((Student)StudentsList[stID]).photoID + ".jpg");
            }
            catch
            {
                pictureBox1.Image = pictureBox1.ErrorImage;
            }
            //comboBox1.SelectedIndex = stID;
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            StudentsList = studen1.LoadToList();
            loadAll();
            comboBox1.SelectedIndex = 0;
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            loadAll(false, comboBox1.SelectedIndex);
        }
        int getA(string abc)
        {
            int resul = 0;
            for(int i = 0; i < StudentsList.Count; i++)
            {
                string fln = ((Student)StudentsList[i]).FirstName + " " + ((Student)StudentsList[i]).LastName;
                if (fln.Equals(abc))
                {
                    resul = ((Student)StudentsList[i]).Id;
                }
            }
            return resul;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            frm2.isEdit = false;
            frm2.clearFields();
            frm2.ShowDialog();
            button1.Enabled = false;
            button2.Enabled = false;
            button4.Enabled = false;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            frm2.StudentsList = StudentsList;
            frm2.fillFields(comboBox1.SelectedIndex);
            frm2.isEdit = true;
            frm2.selID = getA(comboBox1.Text);
            button1.Enabled = false;
            button2.Enabled = false;
            button4.Enabled = false;
            frm2.ShowDialog();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            StudentsList = studen1.LoadToList();
            int mySelInd = comboBox1.SelectedIndex;
            loadAll(true, mySelInd-1);
            comboBox1.SelectedIndex = mySelInd-1;
            button1.Enabled = true;
            button2.Enabled = true;
            //button3.Enabled = true;
            button4.Enabled = true;
        }

        private void button4_Click(object sender, EventArgs e)
        {
            int mySelInd = comboBox1.SelectedIndex;
            studen1.DeleteRow(getA(comboBox1.Text));
            loadAll(true, mySelInd-1);
            comboBox1.SelectedIndex = mySelInd;
            button3.PerformClick();
        }
    }
}
