#include "pch.h"
#include "CppUnitTest.h"
#include "../task2/LinearEquation.h"
#include "../task2/LinearEquation.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LinearEquationTestCpp
{
	TEST_CLASS(LinearEquationTest)
	{
	public:

		TEST_METHOD(Array)
		{
			vector<double>_a{ 1,2,3,4,6 };
			LinearEquation a(_a);
			Assert::AreEqual(2.0, a[1]);
		}
		TEST_METHOD(String)
		{
			string str = "1,2.3,4.5,6";
			LinearEquation a(str);
			Assert::AreEqual(4.5, a[2]);
		}

		TEST_METHOD(Mult1)
		{
			string s = "4,5,6,-7,4,2.9,1,2";
			LinearEquation a(s);
			a = a * 3.0;
			Assert::AreEqual(12.0, a[0]);
		}
		TEST_METHOD(Mult2)
		{
			string s = "4,5,6,-7,4,2.9,1,2";
			LinearEquation a(s);
			a = 4.0 * a;
			Assert::AreEqual(11.6, a[5]);
		}
		TEST_METHOD(Zero)
		{
			LinearEquation a(10);
			Assert::AreEqual(0.0, a[8]);
		}


		TEST_METHOD(Sum)
		{
			string s1 = "1, 4, -3,7,4,2.9,1,2";
			string s2 = "0,2,-6,7,4,2.9,1,2";
			LinearEquation a(s1);
			LinearEquation b(s2);
			LinearEquation res("1,6,-9,14,8,5.8,2.4");
			Assert::AreEqual(true, res == (a + b));
		}
		TEST_METHOD(Sub)
		{
			string s1 = "1, 4, -3,7,4,2.9,1,2";
			string s2 = "0,2,-6,7,4,2.9,1,2";
			LinearEquation a(s1);
			LinearEquation b(s2);
			LinearEquation res("1,2,3,0,0,0,0");
			Assert::AreEqual(true, res == (a - b));
		}

		TEST_METHOD(SameIn)
		{
			LinearEquation a(10);
			a.SameIn(15.432);
			Assert::AreEqual(15.432, a[6]);
		}

		TEST_METHOD(UnaryMinus)
		{
			LinearEquation a("1,2,3,4,5,6");
			a = -a;
			Assert::AreEqual(-3.0, a[2]);
		}

		TEST_METHOD(CheckContradictoryEquation)
		{
			LinearEquation a("0,0,0,2");
			bool check = (a) ? true : false;
			Assert::AreEqual(false, check);
		}


		TEST_METHOD(CheckSolvableEquation)
		{
			LinearEquation a("1,1,0,15");
			bool check = (a) ? true : false;
			Assert::AreEqual(true, check);
		}
		TEST_METHOD(CopyToList)
		{
			LinearEquation a("2,2,1,-4");
			list<double> tmp = a;
			Assert::AreEqual(2.0, tmp.front());
		}
		TEST_METHOD(FailIndex1)
		{
			auto func = []() {

				LinearEquation a("0,2,0,-4");
				double tmp = a[-1];
			};
			Assert::ExpectException<std::out_of_range>(func);
		}
		TEST_METHOD(FailIndex2)
		{
			auto func = []() {

				LinearEquation a("0,2,0,-4");
				double tmp = a[15];
			};
			Assert::ExpectException<std::out_of_range>(func);
		}
	};
}