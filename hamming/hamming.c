#include "hamming.h"

int compute(const char *lhs, const char *rhs)
{
	int hamming_distance = 0;

	// Check invalid inputs
	if (strcmp(lhs, rhs) == 0) return 0;
	if (strlen(lhs) != strlen(rhs)) return -1;

	// Test difference between tro strands of equal length
	while (*lhs) {
		if (*lhs != *rhs)
			hamming_distance++;
		lhs++;
		rhs++;
	}

 	return hamming_distance;
}
