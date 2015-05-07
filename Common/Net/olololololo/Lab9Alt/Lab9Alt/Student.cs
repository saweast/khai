using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab9Alt {
    class Student {
        int id;
        string firstName;
        string lastName;
        DateTime birthDate;

        public Student() {
            id = 0;
            firstName = "Имя1";
            lastName = "Фамилия1";
            birthDate = new DateTime(2008, 6, 1, 0, 0, 0);
        }

        public Student(int id, string firstName, string lastName, DateTime birthDate) {
            this.id = id;
            this.firstName = firstName;
            this.lastName = lastName;
            this.birthDate = birthDate;
        }

        public int Id {
            get {
                return id;
            }

        }

        public string FirstName {
            get {
                return firstName;
            }

            set {
                firstName = value;
            }
        }

        public string LastName {
            get {
                return lastName;
            }

            set {
                lastName = value;
            }
        }

        public DateTime BirthDate {
            get {
                return birthDate;
            }

            set {
                birthDate = value;
            }
        }

        public override string ToString() {
            return lastName + " " + firstName;
        }


    }
}
