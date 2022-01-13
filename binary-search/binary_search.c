#include "binary_search.h"

int *binary_search(int value, const int *arr, size_t length)
{
	int start = 0;
	int end = length - 1;

	if (length == 0 || arr == NULL)
		return NULL;

	while (start <= end) {
		
		int median = start + (end - start) / 2;

		if (value == arr[median])
			return (int*)&arr[median];

		if (value > arr[median])
			start = median + 1;
		else
			end = median - 1;
	}

	return NULL;
}