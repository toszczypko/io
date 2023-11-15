#include <iostream>
#include "GUI.h"
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>


int main() {
    setlocale(LC_CTYPE, "Polish");

    GUI gui;

    while (true) {
        gui.display();
        Sleep(100);
    }

    return 0;
}
