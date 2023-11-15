#include "Database.h"

Database Database::instance;

Database::Database() {
	// prepare dummy data

	Entry entry1;
	entry1.id = 1;
	entry1.question = "Seradela, to roœlina czy ryba?";
	entry1.answers[0] = "Tak";
	entry1.answers[1] = "Nie";
	entry1.answers[2] = "Roœlina";
	entry1.answers[3] = "Ryba";
	entry1.correctAnswer = 2;

	Entry entry2;
	entry2.id = 2;
	entry2.question = "Czy ten projekt zostanie kiedykolwiek ukoñczony?";
	entry2.answers[0] = "Tak";
	entry2.answers[1] = "Nie";
	entry2.answers[2] = "Nie wiem";
	entry2.answers[3] = "Sprzedam opla";
	entry2.correctAnswer = 0;

	TestStruct test;
	test.id = 1;
	test.userID = 1;
	test.name = "Testowy test";
	test.started = false;
	test.entries.push_back(entry1);
	test.entries.push_back(entry2);

	tests.push_back(test);
}

std::vector<TestStruct>* Database::queryTests(uint32_t userID) {
	std::vector<TestStruct>* vec = new std::vector<TestStruct>;
	for (int i = 0; i < instance.tests.size(); i++) {
		if (instance.tests[i].userID == userID) {
			vec->push_back(instance.tests[i]);
		}
	}
	return vec;
}

void Database::updateTests(std::vector<TestStruct> vec) {
	instance.tests = vec;
}
