#include "resistor_color.h"

int color_code(int color)
{
	return color;
}

resistor_band_t *colors()
{
	static resistor_band_t arr[STOP];
	for (resistor_band_t i = 0; i < STOP; i++)
		arr[i] = i;

	return arr;
}