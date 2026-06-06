#include <time.h>

#include "calendar_time.h"
#include "print.h"

int main(void) {

	time_t raw_time;
	struct tm *time_info;

        raw_time = time(NULL);
	time_info = localtime(&raw_time);
	
        enum WEEK_DAY first_day;
        first_day = find_first_week_day(time_info->tm_mday,
					time_info->tm_wday);

        int total_days = find_days_in_month(time_info->tm_mon,
                                            time_info->tm_year);

        print_calendar(total_days, first_day, time_info->tm_mday);
	
        return 0;
}
