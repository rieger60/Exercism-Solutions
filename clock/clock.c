#include "clock.h"

#define MINUTE 60
#define HOUR 24
#define DAY (MINUTE * HOUR)

clock_t clock_create(int hour, int minute)
{
	static clock_t clock;
	int minutes = as_minutes(hour, minute);

	sprintf(clock.text, "%02d:%02d", minutes / 60, minutes % 60);

	return clock;
}

clock_t clock_add(clock_t clock, int minute_add)
{
	int hh = atoi(strtok(clock.text, ":"));
	int mm = atoi(strtok(NULL, ":"));
	int minutes = (as_minutes(hh, mm) + minute_add) % DAY;
	sprintf(clock.text, "%02d:%02d", minutes / 60, minutes % 60);

	return clock;
}

clock_t clock_subtract(clock_t clock, int minute_subtract)
{
	int hh = atoi(strtok(clock.text, ":"));
	int mm = atoi(strtok(NULL, ":"));
	int minutes = (as_minutes(hh, mm) - minute_subtract) % DAY;
	if (minutes < 0)
		minutes = DAY + minutes;
	sprintf(clock.text, "%02d:%02d", minutes / 60, minutes % 60);

	return clock;
}

bool clock_is_equal(clock_t a, clock_t b)
{
	if (strcmp(a.text, b.text) == 0)
		return true;

	return false;
}

int as_minutes(int hour, int minute)
{
	int minutes = 0;

	minutes += (hour % HOUR) * MINUTE;
	minutes += minute % DAY;
	minutes %= DAY;
	if (minutes < 0)
		minutes = DAY + minutes;

	return minutes;
}