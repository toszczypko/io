#include "pch.h"
#include "CppUnitTest.h"

#include "../App.cpp"
#include "../Database.cpp"
#include "../GUI.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest {

	TEST_CLASS(UnitTest) {
	public:
		TEST_METHOD(dbGetNextEntryID) {
			for (int i = 0; i < 5; i++) {
				Assert::AreEqual(i, (int)Database::getNextEntryID());
			}
		}

		TEST_METHOD(dbGetNextTestID) {
			for (int i = 0; i < 5; i++) {
				Assert::AreEqual(i, (int)Database::getNextTestID());
			}
		}

		// TO NIE DZIA£A...
		TEST_METHOD(guiGetTestTitle) {
			std::string expected = "Test";

			Assert::AreEqual(expected, GUI::getTestTitle());
		}
	};
}
