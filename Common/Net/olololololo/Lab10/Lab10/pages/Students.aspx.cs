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
            object result = StudentModel.GetStudents();
            if(result is List<Student>)
            {
                students = (List<Student>)result;
                dgStudents.DataSource = students;
                dgStudents.DataBind();
            }
            else if(result is string)
            {
                ErrorMessage.Text = (string)result;
            }
        }
    }
}