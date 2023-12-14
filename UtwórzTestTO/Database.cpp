#include "Database.h"

Database Database::instance;

Database::Database() {}

uint32_t Database::getNextEntryID() {
	return instance.nextEntryID++;
}

uint32_t Database::getNextTestID() {
	return instance.nextTestID++;
}

void Database::addTest(std::string title, std::vector<Entry> entries) {
	TestStruct test;
	test.ID = getNextTestID();
	test.title = title;
	test.entries = entries;
	test.started = false;
	instance.tests.push_back(test);
}
