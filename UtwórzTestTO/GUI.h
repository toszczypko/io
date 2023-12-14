#pragma once
#include "structs.h"

class GUI {
public:
	GUI(const GUI&) = delete;
	static Entry getEntryFromUser();
	static std::string getTestTitle();
private:
	GUI();
	static GUI instance;
};
