#include "App.h"
#include "GUI.h"
#include "Database.h"
#include "structs.h"

void App::createTest() {
	bool push = true;
	std::string title = GUI::getTestTitle();
	std::vector<Entry> entries;
	while (true) {
		Entry entry = GUI::getEntryFromUser();
		if (entry.question == "X") {
			push = false;
			break;
		}
		entries.push_back(entry);
	}
	
	if (push) {
		Database::addTest(title, entries);
	}
}
