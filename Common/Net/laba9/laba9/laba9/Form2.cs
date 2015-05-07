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
    public partial class Form2 : Form
    {
        public Form2(Form1 fm1)
        {
            InitializeComponent();
            this.frm1 = fm1;
        }

        public List<Student> StudentsList = new List<Student>();
        public int selID = 0;
        public bool isEdit = false;
        Student stud1 = new Student();
        Form1 frm1;
        
        bool isCaptured = false;

        public void fillFields(int stID)
        {
            textBox1.Text = ((Student)StudentsList[stID]).FirstName;
            textBox2.Text = ((Student)StudentsList[stID]).LastName;
            dateTimePicker1.Text = ((Student)StudentsList[stID]).Date.ToString();
        }

        public void clearFields()
        {
            textBox1.Text = "";
            textBox2.Text = "";
            dateTimePicker1.Text = "";
        }

        private void Form2_Load(object sender, EventArgs e)
        {
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.Hide();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (isEdit)
                stud1.EditStudentsTbl(selID, textBox1.Text, textBox2.Text, dateTimePicker1.Value.ToString("yyyy-MM-dd"));
            else
                stud1.InsertIntoStudents(textBox1.Text, textBox2.Text, dateTimePicker1.Value.ToString("yyyy-MM-dd"));
            StudentsList = stud1.LoadToList();
            frm1.reloadL();
            this.Hide();
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {
        }

        private void timer1_Tick(object sender, EventArgs e)
        {

        }
    }
}
