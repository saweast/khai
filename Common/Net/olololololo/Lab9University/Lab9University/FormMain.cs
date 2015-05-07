using System;
using System.Data.SqlClient;
using System.Windows.Forms;
using Lab9University.Classes;

namespace Lab9University
{
    public partial class FormMain : Form
    {
        SqlConnection connection;
        string connString;
        StudentsModel studentsModel;
        public bool LoadForm;

        public FormMain()
        {
            InitializeComponent();
            
            connString = "Server=localhost;Database=University;User Id=AdminUniversity;Password=1111;";
            connection = new SqlConnection(connString);
            LoadForm = false;
        }

        private void FormMain_Load(object sender, EventArgs e)
        {
            try
            {
                connection.Open();

                studentsModel = new StudentsModel(connection);
                studentsModel.Load(cbName.Items);

                if(cbName.Items.Count > 0)
                {
                    cbName.SelectedIndex = 0;
                    tbFirstName.Text = ((Student)cbName.SelectedItem).FirstName;
                    tbLastName.Text = ((Student)cbName.SelectedItem).LastName;
                    tbBirthDate.Text = ((Student)cbName.SelectedItem).BirthDate.ToString("dd MMMM yyyy") + " year";
                }
            }
            catch (SqlException)
            {
                MessageBox.Show("Error connecting to the database");
                this.Close();
            }
        }

        private void FormMain_FormClosed(object sender, FormClosedEventArgs e)
        {
            connection.Close();
        }

        private void cbName_SelectedIndexChanged(object sender, EventArgs e)
        {
            tbFirstName.Text = ((Student)cbName.SelectedItem).FirstName;
            tbLastName.Text = ((Student)cbName.SelectedItem).LastName;
            tbBirthDate.Text = ((Student)cbName.SelectedItem).BirthDate.ToString("dd MMMM yyyy") + " year";
        }
        
        private void btnAdd_Click(object sender, EventArgs e)
        {
            if (!LoadForm)
            {
                FormAddAndEditData formAddAndEditData = new FormAddAndEditData(cbName, true, studentsModel, this);
                formAddAndEditData.Text = "Add student";
                formAddAndEditData.Show();
                LoadForm = true;
            }
        }

        private void btnDelete_Click(object sender, EventArgs e)
        {
            if (cbName.Items.Count == 0)
            {
                MessageBox.Show("Please add data");
                return;
            }
            if (cbName.SelectedIndex == -1)
            {
                MessageBox.Show("Please select student");
                return;
            }
            if (LoadForm == true)
            {
                MessageBox.Show("Please close the add/edit window and continue deletion");
                return;
            }
            if(MessageBox.Show("Are you sure?", "Delete data", MessageBoxButtons.YesNo) == DialogResult.Yes)
            {
                studentsModel.Delete((Student)cbName.SelectedItem);
                cbName.Items.RemoveAt(cbName.SelectedIndex);
                tbFirstName.Text = "";
                tbLastName.Text = "";
                tbBirthDate.Text = "";
                if (cbName.Items.Count > 0) cbName.SelectedIndex = 0;
            }
        }

        private void btnEdit_Click(object sender, EventArgs e)
        {
            if (cbName.Items.Count == 0)
            {
                MessageBox.Show("Please add data");
                return;
            }
            if (cbName.SelectedIndex == -1)
            {
                MessageBox.Show("Please select student");
                return;
            }
            if (!LoadForm)
            {
                FormAddAndEditData formAddAndEditData = new FormAddAndEditData(cbName, false, studentsModel, this);
                formAddAndEditData.Text = "Edit student";
                formAddAndEditData.Show();
                LoadForm = true;
            }
        }
    }
}
