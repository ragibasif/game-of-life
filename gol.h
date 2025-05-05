// gol.h

// includes
#include "ANSI.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

// defines
#define BUFFER_HEIGHT 40 // rows
#define BUFFER_WIDTH 40  // cols

// #define ALIVE 1
// #define DEAD 0

#define MOD(a, b) (a % b + b) % b

// #define ANSI_CLEAR_SCREEN printf("\x1b[1;1H\e[2J")
// #define ANSI_RESET_CURSOR(x, y) printf(ANSI_CURSOR_UP(x) ANSI_CURSOR_BACK(y))

bool check_empty_buffer(void);

void display_buffer(void);

int count_neighbors(int y, int x);

void create_next_state(void);

// still lifes
void block(void);
void bee_hive(void);

// oscillators
// spaceships

int main(int argc, char **argv);
