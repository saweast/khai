using Lab10.classes;
using Lab9University.Classes;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Lab10.pages
{
    public partial class Students : System.Web.UI.Page
    {
        List<Student> students;

        protected void Page_Load(object sender, EventArgs e)
        {
            students = (List<Student>)StudentModel.GetStudents();
                dgStudents.DataSource = students;
                dgStudents.DataBind();
        }

        protected void dgStudents_SelectedIndexChanged(object sender, EventArgs e)
        {

        }
    }
}