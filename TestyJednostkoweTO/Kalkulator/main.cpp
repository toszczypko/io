#include "funkcje.h"
#include <iostream>

int main() {
	float x[] = { 2.f, 2.f, 1.f, -3.f, 5.f };
	int n = sizeof(x) / sizeof(float);

	float logn_value = natural_logarithm(x[0]);
	
	float deviation_value = standard_deviation(x, n);

	float exponent_value = exponent(x[0]);


	std::cout << "Ln: " << logn_value << '\n';
	std::cout << "Dev: " << deviation_value << '\n';
	std::cout << "Exp: " << exponent_value << '\n';

	return 0;
}
