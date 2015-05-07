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
    public partial class EditForm : Form {
        Students students;
        public EditForm() {
            InitializeComponent();
        }

        private void EditForm_Load(object sender, EventArgs e) {
            students = new Students();
            Student student = students.GetStudentById(studentId);
            lastNameText.Text = student.LastName;
            firstNameText.Text = student.FirstName;
            calendar.SetDate(student.BirthDate);

        }

        private void editBtn_Click(object sender, EventArgs e) {
            string lastName = lastNameText.Text.Trim();
            string firstName = firstNameText.Text.Trim();
            DateTime birthDate = calendar.SelectionRange.End.Date;
            students.EditStudent(studentId, lastName, firstName, birthDate);
        }
    }
}
