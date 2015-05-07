using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Lab10
{
    public partial class Calculator : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void Plus_Click(object sender, EventArgs e)
        {
            Operation.Text = "+";
        }

        protected void Minus_Click(object sender, EventArgs e)
        {
            Operation.Text = "-";
        }

        protected void Multiply_Click(object sender, EventArgs e)
        {
            Operation.Text = "*";
        }

        protected void Devision_Click(object sender, EventArgs e)
        {
            Operation.Text = "/";
        }

        protected void Calculate_Click(object sender, EventArgs e)
        {
            double operand1 = 0.0;
            double operand2 = 0.0;

            try
            {
                operand1 = Double.Parse(Operand1.Text);
                operand2 = Double.Parse(Operand2.Text);
            }
            catch (Exception)
            {
                ScriptManager.RegisterStartupScript(this, GetType(), "Error",
                    "alert('You entered the wrong operand!');", true);
                return;
            }

            switch(Operation.Text)
            {
                case "+":
                    Result.Text = "= " + (operand1 + operand2).ToString();
                break;

                case "-":
                    Result.Text = "= " + (operand1 - operand2).ToString();
                break;

                case "*":
                    Result.Text = "= " + (operand1 * operand2).ToString();
                break;

                case "/":
                    Result.Text = "= " + (operand1 / operand2).ToString();
                break;

                default:
                    ScriptManager.RegisterStartupScript(this, GetType(), "Error",
                    "alert('You entered the wrong operation!');", true);
                break;
            }
        }
    }
}