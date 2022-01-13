#include "isogram.h"

bool is_isogram(const char phrase[])
{
	if (phrase == NULL)
		return false;

	int arr[SIZE] = {0};
	
	while (*phrase)
	{
		if (tolower(*phrase) >= 'a' && tolower(*phrase) <= 'z')
			arr[tolower(*phrase) - 'a']++;
		phrase++;
	}

	for (int i = 0; i < SIZE; i++) {
		if (arr[i] > 1)
			return false;
	}

	return true;
}
