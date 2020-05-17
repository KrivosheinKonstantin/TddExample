using System;
using System.Collections.Generic;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using task2;
namespace LinearEquationTestCs
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void String()//тест строки
        {
            string coeff = "7,8,    15, 9, 4.2";
            LinearEquation a1 = new LinearEquation(coeff);
            Assert.AreEqual(4.2, a1[4]);
        }
        [TestMethod]
        public void Array()//тест массива
        {
            double[] arr = new double[] { 1, 2.7, 3.31, 1.6, 5 };
            LinearEquation a1 = new LinearEquation(arr);
            Assert.AreEqual(2.7, a1[1]);
        }

        [TestMethod]
        public void List()//тест листа
        {
            List<double> coeff = new List<double>() { 1, 2, 3, 4, 5, 6 };
            LinearEquation a1 = new LinearEquation(coeff);
            Assert.AreEqual(2, a1[1]);
        }



        [TestMethod]
        public void InZero()//ур-е от n переменных
        {
            int n = 3;
            LinearEquation a = new LinearEquation(n);
            Assert.AreEqual("0x1+0x2+0x3=0", a.ToString());
        }

        [TestMethod]
        public void Sum()//сложение
        {
            LinearEquation a1 = new LinearEquation("1, 2, 3, 4, 5, 6.2");
            LinearEquation a2 = new LinearEquation("0.1    5.1     6.2     9.1     1    0");
            Assert.AreEqual(new LinearEquation("1.1,7.1,9.2,13.1,6,6.2"), a1 + a2);
        }

        [TestMethod]
        public void Sub()//вычитание
        {
            LinearEquation a1 = new LinearEquation("1, 2, 3, 4, 5, 6.2");
            LinearEquation a2 = new LinearEquation("0.1    5.1     6.2     9.1     1    0");
            Assert.AreEqual(new LinearEquation("0.9,-3.1,-3.2,-5.1,4,6.2"), a1 - a2);
        }

        [TestMethod]
        public void UnaryMinus()//*(-1)
        {
            LinearEquation a = new LinearEquation("1,2,3,4");
            Assert.AreEqual(new LinearEquation("-1,-2,-3,-4"), -a);
        }

        [TestMethod]
        public void Mult1()//умножение. число справа
        {
            LinearEquation a = new LinearEquation("1,4,5.2");
            Assert.AreEqual(new LinearEquation("3,12,15.6"), a * 3);
        }

        [TestMethod]
        public void Mult2()//умножение. число слева
        {
            string coeff = "4,6,2,78.9,23";
            LinearEquation a = new LinearEquation(coeff);
            string res = "12,18,6,236.7,69";
            Assert.AreEqual(new LinearEquation(res), 3 * a);
        }

        [TestMethod]
        public void Index()//обращение к переменным 
        {
            string coeff = "4,6,2,78.9,23";
            LinearEquation a = new LinearEquation(coeff);
            Assert.AreEqual(78.9, a[3]);
        }

        [TestMethod]
        public void SameIn()//одинаковые значения
        {
            LinearEquation a = new LinearEquation(4);
            a.SameIn(15.2);
            string res = "15.2,15.2,15.2,15.2,15.2";
            Assert.AreEqual(new LinearEquation(res), a);
        }

        [TestMethod]
        public void Equal1()//operator false
        {
            string res = "0,0,0,6";
            LinearEquation a = new LinearEquation(res);
            bool check = (a) ? true : false;
            Assert.AreEqual(false, check);
        }

        [TestMethod]
        public void Equal2()//operator true
        {
            string res = "0,2,0,15.2";
            LinearEquation a = new LinearEquation(res);
            bool check = (a) ? true : false;
            Assert.AreEqual(true, check);
        }

        [TestMethod]
        [ExpectedException(typeof(IndexOutOfRangeException))]
        public void FailIndex1()
        {
            string arr = "1,2.3,5.3,18,4";
            LinearEquation a = new LinearEquation(arr);
            Assert.Equals(typeof(IndexOutOfRangeException), a[5]);
        }

        [TestMethod]
        [ExpectedException(typeof(IndexOutOfRangeException))]
        public void FailIndex2()
        {
            string arr = "1,2.3,5.3,18,4";
            LinearEquation a = new LinearEquation(arr);
            Assert.Equals(typeof(IndexOutOfRangeException), a[-5]);
        }

        [TestMethod]
        [ExpectedException(typeof(ArgumentException))]
        public void FailArgument()
        {
            Assert.Equals(typeof(ArgumentException), new LinearEquation(0));
        }
    }
}