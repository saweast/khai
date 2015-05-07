using Lab9University.Classes;
using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.UI;

namespace Lab10.classes
{
    public static class StudentModel
    {
        public static string Connection { get; set; }

        static StudentModel()
        {
            Connection = "Server=localhost;Database=University;User Id=AdminUniversity;Password=1111;";
        }

        public static object GetStudents()
        {
            using (SqlConnection connection = new SqlConnection(Connection))
            {
                try
                {
                    connection.Open();
                }
                catch(SqlException ex)
                {
                    return ex.Message;
                }

                SqlCommand command = new SqlCommand();
                command.CommandText = "SELECT StudentID, FirstName, LastName, BirthDate FROM Students;";
                command.Connection = connection;

                SqlDataReader reader = null;
                try
                {
                    reader = command.ExecuteReader();
                }
                catch (SqlException ex)
                {
                    return ex.Message;
                }

                List<Student> students = new List<Student>();
                while(reader.Read())
                {
                    students.Add(new Student(
                        (int)reader["StudentID"],
                        (string)reader["FirstName"],
                        (string)reader["LastName"],
                        (DateTime)reader["BirthDate"]
                    ));
                }

                return students;
            }
        }
    }
}