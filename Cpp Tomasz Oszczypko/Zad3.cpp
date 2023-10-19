#include <iostream>


struct Miles {
	double land;
	double nautical;
};


Miles kmToMiles(double km) {
	return Miles{ km * 0.62137119, km * 0.539956803 };
}


int main() {
	setlocale(LC_CTYPE, "Polish");

	double km;
	std::cout << "Podaj odleg³oœæ w kilometrach: ";
	std::cin >> km;
	if (km <= 0) {
		std::cout << "B³êdna odleg³oœæ!\n";
		return -1;
	}
	Miles miles = kmToMiles(km);
	std::cout << "Odleg³oœæ w milach l¹dowych: " << miles.land << '\n';
	std::cout << "Odleg³oœæ w milach morskich: " << miles.nautical << '\n';

	return 0;
}
