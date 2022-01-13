#include "armstrong_numbers.h"

bool is_armstrong_number(int candidate)
{
	int n_digits = floor(log10(abs(candidate))) + 1;
	int number = candidate;
	int sum = 0;

	while (number > 0) {
		int digit = number % 10;
		sum += pow(digit, n_digits);
		number /= 10;
	}

	return sum == candidate;
}