#include "GUI.h"
#include "Database.h"
#include <iostream>
#include <cstring>

GUI GUI::instance;

GUI::GUI() {}

Entry GUI::getEntryFromUser() {
	Entry entry;

	entry.ID = Database::getNextEntryID();

	std::cout << "Pytanie: ";
	getline(std::cin, entry.question);
	if (entry.question == "X") {
		return entry;
	}
	for (int i = 0; i < 4; i++) {
		std::cout << "OdpowiedŸ " << i + 1 << ": ";
		getline(std::cin, entry.answers[i]);
	}
	std::cout << "Poprawna odpowiedŸ: ";
	std::string correctAnswer;
	getline(std::cin, correctAnswer);
	entry.correctAnswer = std::stoi(correctAnswer) - 1;

	return entry;
}

std::string GUI::getTestTitle() {
	std::string title;
	std::cout << "Podaj tytu³ testu: ";
	getline(std::cin, title);
	std::cout << "Aby przerwaæ, wpisz 'X' podczas wprowadzania pytania.\n";
	return title;
}
