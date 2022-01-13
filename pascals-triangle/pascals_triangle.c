#include "pascals_triangle.h"

void free_triangle(uint8_t **triangle, size_t rows)
{
	if (!rows) {
		rows++;
	}

	for (size_t i = 0; i < rows; i++) {
		free(triangle[i]);
	}
	free(triangle);
}

uint8_t **create_triangle(size_t rows)
{
	if (!rows || rows > 10) {
		rows = 1;
		uint8_t **triangle = init_triangle(rows);
		return triangle;
	}

	uint8_t **triangle = init_triangle(rows);

	for (uint8_t n = 0; n < rows; n++) {
		for (uint8_t k = 0; k < n + 1; k++) {
			if (k == 0 || k == n)
				triangle[n][k] = 1;
			else
				triangle[n][k] = (triangle[n - 1][k - 1] +
					triangle[n - 1][k]);
		}
	}

	return triangle;
}

uint8_t **init_triangle(size_t rows)
{
	uint8_t **triangle = malloc(rows * sizeof(uint8_t *));
	for (size_t i = 0; i < rows; i++) {
		triangle[i] = calloc(rows, sizeof(uint8_t));
	}

	return triangle;
}