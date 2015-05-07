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

namespace WinFormsAppSqlLab9
{
    public partial class FrmChNew : Form
    {
        delegate void CurMethod();
        Student student;
        CurMethod curMethod;
        //string strConnection;
        //string strCommand;
        SqlConnection myConnection;

        //constructor for creating new student
        public FrmChNew(string strConnection)
        {
            InitializeComponent();
            curMethod = new CurMethod(CreateNewStudent);
            this.Text = "New Student";
            //this.strConnection = strConnection;
            myConnection = new SqlConnection(strConnection);
            dateTimePicker1.Value = new DateTime(2000,01,01);
        }

        //constructor for changing students data
        public FrmChNew(string strConnection,  Student student)
        {
            InitializeComponent();
            this.student = student;
            this.Text = "Change Student's Info";
            //this.strConnection = strConnection;
            myConnection = new SqlConnection(strConnection);
            textBox1.Text = student.FirstName;
            textBox2.Text = student.LastName;
            dateTimePicker1.Value = student.DateBirth;

            curMethod = new CurMethod(ChangeStudent);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (((textBox1.Text != "") && (textBox2.Text != "")))
            {
                curMethod();
            }
            else { System.Windows.Forms.MessageBox.Show("Please, Fill all fields"); }          
        }

        private void ChangeStudent()
        {
            string strCommand = "UPDATE Students SET firstname = @firstname, lastname = @lastname, birthdate =@birthdate WHERE StudentID = @studentsID";
            ExecutionMetod(strCommand,student.StudentID);
        }
        private void CreateNewStudent()
        {
            string strCommand = "INSERT INTO Students (firstname, lastname, birthdate) VALUES (@firstname, @lastname, @birthdate)";
            ExecutionMetod(strCommand);
        }
        private void ExecutionMetod(string strCommand, int id=-1)
        {
            try
            {
                myConnection.Open();
                SqlCommand cmd = new SqlCommand();
                cmd.Connection = myConnection;
                cmd.CommandText = strCommand;
                SqlParameter idParam;
                SqlParameter firstNameParam = new SqlParameter("@firstname", SqlDbType.Text, 100);
                SqlParameter lastNameParam = new SqlParameter("@lastname", SqlDbType.Text, 100);
                SqlParameter birthDateParam = new SqlParameter("@birthdate", SqlDbType.Date, 100);

               
                firstNameParam.Value = textBox1.Text;
                lastNameParam.Value = textBox2.Text;
                birthDateParam.Value = dateTimePicker1.Value;

                if (id != (-1))
                {
                    idParam = new SqlParameter("@studentsID", SqlDbType.Int, 100);
                    idParam.Value = id;
                    cmd.Parameters.Add(idParam);
                }
                cmd.Parameters.Add(firstNameParam);
                cmd.Parameters.Add(lastNameParam);
                cmd.Parameters.Add(birthDateParam);

                cmd.Prepare();
                cmd.ExecuteNonQuery();
                System.Windows.Forms.MessageBox.Show("Done");
            }
            catch (ArgumentOutOfRangeException)
            {

            }
            finally
            {
                myConnection.Close();
                this.Close();
            }
        }
    }
}
