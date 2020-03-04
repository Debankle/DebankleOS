#ifndef OS_DISPLAY
#define OS_DISPLAY

#define MAX_ROWS 25
#define MAX_COLS 80

#include "../libc/stdint.h"

#define VIDEO_ADDRESS 0x000B8000

enum vga_color {
	VGA_COLOR_BLACK = 0,
	VGA_COLOR_BLUE = 1,
	VGA_COLOUR_GREEN = 2,
	VGA_COLOUR_CYAN = 3,
	VGA_COLOUR_RED = 4,
	VGA_COLOUR_MAGENTA = 5,
	VGA_COLOUR_BROWN = 6,
	VGA_COLOUR_LIGHT_GREY = 7,
	VGA_COLOUR_DARK_GREY = 8,
	VGA_COLOUR_LIGHT_BLUE = 9,
	VGA_COLOUR_LIGHT_GREEN = 10,
	VGA_COLOUR_LIGHT_CYAN = 11,
	VGA_COLOUR_LIGHT_RED = 12,
	VGA_COLOUR_LIGHT_MAGENTA = 13,
	VGA_COLOUR_LIGHT_BROWN = 14,
	VGA_COLOUR_WHITE = 15,
};

uint32_t row;
uint32_t col;
uint8_t colour;

void display_init();
void clear_screen();

void kprint(char *p);
void set_colour(uint8_t c);

#endif // OS_DISPLAY