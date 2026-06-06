#include "colors.h"

void color_text_reset(HANDLE hConsole) {
	SetConsoleTextAttribute(hConsole, FOREGROUND_WHITE);
}

enum COLOR_TARGET {
	FOREGROUND,
	BACKGROUND
};

static int get_color_code(enum COLOR color, enum COLOR_TARGET target) {
	if (target == FOREGROUND) {
		switch (color) {
		case RED:
			return FOREGROUND_RED;
		case WHITE:
			return FOREGROUND_WHITE;
                case NONE:
			return 0;
		}
        }

        switch (color) {
        case RED:
		return BACKGROUND_RED;
        case WHITE:
		return BACKGROUND_WHITE;
        case NONE:
		return 0;
        }

	return 0;
}

void color_text(HANDLE hConsole, enum COLOR fg_color, enum COLOR bg_color) {
	int fg_color_code = get_color_code(fg_color, FOREGROUND);
        int bg_color_code = get_color_code(bg_color, BACKGROUND);
        
	SetConsoleTextAttribute(hConsole, fg_color_code | bg_color_code);
}
