#include "funkcje.h"
#include <cmath>

float natural_logarithm(float x) {
	return log(x);
}

float standard_deviation(float x[], int n) {
	float avg = 0;
	for (int i = 0; i < n; i++) {
		avg += x[i];
	}
	avg /= n;

	float variance = 0;
	for (int i = 0; i < n; i++) {
		variance += (x[i] - avg) * (x[i] - avg);
	}
	variance /= n;

	return sqrtf(variance);
}

float exponent(float x) {
	return powf(2.718281f, x);
}

float average(float x[], int n) {
	float sum = 0;
	for (int i = 0; i < n; i++) {
		sum += x[i];
	}
	return sum / (float)n;
}
