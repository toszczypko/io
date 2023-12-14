#pragma once
#include "structs.h"
#include <vector>

class Database {
public:
	Database(const Database&) = delete;
	static void addTest(std::string title, std::vector<Entry> entries);
	static uint32_t getNextEntryID();
	static uint32_t getNextTestID();
private:
	Database();
	static Database instance;
	uint32_t nextTestID = 0;
	uint32_t nextEntryID = 0;
	std::vector<TestStruct> tests;
};
