#include "print.h"

#include <windows.h>
#include <stdio.h>
#include "colors.h"

static void apply_day_color(HANDLE hConsole, bool *colored, enum WEEK_DAY wday, int current_day, int i) {
	if (is_weekend(wday) || current_day == i) {
		*colored = true;
	}
		
	if (is_weekend(wday) && current_day == i) {
		color_text(hConsole, RED, WHITE);
	} else if (is_weekend(wday)) {
		color_text(hConsole, RED, NONE);
	} else if (current_day == i) {
		color_text(hConsole, NONE, WHITE);
	}
}

void print_calendar(int total_days, enum WEEK_DAY first_day, int current_day) {

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        bool colored = false;
	enum WEEK_DAY wday = first_day;

	printf("\n\n");
        
	printf("Mo Tu We Th Fr Sa Su\n");

	// Add spaces for non-existing days
	for (int i = 0; i < first_day; i++) {
		printf("   ");
        }

        for (int i = 1; i <= total_days; i++) {

		apply_day_color(hConsole, &colored, wday, current_day, i);
		printf("%2d ", i);

                if (colored) {
			color_text_reset(hConsole);
			colored = false;
                }

		if (wday == SUNDAY) {
			wday = MONDAY;
                        printf("\n");
			continue;
                }
		wday++;
		
	}
        printf("\n\n\n");

	CloseHandle(hConsole);
}

