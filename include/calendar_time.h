#ifndef CALENDAR_TIME_H
#define CALENDAR_TIME_H

#include <stdbool.h>

enum WEEK_DAY {
	MONDAY,
	TUESDAY,
	WEDNESDAY,
	THURSDAY,
	FRIDAY,
	SATURDAY,
	SUNDAY
};

enum MONTH {
	JAN = 1,
	FEB,
	MAR,
	APR,
	MAY,
	JUN,
	JUL,
	AUG,
	SEP,
	OCT,
	NOV,
	DEC
};

enum WEEK_DAY find_first_week_day(int current_day, int sweek_day);
int find_days_in_month(enum MONTH month, int year);
bool is_weekend(enum WEEK_DAY wday);
#endif
