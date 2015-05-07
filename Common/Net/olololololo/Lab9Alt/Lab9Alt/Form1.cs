using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab9Alt {
    public partial class Form1 : Form {
        Students students = new Students();
        AddForm addForm;
        EditForm editForm;

        public Form1() {
            InitializeComponent();
            addForm = new AddForm();
            editForm = new EditForm();
        }

        private void Form1_Load(object sender, EventArgs e) {
            cbxStudents.DataSource = students;
        }

        private void cbxStudents_DropDown(object sender, EventArgs e) {
            RefrechCbx();
        }

        private void cbxStudents_SelectedIndexChanged(object sender, EventArgs e) {
            lastNameText.Text = ((Student)cbxStudents.SelectedItem).LastName;
            firstNameText.Text = ((Student)cbxStudents.SelectedItem).FirstName;
            birthDateText.Text = ((Student)cbxStudents.SelectedItem).BirthDate.ToString().Substring(0, 10);
        }

        private void addBtn_Click(object sender, EventArgs e) {
            addForm.ShowDialog();
        }

        private void deleteBtn_Click(object sender, EventArgs e) {
            int id = ((Student)cbxStudents.SelectedItem).Id;
            students.DeleteStudent(id);

            RefrechCbx();
            
        }

        private void RefrechCbx() {
            students = new Students();
            cbxStudents.DataSource = students;
        }

        private void editBtn_Click(object sender, EventArgs e) {
            editForm.studentId = ((Student)cbxStudents.SelectedItem).Id;
            editForm.ShowDialog();
        }
    }
}
