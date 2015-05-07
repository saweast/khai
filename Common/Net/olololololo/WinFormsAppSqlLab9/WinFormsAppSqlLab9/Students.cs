using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WinFormsAppSqlLab9
{
    public class Student
    {
        int studentID;
        string firstName;
        string lastName;
        DateTime dateBirth;

        public Student(string firstName, string lastName, DateTime dateBirth, int studentID)
        {
            this.firstName = firstName;
            this.lastName = lastName;
            this.dateBirth = dateBirth;
            this.studentID = studentID;
        }
        public string FirstName { get { return firstName; } set { } }
        public string LastName { get { return lastName; } set { } }
        public DateTime DateBirth { get { return dateBirth; } set { } }
        public int StudentID { get { return studentID; } set { } }
        public override string ToString()
        {
            return LastName + " " + FirstName;
        } 

    }
}
