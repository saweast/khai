using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab3Ex3
{
    abstract class Figure
    {
        public abstract double CalculatePerimeter();
        public abstract double CalculateSquare();
    }

    class Triangle : Figure
    {
        double a, b, c;

        public Triangle(double a, double b, double c)
        {
            if (a > 0 && b > 0 && c > 0)
            {
                this.a = a;
                this.b = b;
                this.c = c;
            }
            else a = b = c = 0;
        }

        public override double CalculatePerimeter()
        {
            if (a == 0 && b == 0 && c == 0) return 0;
            else return (a + b + c);
        }

        public override double CalculateSquare()
        {
            double p = CalculatePerimeter() / 2;

            if (p != 0) return Math.Sqrt(p * (p - a) * (p - b) * (p - c));
            else return 0;
        }
    }

    class Rectangle : Figure
    {
        double a, b;

        public Rectangle(double a, double b)
        {
            if (a > 0 && b > 0)
            {
                this.a = a;
                this.b = b;
            }
            else a = b = 0;
        }

        public override double CalculatePerimeter()
        {
            if (a == 0 && b == 0) return 0;
            else return 2 * (a + b);
        }

        public override double CalculateSquare()
        {
            if (a == 0 || b == 0) return 0;
            else return a * b;
        }
    }

    class AllFigure
    {
        public static void PrintFigure(Figure fig)
        {
            Console.WriteLine(
                fig.GetType() +
                "\nPerimeter = " + fig.CalculatePerimeter() +
                "\nSquare = " + fig.CalculateSquare()
            );
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Triangle tri = new Triangle(1, 1, 1.4);
            Rectangle rec = new Rectangle(6, 8);

            AllFigure.PrintFigure(tri);
            Console.WriteLine("");
            AllFigure.PrintFigure(rec);

            Console.ReadLine();
        }
    }

    
}
