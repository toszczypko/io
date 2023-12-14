#pragma once
#include <cstdint>
#include <string>
#include <vector>

struct Entry {
	uint32_t ID;
	std::string question;
	std::string answers[4];
	uint8_t correctAnswer;
};

struct TestStruct {
	uint32_t ID;
	std::string title;
	std::vector<Entry> entries;
	bool started;
};
