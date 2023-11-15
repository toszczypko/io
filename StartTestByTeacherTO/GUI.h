#pragma once
#include <vector>
#include "Database.h"

#define MENU 0
#define TESTS 1

class GUI {
public:
	GUI();
	virtual ~GUI();
	void display();
private:
	int state;
	std::vector<TestStruct>* queriedTests;
	void showMenu();
	void showTests();
};
