#include "calendar_time.h"

static enum WEEK_DAY convert_sweek_to_mweek(int sweek_day) {
	if (sweek_day == 0) {
		return SUNDAY;
        }
	sweek_day--;
	return sweek_day;
}

enum WEEK_DAY find_first_week_day(int current_day, int sweek_day) {
	enum WEEK_DAY wday;
        wday = convert_sweek_to_mweek(sweek_day);

	while (current_day != 1) {
		if (wday == MONDAY) {
			wday = SUNDAY;
                } else {
			wday--;
                }
		current_day--;
        }

	return wday;
}

static bool is_leap_year(int year) {
	if (year % 400 == 0) {
		return true;
	}
	if (year % 100 == 0) {
		return false;
	}
	if (year % 4 == 0) {
		return true;
	}

	return false;
} 

int find_days_in_month(enum MONTH month, int year) {
	switch (month) {
	case JAN:
	case MAR:
	case MAY:
	case JUL:
	case AUG:
	case OCT:
	case DEC:
		return 31;
	case APR:
	case JUN:
	case SEP:
	case NOV:
		return 30;
	case FEB:
		if (is_leap_year(year)) {
			return 29;
		}
                return 28;
        default:
		return 0;
	}
}

bool is_weekend(enum WEEK_DAY wday) {
	if (wday == SATURDAY || wday == SUNDAY) {
		return true;
	}

	return false;
}
