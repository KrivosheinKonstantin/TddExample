using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using task2;
namespace SystemOfLinearEquationTestCs
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void Index()//индексация ур-й
        {
            SystemOfLinearEquation s = new SystemOfLinearEquation(3);
            s.Add(new LinearEquation("1,2,3,4"));
            s.Add(new LinearEquation("5,6,7,8"));
            s.Add(new LinearEquation("10,11,12,13"));
            Assert.AreEqual(new LinearEquation("10,11,12,13"), s[2]);
        }
        [TestMethod]
        public void Solve()//Решение
        {
            const int n = 3;
            SystemOfLinearEquation s = new SystemOfLinearEquation(3);
            s.Add(new LinearEquation("1,-2,4,3"));
            s.Add(new LinearEquation("-4,5,7,3"));
            s.Add(new LinearEquation("-3,3,-7,6"));
            s.StepView();
            double[] solve1 = new double[] { -7, -5, 0 };//правильный ответ
            double[] solve2 = s.Solve(); //ответ полученный функцией
            bool check = true;
            for (int i = 0; i < n; i++)
                if (solve1[i] != solve2[i]) check = false;
            Assert.AreEqual(true, check);
        }
        [TestMethod]
        [ExpectedException(typeof(IndexOutOfRangeException))]
        public void FailIndex1()//Индексация
        {
            int n = 3;
            SystemOfLinearEquation s = new SystemOfLinearEquation(n);
            s.Add(new LinearEquation("1,-2,4,3"));
            s.Add(new LinearEquation("-4,5,7,3"));
            s.Add(new LinearEquation("-3,3,-7,6"));
            Assert.Equals(typeof(IndexOutOfRangeException), s[-1]);
        }
        [TestMethod]
        [ExpectedException(typeof(IndexOutOfRangeException))]
        public void FailIndex2()//Индексация
        {
            int n = 3;
            SystemOfLinearEquation s = new SystemOfLinearEquation(n);
            s.Add(new LinearEquation("1,-2,4,3"));
            s.Add(new LinearEquation("-4,5,7,3"));
            s.Add(new LinearEquation("-3,3,-7,6"));
            Assert.Equals(typeof(IndexOutOfRangeException), s[5]);
        }
        [TestMethod]
        [ExpectedException(typeof(ArgumentException))]
        public void NoSolutions()
        {
            int n = 3;
            SystemOfLinearEquation s = new SystemOfLinearEquation(n);
            s.Add(new LinearEquation("14,16, 40, 20"));
            s.Add(new LinearEquation("7, 8, 20, 10"));
            s.Add(new LinearEquation("0, 0, 0, 0"));
            s.StepView();
            Assert.Equals(typeof(ArgumentException), s.Solve());
        }

        [TestMethod]
        [ExpectedException(typeof(ArgumentException))]
        public void ManySolutions()
        {
            int n = 3;
            SystemOfLinearEquation s = new SystemOfLinearEquation(n);
            s.Add(new LinearEquation("3,7,1,0"));
            s.Add(new LinearEquation("1,2,3,4"));

            s.StepView();
            Assert.Equals(typeof(ArgumentException), s.Solve());
        }
    }
}