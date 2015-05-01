using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Laba3_3
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
                return (a + b + c);
        }

        public override double CalculateSquare()
        {
            double per = CalculatePerimeter() / 2;
            return Math.Sqrt(per * (per - a) * (per - b) * (per - c));
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
            else Console.WriteLine("Wrong parameters");
        }

        public override double CalculatePerimeter()
        {
            return 2 * (a + b);
        }

        public override double CalculateSquare()
        {
            return a * b;
        }
    }

    class FigureProcess
    {
        public static void printFigure(Figure figure)
        {
            Console.WriteLine("Perimeter = " + figure.CalculatePerimeter());
            Console.WriteLine("Ploshcha = " + figure.CalculateSquare());
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Triangle triangle = new Triangle(1, 1, 1.4);
            Rectangle rectangle = new Rectangle(10, 14);
            Console.WriteLine("Triangle");
            FigureProcess.printFigure(triangle);
            Console.WriteLine("Rectangle");
            FigureProcess.printFigure(rectangle);
            Console.ReadLine();
        }
    }
}