#ifndef COLORS_H
#define COLORS_H

#include <windows.h>

#define FOREGROUND_WHITE FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE
#define BACKGROUND_WHITE BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE

enum COLOR {
	WHITE,
	RED,
	NONE  
};

void color_text_reset(HANDLE hConsole);
void color_text(HANDLE hConsole, enum COLOR fg_color, enum COLOR bg_color);

#endif
