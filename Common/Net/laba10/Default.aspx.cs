using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using laba10;

    public partial class _Default : System.Web.UI.Page
    {
        Student stud = new Student();
        List<Student> StudentsList;
        protected void Page_Load(object sender, EventArgs e)
        {
            try
            {
                StudentsList = stud.LoadToList();
                DataGridStudents.DataSource = StudentsList;
                DataGridStudents.DataBind();
            }
            catch
            {
                ClientScript.RegisterStartupScript(this.GetType(), "myalert", "alert('Помилка з'єднання з базою!');", true);
            }
            finally
            {
                stud.myConn.Close();
            }
        }
        protected void Button1_Click(object sender, EventArgs e)
        {
            try
            {
                Label1.Text = " + ";
                Label3.Text = Convert.ToString(Convert.ToInt32(TextBox1.Text.ToString()) + Convert.ToInt32(TextBox2.Text.ToString()));
            }
            catch
            {
                ClientScript.RegisterStartupScript(this.GetType(), "myalert", "alert('Вірно введіть значення!');", true);
            }
        }
        protected void Button2_Click(object sender, EventArgs e)
        {
            try
            {
                Label1.Text = " - ";
                Label3.Text = Convert.ToString(Convert.ToInt32(TextBox1.Text.ToString()) - Convert.ToInt32(TextBox2.Text.ToString()));
            }
            catch
            {
                ClientScript.RegisterStartupScript(this.GetType(), "myalert", "alert('Вірно введіть значення!');", true);
            }
        }
        protected void Button3_Click(object sender, EventArgs e)
        {
            try
            {
                Label1.Text = " * ";
                Label3.Text = Convert.ToString(Convert.ToInt32(TextBox1.Text.ToString()) * Convert.ToInt32(TextBox2.Text.ToString()));
            }
            catch
            {
                ClientScript.RegisterStartupScript(this.GetType(), "myalert", "alert('Вірно введіть значення!');", true);
            }
        }
        protected void Button4_Click(object sender, EventArgs e)
        {
            try
            {
                Label1.Text = " / ";
                Label3.Text = Convert.ToString(Convert.ToDouble(TextBox1.Text.ToString()) / Convert.ToDouble(TextBox2.Text.ToString()));
            }
            catch
            {
                ClientScript.RegisterStartupScript(this.GetType(), "myalert", "alert('Вірно введіть значення!');", true);
            }
        }
        protected void dgStudents_SelectedIndexChanged(object sender, EventArgs e)
        {

        }
    }