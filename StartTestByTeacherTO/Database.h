#pragma once
#include <string>
#include <cstdint>
#include <vector>

struct Entry {
	uint32_t id;
	std::string question;
	std::string answers[4];
	uint8_t correctAnswer;
};

struct TestStruct {
	uint32_t id;
	uint32_t userID;
	std::string name;
	std::vector<Entry> entries;
	bool started;
};

class Database {
public:
	Database(const Database&) = delete;
	static std::vector<TestStruct>* queryTests(uint32_t userID);
	static void updateTests(std::vector<TestStruct> vec);
private:
	Database();

	static Database instance;

	std::vector<TestStruct> tests;
};
