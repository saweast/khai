using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data;
using System.Data.SqlClient;
using System.ComponentModel;
using System.Windows.Forms;

namespace Lab9Alt {
    class Students : IListSource {

        List<Student> students = new List<Student>();
        SqlConnection connection;

        bool IListSource.ContainsListCollection {
            get { return false; }
        }

        public Students() {
            string connectionString = "Server=.\\SQLEXPRESS;Database=Institute;User Id=StUser;Password=123;";
            connection = new SqlConnection(connectionString);
            GetAllRows();
        }

        IList IListSource.GetList() {
            return students;
        }

        public void AddStudent(string lastName, string firstName, DateTime birthDate) {
            try {
                connection.Open();

                lastName = lastName.Trim();
                firstName = firstName.Trim();

                SqlCommand sqlCommand = new SqlCommand(null, connection);
                sqlCommand.CommandText = "INSERT INTO Students (lastname, firstname, birthdate) " +
                                         "VALUES (@lastname, @firstname, @birthdate)";

                SqlParameter lastNameParam = new SqlParameter("@lastname", SqlDbType.Text, 100);
                SqlParameter firstNameParam = new SqlParameter("@firstname", SqlDbType.Text, 100);
                SqlParameter birthDateParam = new SqlParameter("@birthdate", SqlDbType.Date, 100);

                lastNameParam.Value = lastName;
                firstNameParam.Value = firstName;
                birthDateParam.Value = birthDate;

                sqlCommand.Parameters.Add(lastNameParam);
                sqlCommand.Parameters.Add(firstNameParam);
                sqlCommand.Parameters.Add(birthDateParam);

                sqlCommand.Prepare();
                sqlCommand.ExecuteNonQuery();
            } catch(SqlException ex) {
                MessageBox.Show("Ошибка при подключении к бд" + ex.Message);
            } finally {
                connection.Close();
            }
        }

        public void GetAllRows() {
            students.Clear();

            try {

                connection.Open();

                SqlCommand sqlCommand = new SqlCommand("SELECT * FROM Students", connection);

                SqlDataReader reader = sqlCommand.ExecuteReader();

                while (reader.Read()) {
                    int id = (int)reader["id"];
                    string firstName = (string)reader["firstname"];
                    string lastName = (string)reader["lastname"];
                    DateTime birthDate = (DateTime)reader["birthdate"];

                    students.Add(new Student(id, firstName, lastName, birthDate));
                }

                reader.Close();
                

            } catch (SqlException ex) {
                MessageBox.Show("Ошибка при работе с бд" + ex.Message);
            } finally {
                connection.Close();
            }

        }

        public Student GetStudentById(int id) {
            try {

                connection.Open();

                SqlCommand sqlCommand = new SqlCommand(null, connection);
                sqlCommand.CommandText = "SELECT id, lastname, firstname, birthdate " +
                                         "FROM students " +
                                         "WHERE id=@id";

                SqlParameter idParam = new SqlParameter("@id", SqlDbType.Int);

                idParam.Value = id;

                sqlCommand.Parameters.Add(idParam);

                sqlCommand.Prepare();

                SqlDataReader reader = sqlCommand.ExecuteReader();

                reader.Read();
                string firstName = (string)reader["firstname"];
                string lastName = (string)reader["lastname"];
                DateTime birthDate = (DateTime)reader["birthdate"];
                reader.Close();

                return new Student(id, firstName, lastName, birthDate);

                
            } catch (SqlException ex) {
                MessageBox.Show(ex.Message);
                return null;
            } finally {
                connection.Close();
            }
        }

        public void DeleteStudent(int id) {

            try {

                connection.Open();

                SqlCommand sqlCommand = new SqlCommand(null, connection);
                sqlCommand.CommandText = "DELETE FROM students " +
                                         "WHERE id=@id";

                SqlParameter idParam = new SqlParameter("@id", SqlDbType.Int);

                idParam.Value = id;

                sqlCommand.Parameters.Add(idParam);

                sqlCommand.Prepare();
                sqlCommand.ExecuteNonQuery();
            } catch (SqlException ex) {
                MessageBox.Show(ex.Message);
            } finally {
                connection.Close();
            } 
        }

        public void EditStudent(int id, string lastName, string firstName, DateTime birthDate) {
            try {
                connection.Open();

                SqlCommand sqlCommand = new SqlCommand(null, connection);

                sqlCommand.CommandText = "UPDATE students " +
                                         "SET lastname = @lastName, firstname = @firstName, birthdate = @birthDate " +
                                         "WHERE id = @id";


                SqlParameter lastNameParam = new SqlParameter("@lastName", SqlDbType.Text, 100);
                SqlParameter firstNameParam = new SqlParameter("@firstName", SqlDbType.Text, 100);
                SqlParameter birthDateParam = new SqlParameter("@birthDate", SqlDbType.Date);
                SqlParameter idParam = new SqlParameter("@id", SqlDbType.Int);

                
                lastNameParam.Value = lastName;
                firstNameParam.Value = firstName;
                birthDateParam.Value = birthDate;
                idParam.Value = id;

                
                sqlCommand.Parameters.Add(lastNameParam);
                sqlCommand.Parameters.Add(firstNameParam);
                sqlCommand.Parameters.Add(birthDateParam);
                sqlCommand.Parameters.Add(idParam);

                sqlCommand.Prepare();
                sqlCommand.ExecuteNonQuery();

            } catch (SqlException ex) {
                MessageBox.Show(ex.Message);
            } catch (InvalidCastException ex) {
                MessageBox.Show(ex.Message);
            } finally {
                connection.Close();
            }

        }

        public IEnumerator<Student> GetEnumerator() {
            foreach (Student student in students) {
                yield return student;
            }
        }



    }
}
