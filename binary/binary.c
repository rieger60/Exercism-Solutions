#include "binary.h"

int convert(const char *input)
{
	int n = (int)strlen(input);
	int dec = 0;

	while (*input) {

		if (*input != '0' && *input != '1')
			return INVALID;

		dec += (*(input++) - '0') * pow(2, (n--)-1);
	}

	return dec;
}
