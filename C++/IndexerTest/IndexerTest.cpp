#include "pch.h"
#include "CppUnitTest.h"
#include "../task1/Indexer.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace IndexerTestCpp
{
	TEST_CLASS(IndexerTestCpp)
	{
	private:
		double* array = new double[4]{ 1,2,3,4 };
	public:
		TEST_METHOD(HaveCorrectLength)
		{
			auto indexer = Indexer(array, 1, 2, 4);
			Assert::AreEqual(2, indexer.Length());
		}
		TEST_METHOD(GetCorrectly)
		{
			auto indexer = Indexer(array, 1, 2, 4);
			Assert::AreEqual((double)2, indexer[0]);
			Assert::AreEqual((double)3, indexer[1]);
		}
		TEST_METHOD(SetCorrectly)
		{
			auto indexer = Indexer(array, 1, 2, 4);
			indexer[0] = 10;
			Assert::AreEqual((double)10, array[1]);
		}
		TEST_METHOD(IndexerDoesNotCopyArray)
		{
			auto indexer1 = Indexer(array, 1, 2, 4);
			Indexer indexer2(array, 0, 2, 4);
			indexer1[0] = 100500;
			Assert::AreEqual((double)100500, indexer2[1]);
		}
		TEST_METHOD(FailWithWrongArguments1)
		{
			Assert::ExpectException<invalid_argument>([&] {Indexer(array, -1, 3, 4); });
		}
		TEST_METHOD(FailWithWrongArguments2)
		{
			Assert::ExpectException<invalid_argument>([&] {Indexer(array, 1, -1, 4); });
		}
		TEST_METHOD(FailWithWrongArguments3)
		{
			Assert::ExpectException<invalid_argument>([&] {Indexer(array, 1, 10, 4); });
		}
		TEST_METHOD(FailWithWrongIndexing1)
		{
			auto indexer = Indexer(array, 1, 2, 4);
			Assert::ExpectException<out_of_range>([&] {indexer[-1]; });
		}
		TEST_METHOD(FailWithWrongIndexing2)
		{
			auto indexer = Indexer(array, 1, 2, 4);
			Assert::ExpectException<out_of_range>([&] {indexer[10]; });
		}

	};
}