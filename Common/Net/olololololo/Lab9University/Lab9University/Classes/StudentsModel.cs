using System;
using System.Data.SqlClient;
using System.Windows.Forms;

namespace Lab9University.Classes
{
    public class StudentsModel
    {
        SqlConnection connection;

        public StudentsModel(SqlConnection connection)
        {
            this.connection = connection;
        }

        public void Load(ComboBox.ObjectCollection students)
        {
            using (SqlCommand command = new SqlCommand("select * from dbo.Students;", connection))
            using(SqlDataReader reader = command.ExecuteReader())
            {
                while (reader.Read())
                {
                    students.Add(new Student(reader.GetInt32(0), reader.GetString(1), reader.GetString(2), reader.GetDateTime(3)));
                }
            }
        }

        public void Insert(Student student)
        {
            string comm = "insert into dbo.Students (FirstName, LastName, BirthDate) values ('"
                + student.FirstName + "', '" + student.LastName + "', '"
                + student.BirthDate.ToString("yyyy-MM-dd") + "');";
            using (SqlCommand command = new SqlCommand(comm, connection))
            {
                command.ExecuteNonQuery().ToString();
            }
        }

        public void Update(Student student)
        {
            string comm = "update dbo.Students set FirstName = '"
                + student.FirstName + "', LastName = '" + student.LastName + "', BirthDate = '"
                + student.BirthDate.ToString("yyyy-MM-dd")
                + "' where StudentID = " + student.StudentID + ";";
            using (SqlCommand command = new SqlCommand(comm, connection))
            {
                command.ExecuteNonQuery();
            }
        }

        public void Delete(Student student)
        {
            string comm = "delete from dbo.Students where StudentID = " + student.StudentID + ";";
            using (SqlCommand command = new SqlCommand(comm, connection))
            {
                command.ExecuteNonQuery();
            }
        }

        public Student GetLastStudent()
        {
            String comm = "select top 1 * from dbo.Students order by StudentID desc;";
            using (SqlCommand command = new SqlCommand(comm, connection))
            using (SqlDataReader reader = command.ExecuteReader())
            {
                reader.Read();
                return new Student(reader.GetInt32(0), reader.GetString(1), reader.GetString(2), reader.GetDateTime(3));
            }
        }
    }
}
