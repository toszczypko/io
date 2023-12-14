#include "pch.h"
#include "CppUnitTest.h"
#include <cmath>
#include "../Kalkulator/funkcje.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestJednostkowy {

	TEST_CLASS(TestJednostkowy) {
	public:
		TEST_METHOD(NaturalLogarithm) {
			float result = natural_logarithm(3.f);
			Assert::IsTrue(abs(logf(3.f) - result) < 0.00001f);
		}

		TEST_METHOD(StandardDeviation) {

			float dev = 2.57682f;
			float x[] = { 2.f, 2.f, 1.f, -3.f, 5.f };
			float result = standard_deviation(x, 5);
			Assert::IsTrue(abs(dev - result) < 0.00001f);
		}
		TEST_METHOD(Exponential) {
			float result = exponent(2.f);
			Assert::IsTrue(abs(expf(2.f) - result) < 0.00001f);
		}

		TEST_METHOD(Average) {
			float x[] = { 1.f, 2.f, 3.f };
			float result = average(x, 3);
			Assert::AreEqual(2.f, result);
		}
	};
}
