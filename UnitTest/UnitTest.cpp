#include "pch.h"
#include "CppUnitTest.h"
#include "..\Lab12_6.3A\main.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Elem* first = nullptr, * last = nullptr;
			for (size_t i = 0; i < 10; i++)
				enqueue(first, last, i);
			Assert::AreEqual(1, count(first, 3));
		}
	};
}
