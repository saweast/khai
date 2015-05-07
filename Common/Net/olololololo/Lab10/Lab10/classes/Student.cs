using System;

namespace Lab9University.Classes
{
    public class Student
    {
        private int _studentID;
        public int StudentID
        {
            get { return _studentID; }
        }
        public string FirstName { get; set; }
        public string LastName { get; set; }
        public DateTime BirthDate { get; set; }

        public Student(int studentID, string firstName, string lastName, DateTime birthDate)
        {
            _studentID = studentID;
            FirstName = firstName;
            LastName = lastName;
            BirthDate = birthDate;
        }

        public override string ToString()
        {
            return LastName + " " + FirstName;
        }
    }
}
