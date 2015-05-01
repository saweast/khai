using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ex2
{
    class Cube { 
        int[] x = new int[6];
        int[] y;

        public int getYLength()
        {
            return y.Length;
        }

        public int getElementFromY(int i)
        {
            i = Math.Abs(i);

            if (i < y.Length)
                return y[i];

            return 0;
        }
        
        public int Generate(int r){
            int b = r;
            x[b]++;
            return ++b;         
        }

        public void Experiment(int n, Random r) {
            
            int[] buf = new int[n];
            for (int i = 0; i < n; i++)  {
                buf[i] = Generate(r.Next(6));
            }
            y = buf;
        }

        public void OutY()
        {
            for (int i = 0; i < y.Length; i++)
                Console.WriteLine(y[i]);
        }

        public void Output()
        {
            for (int i = 0; i < x.Length; i++)
            {
                Console.Write((i + 1) + ": ");
                for (int j = 0; j < x[i]; j++)
                    Console.Write("*");
                Console.Write("(" + x[i] + ")\n");
            }
        }
    }

    class Analyser{
        List<Cube> cubes;
        Random rand;
        int[] x;
        int n;

        public Analyser(int n = 2){
            this.n = n;
            cubes = new List<Cube>();
            for (int i = 0; i < n; i++)
                cubes.Add(new Cube());

            rand = new Random();

            x = new int[6*n + 1];
        }

        public void Generate(int a){
             // Количество экспериментов

            foreach (Cube c in cubes)
                c.Experiment(a, rand);

            int s = 0;

            for(int i = 0; i < a; i++)
            {
                s = 0;
                foreach (Cube c in cubes)
                {
                    s += c.getElementFromY(i);
                }
                x[s]++;
            }
        }

        public void Output()
        {
         
            // вывод последовательности результата бросков
            
                    
           for (int i = n; i < x.Length; i++)
           {
               Console.Write(i + ": ");
               for (int j = 0; j < x[i]; j++)
                   Console.Write("*");
               Console.Write("(" + x[i] + ")\n");
           }
        }
    } 
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Insert count experiments: ");
            int countExp = Convert.ToInt32(Console.ReadLine());
            Cube cube = new Cube();
            Random rand = new Random();
            cube.Experiment(countExp, rand);
            cube.Output();

            
            Console.WriteLine();

            Console.Write("Insert count of cubes: ");
            int countCubes = Convert.ToInt32(Console.ReadLine());

            Analyser analyser = new Analyser(countCubes);
            analyser.Generate(countExp);
            analyser.Output();

            Console.ReadLine();
        }
    }
}
