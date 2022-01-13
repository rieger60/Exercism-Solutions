#ifndef RESISTOR_COLOR_H
#define RESISTOR_COLOR_H

typedef enum {
	BLACK,
	BROWN,
	RED,
	ORANGE,
	YELLOW,
	GREEN,
	BLUE,
	VIOLET,
	GREY,
	WHITE,
	STOP
} resistor_band_t;

int color_code(int color);
resistor_band_t *colors();

#endif
