#pragma once
#include <cstdint>
#include <string>


struct SolvedTestEntry {
	uint32_t ID;
	uint32_t userID;
	std::string testName;
	uint32_t points;
	std::pair<uint32_t, std::string> answers[4];  // pairs of questionIDs and answers
};


class Database {
public:
	static int getCount(uint32_t userID);
private:
	static SolvedTestEntry m_Entries[100]; // array in the future
	static uint32_t m_EntriesAmount;
};
