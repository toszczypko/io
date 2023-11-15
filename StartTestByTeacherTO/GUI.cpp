#include "GUI.h"
#include <iostream>
#include <cstdlib>

GUI::GUI() : state(0) {}

GUI::~GUI() {
	delete queriedTests;
}

void GUI::display() {
	system("cls");
	switch (state) {
	case MENU:
		showMenu();
		break;
	case TESTS:
		showTests();
		break;
	default:
		break;
	}
}

void GUI::showMenu() {
	std::cout << "----------------\n";
	std::cout << "1. Testy\n";
	std::cout << "2. Wyjd�\n";
	std::cout << "----------------\n";
	std::cout << "> ";

	int option;
	std::cin >> option;
	std::cout << option;
	switch (option) {
	case 1:
		state = TESTS;
		queriedTests = Database::queryTests(1);
		break;
	case 2:
		exit(0);
		break;
	default:
		break;
	}
}

void GUI::showTests() {
	std::cout << "TESTY\n";
	std::cout << "--------------------------------\n";
	for (int i = 0; i < queriedTests->size(); i++) {
		std::cout << "Nazwa: " << (*queriedTests)[i].name << '\n';
		std::cout << "Pyta�: " << (*queriedTests)[i].entries.size() << '\n';
		std::cout << "Rozpocz�ty: ";
		if ((*queriedTests)[i].started) {
			std::cout << "[X]\n";
		}
		else {
			std::cout << "[ ]\n";
		}
		std::cout << "--------------------------------\n";
	}

	std::cout << "Finalna aplikacja okienkowa b�dzie obs�ugiwa� mysz oraz wi�cej test�w.\n";
	std::cout << "Na chwil� obecn� mo�liwe jest uruchomienie tylko jednego testu.\n";
	char option;
	do {
		std::cout << "Czy rozpocz�� test? t/n: ";
		std::cin >> option;
		option = (char)std::tolower((int)option);
	} while (option != 't' && option != 'n');
	
	// obecnie wspierany jest tylko jeden test
	(*queriedTests)[0].started = (option == 't');

	Database::updateTests(*queriedTests);
}
