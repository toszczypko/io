#include "pch.h"
#include "CppUnitTest.h"
#include "DiagramSekwencji.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Szyfr)
		{
			db* test = nullptr;
			db* result = szyfr(test);
			Assert::IsTrue(test == result);
		}
		TEST_METHOD(DeSzyfr)
		{
			db* test = nullptr;
			db* result = deszyfr(test);
			Assert::IsTrue(test == result);
		}
		TEST_METHOD(Weryfikacja_good)
		{
			db test = {123,1,"imie","nazwisko",1,1};
			Assert::IsTrue(weryfikacja(&test));

		}
		TEST_METHOD(Weryfikacja_bad)
		{
			db test = { 1337,1,"imie","nazwisko",1,1 };
			Assert::IsTrue(!weryfikacja(&test));
		}
		TEST_METHOD(Logowanie)
		{
			Assert::IsTrue(logowanie);
		}
	};
}
