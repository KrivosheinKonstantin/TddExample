#include "pch.h"
#include "CppUnitTest.h"
#include "../task2/SystemOfLinearEquation.h"
#include "../task2/SystemOfLinearEquation.cpp"
#include "../task2/LinearEquation.h"
#include "../task2/LinearEquation.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SystemLinearEquationTest
{
	TEST_CLASS(SystemLinearEquationTest)
	{
	public:

		TEST_METHOD(Index1)
		{
			SystemOfLinearEquation s(3);
			s.Add(LinearEquation("1,2,3,4"));
			s.Add(LinearEquation("5,6,7,8"));
			s.Add(LinearEquation("10,11,12,13"));
			Assert::AreEqual(3.0, s[0][2]);
		}
		TEST_METHOD(Solve)
		{
			int n = 3;
			SystemOfLinearEquation s(n);
			LinearEquation a1("1,-2,4,3");
			LinearEquation a2("-4,5,7,3");
			LinearEquation a3("-3,3,-7,6");
			s.Add(a1);
			s.Add(a2);
			s.Add(a3);
			s.StepView();
			vector<double> solve1 = s.Solve();
			bool check = true;
			vector<double>solve2{ -7, -5, 0 };
			for (int i = 0; i < solve1.size(); i++)
				if (solve1[i] != solve2[i]) check = false;
			Assert::AreEqual(true, check);
		}

		TEST_METHOD(NoSolutions)
		{
			auto func = []()
			{
				int n = 3;
				SystemOfLinearEquation s(n);
				s.Add(LinearEquation("14,16, 40, 20"));
				s.Add(LinearEquation("7, 8, 20, 10"));
				s.Add(LinearEquation("0, 0, 0, 0"));
				s.StepView();
				vector<double> solve1 = s.Solve();
			};
			Assert::ExpectException< std::invalid_argument>(func);
		}

		TEST_METHOD(ManySolutions)
		{
			auto func = []()
			{
				int n = 2;
				SystemOfLinearEquation s(n);
				LinearEquation a1("3, 7, 1, 0");
				LinearEquation a2("1,2,3,4");

				s.Add(a1);
				s.Add(a2);

				s.StepView();
				vector<double> solve1 = s.Solve();
			};
			Assert::ExpectException< std::invalid_argument>(func);
		}
		TEST_METHOD(FailIndex1)
		{
			auto func = []() {
				SystemOfLinearEquation s(3);
				s.Add(LinearEquation("0,0,0,0"));
				LinearEquation tmp = s[-1]; };
			Assert::ExpectException<std::out_of_range>(func);
		}
		TEST_METHOD(FailIndex2)
		{
			auto func = []() {
				SystemOfLinearEquation s(3);
				s.Add(LinearEquation("0,0,0,0"));
				LinearEquation tmp = s[15]; };
			Assert::ExpectException<std::out_of_range>(func);
		}

		TEST_METHOD(FailAddEquation)
		{
			auto func = []() {
				SystemOfLinearEquation s(3);
				s.Add(LinearEquation("1,2,3,3,4,6,7,8,5")); };
			Assert::ExpectException<std::invalid_argument>(func);
		}
	};
}