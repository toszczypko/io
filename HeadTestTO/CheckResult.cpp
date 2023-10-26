#include "Database.h"
#include <iostream>


// logged-in user data
std::string loggedUserName = "PiwnyOlbrzym18";
uint32_t loggedUserID = 1;


void checkResult();
void showResultScreen();


void menu() {
	int selectedOption;
	do {
		system("cls");
		std::cout << "Zalogowano jako u�ytkownik: " << loggedUserName << "\n";
		"----- TYMCZASOWE MENU, TO B�DZIE KIEDY� IMGUI -----\n";
		std::cout << "Wprowad� numer opcji:\n";
		std::cout << "1. Wyniki\n";
		std::cout << "2. Wyjd�\n";
		std::cout << "> ";
		std::cin >> selectedOption;
	} while (selectedOption < 1 && selectedOption > 2);
	
	switch (selectedOption) {
	case 1:
		checkResult();
		showResultScreen();
	case 2:
		exit(0);
	}
	
}


void checkResult() {
	if (Database::getCount(loggedUserID) == 0) {
		showResultScreen();
	}
}


void showResultScreen() {
	std::cout << "Brak rozwi�zanych test�w\n";
}
