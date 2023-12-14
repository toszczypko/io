#include <iostream>
#include "App.h"

int main() {
    setlocale(LC_CTYPE, "Polish");

    App app{};

    app.createTest();

    return 0;
}
