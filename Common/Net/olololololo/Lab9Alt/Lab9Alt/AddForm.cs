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
    public partial class AddForm : Form {
        public AddForm() {
            InitializeComponent();
        }

        private void addBtn_Click(object sender, EventArgs e) {
            string lastName = lastNameText.Text;
            string firstName = firstNameText.Text;            
            DateTime birthDate = calendar.SelectionRange.End.Date;

            Students students = new Students();
            students.AddStudent(lastName, firstName, birthDate);
            
            lastNameText.Text = "";
            firstNameText.Text = "";
        }
    }
}
