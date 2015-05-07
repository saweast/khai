using Lab9University.Classes;
using System;
using System.Windows.Forms;
using System.Text.RegularExpressions;

namespace Lab9University
{
    public partial class FormAddAndEditData : Form
    {
        ComboBox cbName;
        StudentsModel studentsModel;
        FormMain formMain;
        bool addData;

        public FormAddAndEditData(ComboBox cbName, bool addData, StudentsModel studentsModel, FormMain formMain)
        {
            InitializeComponent();

            this.cbName = cbName;
            this.studentsModel = studentsModel;
            this.formMain = formMain;
            this.addData = addData;
        }

        private void btnCancel_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void btnOK_Click(object sender, EventArgs e)
        {
            string FirstName = tbFirstName.Text;
            string LastName = tbLastName.Text;
            if (CheckSpace(ref FirstName) && CheckSpace(ref LastName))
            {
                if(!CheckDate(dtpBirthDate.Value))
                {
                    MessageBox.Show("Incorrect date, enter the date in which the age is from 16 to 100 years");
                    return;
                }
                if (addData)
                {
                    studentsModel.Insert(new Student(-1, FirstName, LastName, dtpBirthDate.Value));
                    cbName.Items.Add(studentsModel.GetLastStudent());
                    cbName.SelectedItem = cbName.Items[cbName.Items.Count - 1];
                    MessageBox.Show("Data successfully added!");
                    this.Close();
                }
                else
                {
                    Student st = new Student(((Student)cbName.Items[cbName.SelectedIndex]).StudentID, FirstName, LastName, dtpBirthDate.Value);
                    studentsModel.Update(st);
                    cbName.Items[cbName.SelectedIndex] = st;
                    MessageBox.Show("Data updated successfully!");
                    this.Close();
                }
            }
            else MessageBox.Show("Fill in all required fields");
        }

        private void FormAddAndEditData_Load(object sender, EventArgs e)
        {
            if (addData)
            {
                tbFirstName.Text = "";
                tbLastName.Text = "";
                dtpBirthDate.Value = new DateTime(1995, 01, 21);
            }
            else
            {
                tbFirstName.Text = ((Student)cbName.Items[cbName.SelectedIndex]).FirstName;
                tbLastName.Text = ((Student)cbName.Items[cbName.SelectedIndex]).LastName;
                dtpBirthDate.Value = ((Student)cbName.Items[cbName.SelectedIndex]).BirthDate;
            }
        }

        private void tbFirstName_KeyPress(object sender, KeyPressEventArgs e)
        {
            VerificationData(e);
        }

        private void tbLastName_KeyPress(object sender, KeyPressEventArgs e)
        {
            VerificationData(e);
        }

        void VerificationData(KeyPressEventArgs e)
        {
            if ((e.KeyChar >= 65 && e.KeyChar <= 90) || (e.KeyChar >= 97 && e.KeyChar <= 122)
                || (e.KeyChar >= 'А' && e.KeyChar <= 'Я') || (e.KeyChar >= 'а' && e.KeyChar <= 'я')
                || e.KeyChar == 32 || e.KeyChar == 8)
                e.Handled = false;
            else e.Handled = true;
        }

        bool CheckSpace(ref string str)
        {
            str = Regex.Replace(str, " +", " ");
            if (str.Length > 0 && str[0] == ' ') str = str.Remove(0, 1);
            if (str == "") return false;
            if (str[str.Length - 1] == ' ') str = str.Remove(str.Length - 1, 1);
            return true;
        }

        bool CheckDate(DateTime birthDate)
        {
            int age = DateTime.Now.Year - birthDate.Year;
            if (birthDate > DateTime.Now.AddYears(-age)) age--;

            if (age > 15 && age < 100) return true;
            return false;
        }

        private void FormAddAndEditData_FormClosed(object sender, FormClosedEventArgs e)
        {
            formMain.LoadForm = false;
        }
    }
}
