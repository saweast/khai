using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.SqlClient;

namespace laba9
{
    public class Student
    {
        public int Id = 0;
        public string FirstName = "";
        public string LastName = "";
        public DateTime Date = new DateTime();
        public int photoID = 0;
        public SqlConnection myConn = new SqlConnection(@"Data Source=TRAKTOR\SQLEXPRESS;Initial Catalog=Institute;Integrated Security=True;");
        public SqlCommand myComm;
        public SqlDataReader myReader;

        public Student()
        {
            //myConn.Open();
        }
        public Student(int id, string fName, string lName, DateTime date, int phID)
        {
            //myConn.Open();
            Id = id;
            FirstName = fName;
            LastName = lName;
            Date = date.Date;
            photoID = phID;
        }

        public void InsertIntoStudents(string FirstName, string LastName, string date)
        {
            myConn.Open();
            myComm = new SqlCommand("insert into dbo.Students (FirstName, LastName, BirthDay) values ('" +
                FirstName + "','" + LastName + "','" + date + "');", myConn);
            myComm.ExecuteNonQuery().ToString();
            myConn.Close();
        }

        public void EditStudentsTbl(int id, string FirstName, string LastName, string date)
        {
            myConn.Open();
            myComm = new SqlCommand("update dbo.Students set FirstName = '"
                + FirstName + "', LastName = '" + LastName + "', BirthDay = '"
                + date + "' where Id = " + id + ";", myConn);
            myComm.ExecuteNonQuery().ToString();
            myConn.Close();
        }

        public void DeleteRow(int Id)
        {
            myConn.Open();
            myComm = new SqlCommand("delete from dbo.Students where Id = " + Id + ";", myConn);
            myComm.ExecuteNonQuery().ToString();
            myConn.Close();
        }

        public List<Student> LoadToList()
        {
            myConn.Open();
            List<Student> StList = new List<Student>();
            myComm = new SqlCommand("select * from dbo.Students;", myConn);
            myReader = myComm.ExecuteReader();
            while (myReader.Read())
            {
                    StList.Add(new Student(myReader.GetInt32(0), myReader.GetString(1).Trim(), myReader.GetString(2).Trim(), myReader.GetDateTime(3).Date, myReader.GetInt32(4)));
            }
            myConn.Close();
            return StList;
        }
    }
}
