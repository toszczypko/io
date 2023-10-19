#include <iostream>
#include <string>

#define ARRAY_SIZE 10


struct Product {
    std::string name;
    float price;
};


void bubbleSort(Product array[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (array[j].price > array[j + 1].price) {
                std::swap(array[j], array[j + 1]);
            }
        }
    }
}


int main()
{
    std::setlocale(LC_CTYPE, "Polish");
    Product products[ARRAY_SIZE];

    std::string price;

    for (int i = 0; i < ARRAY_SIZE; i++) {
        std::cout << "Wprowadź nazwę " << i + 1 << " produktu: ";
        std::getline(std::cin, products[i].name, '\n');
        std::cout << "Wprowadź cenę " << i + 1 << " produktu: ";
        std::getline(std::cin, price, '\n');
        products[i].price = std::stof(price);
    }

    bubbleSort(products, ARRAY_SIZE);

    std::cout << "\n\n";

    for (int i = 0; i < ARRAY_SIZE; i++) {
        std::cout << products[i].name << " - " << products[i].price << '\n';
    }
}
