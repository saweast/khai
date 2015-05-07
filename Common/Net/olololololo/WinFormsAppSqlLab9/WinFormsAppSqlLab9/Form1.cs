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
    public partial class Frm1 : Form
    {
        string strConnection = "Server=localhost;Database=University;User Id=AdminUniversity;Password=1111;";
        List<Student> studentsList;
        string strCommand;
        SqlConnection myConnection;

        public Frm1()
        {
            InitializeComponent();
            myConnection = new SqlConnection(strConnection);
            SqlSetList();
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            label1.Text = "First name: " + studentsList.ElementAt(comboBox1.SelectedIndex).FirstName;
            label2.Text = "Last name: " + studentsList.ElementAt(comboBox1.SelectedIndex).LastName;
            label3.Text = "Date birth: " + studentsList.ElementAt(comboBox1.SelectedIndex).DateBirth.ToLongDateString();
        }
        private void comboBox1_DropDown(object sender, System.EventArgs e)
        {
            comboBox1.Items.Clear();
            SqlSetList();   
        }

        private void SqlSetList()
        {

            studentsList = new List<Student>();
            SqlCommand cmdSelect = new SqlCommand();
            strCommand = "SELECT FirstName, LastName, BirthDate, StudentID FROM dbo.Students";
            try
            {
                myConnection.Open();
                cmdSelect.Connection = myConnection;
                cmdSelect.CommandText = strCommand;
                SqlDataReader reader = cmdSelect.ExecuteReader();

                while (reader.Read())
                {
                    studentsList.Add(new Student(reader.GetString(0),
                                                 reader.GetString(1),
                                                 reader.GetDateTime(2),
                                                 reader.GetInt32(3)));
                }
                reader.Close();
                comboBox1.Items.Clear();
                foreach (Student st in studentsList)
                {
                    comboBox1.Items.Add(st);
                }
                comboBox1.SelectedIndex = 0;
            }
            catch (ArgumentOutOfRangeException)
            {

            }
            finally
            {
                myConnection.Close();
            }


        }

        private void deleteToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //comboBox1.SelectedIndex   DELETE FROM students WHERE id = 
            DialogResult dialogResult = MessageBox.Show("Are you sure, you'd like to delete stuent's info?", 
                "Deletting " + studentsList.ElementAt(comboBox1.SelectedIndex).LastName, MessageBoxButtons.YesNo);
            if (dialogResult == DialogResult.Yes)
            {
                SqlCommand cmdDel = new SqlCommand();
                strCommand = " DELETE FROM dbo.Students WHERE StudentID = " + studentsList.ElementAt(comboBox1.SelectedIndex).StudentID.ToString();
                try
                {
                    myConnection.Open();
                    cmdDel.Connection = myConnection;
                    cmdDel.CommandText = strCommand;
                    cmdDel.ExecuteNonQuery();

                    comboBox1.SelectedIndex = 0;
                }
                catch (ArgumentOutOfRangeException)
                {

                }
                finally
                {
                    myConnection.Close();
                }
                SqlSetList();
            }
            else if (dialogResult == DialogResult.No){ }           
        }

        private void changeToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            FrmChNew frm3 = new FrmChNew(strConnection,studentsList.ElementAt(comboBox1.SelectedIndex));
            frm3.ShowDialog();
            SqlSetList();
        }
        private void changeToolStripMenuItem_Click(object sender, EventArgs e)
        {
            FrmChNew frm2 = new FrmChNew(strConnection);
            frm2.ShowDialog();
            SqlSetList();
        }
    }
}
/*
    
            string strCon = "Server=localhost;Database=University;User Id=AdminUniversity;Password=1111;";
            SqlConnection myConnection = new SqlConnection(strCon);
            SqlCommand cmdCount = new SqlCommand();
            SqlCommand cmdSelect = new SqlCommand();
            Student[] stArr = new Student[5];

            try
            {
                myConnection.Open();


                //cmdCount.Connection = myConnection;
                //not need cmdCount.CommandType = System.Data.CommandType.StoredProcedure;
                //cmdCount.CommandText =  "SELECT COUNT(*) AS Number FROM dbo.Students;";
                //SqlDataReader reader = cmdCount.ExecuteReader();

                cmdSelect.Connection = myConnection;
                cmdSelect.CommandText = "SELECT StudentID, FirstName, LastName, BirthDate FROM dbo.Students";
                SqlDataReader reader = cmdSelect.ExecuteReader();

                while (reader.Read())
                {
                    Console.WriteLine(reader.GetInt32(0).ToString() + " " + 
                                      reader.GetString(1) + " " +
                                      reader.GetString(2) + " " +
                                      reader.GetDateTime(3).ToString());
                }
                reader.Close();
            }
            catch (UriFormatException)
            {
               
            }
            finally
            {
                myConnection.Close();
            }
            Console.ReadKey();
*/