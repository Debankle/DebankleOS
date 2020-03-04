#include "display.h"
#include "ports.h"
#include "../libc/stdint.h"
#include "../libc/stdio.h"


/* -------------------- */
/*   Private Functions  */
/* -------------------- */

void kscroll() {
    uint8_t *screen = (uint8_t *)VIDEO_ADDRESS;
    for (uint32_t i = 0; i < (MAX_ROWS*MAX_COLS); i++) {
        uint8_t text = screen[2*i];
        screen[2*(i-MAX_COLS)] = text;
    }
    row--;
    move_cursor(row*80+col);
}

void kprint_char(const char s) {
    uint8_t *screen = (uint8_t *)VIDEO_ADDRESS;
    if (s == '\n') {
        row += 1;
        col = 0;
    } else {
        uint32_t pos = 2*(row*80+col);
        screen[pos] = s;
        screen[pos+1] = colour;
        col++;
        if (col >= MAX_COLS) {
            col = 0;
            row += 1;
        }
    }

    if (row == MAX_ROWS) kscroll();
    else move_cursor(row*80+col);
}


/* -------------------- */
/*   Public Functions   */
/* -------------------- */

void set_colour(uint8_t c) {
    uint8_t tc = c | (0 << 4);
    colour = tc;
}

void kprint(const char *p) {
    uint8_t l = strlen(p);
    for (uint8_t i = 0; i < l; i++) {
        kprint_char(p[i]);
    }
}

void clear_screen() {
    col = 0;
    row = 0;
    for (uint32_t i = 0; i < (MAX_COLS * MAX_ROWS); i++) {
        kprint_char(' ');
    }
    col = 0;
    row = 0;
}

void display_init() {
    set_colour(15);
    clear_screen();
    move_cursor(row*80+col);

    // uint8_t *welcomeMsg = (uint8_t *)"Hello World!\nWelcome to my ";
    // uint8_t *msg2 = (uint8_t *)"OS\n";
    // uint8_t *msg3 = (uint8_t *)"DebankleOS - The piece of shit I threw together\n\n";

    // kprint(welcomeMsg);
    // set_colour(4);
    // kprint(msg2);
    // set_colour(9);
    // kprint(msg3);

    set_colour(4);
    kprint("Welcome to my OS\n");
    set_colour(9);
    kprint("DebankleOS - The piece of shit I threw together\n\n");

    set_colour(15);
}