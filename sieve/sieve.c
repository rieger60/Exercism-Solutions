#include "sieve.h"

uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes)
{
	
	bool *arr = malloc((limit + 1) * sizeof(bool));
	for (uint32_t i = 2; i <= limit; i++) {arr[i] = true;}

	for (uint32_t i = 2; i <= limit; i++) {
		if (arr[i]) {
			for (uint32_t j = i*i, k = 1; j <= limit; j = i*i+(k++)*i) {
				arr[j] = false;
			}
		}
	}

	uint32_t count = 0, prime = 2;
	while (prime <= limit) {
		if (arr[prime] == true) {
			*primes++ = prime;
			count++;
		}
		if (count >= max_primes)
			break;
		prime++;
	}

	return count;
}
