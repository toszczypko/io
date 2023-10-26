#include "Database.h"


uint32_t Database::m_EntriesAmount = 0;

int Database::getCount(uint32_t userID) {
	int counter = 0;
	for (int i = 0; i < m_EntriesAmount; i++) {
		if (m_Entries[i].userID == userID) {
			counter++;
		}
	}
	return counter;
}
