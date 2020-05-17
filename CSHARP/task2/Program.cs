using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace task2
{
    class Program
    {
        static void Main(string[] args)
        {
            const int n = 3;
            SystemOfLinearEquation s = new SystemOfLinearEquation(3);
            s.Add(new LinearEquation("1,-2,4,3"));
            s.Add(new LinearEquation("-4,5,7,3"));
            s.Add(new LinearEquation("-3,3,-7,6"));
            s.StepView();

            double[] solve = s.Solve();
            Console.WriteLine(s.ToString());
            Console.Write("Ответ: ");
            for (int i = 0; i < solve.Length; ++i)
                Console.Write(solve[i] + " ");

            Console.ReadKey();
        }
    }
}
