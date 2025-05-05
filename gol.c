// gol.c
// https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life
//

// includes

#include "ANSI.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_HEIGHT 40 // rows
#define BUFFER_WIDTH 40  // cols

// #define ALIVE 1
// #define DEAD 0

#define MOD(a, b) (a % b + b) % b

int buffer[BUFFER_HEIGHT][BUFFER_WIDTH] = {0};
int next_state_buffer[BUFFER_HEIGHT][BUFFER_WIDTH] = {0};

bool check_empty_buffer(void) {
    int x;
    int y;
    for (y = 0; y < BUFFER_HEIGHT; y++) {
        for (x = 0; x < BUFFER_WIDTH; x++) {
            if (buffer[y][x])
                return false;
        }
    }
    return true;
}

void display_buffer(void) {
    int x;
    int y;
    for (y = 0; y < BUFFER_HEIGHT; y++) {
        for (x = 0; x < BUFFER_WIDTH; x++) {
            if (buffer[y][x])
                putchar('X');
            else
                putchar(' ');
        }
        putchar('\n');
    }
}

//
// (-1,-1) (-1,0) (-1,1)
// (0,-1) (0,0) (0,1)
// (1,-1) (1,0) (1,1)
//
int count_neighbors(int y, int x) {
    int live_neighbor_count;
    int dy;
    int dx;
    int by;
    int bx;
    live_neighbor_count = 0;
    for (dy = -1; dy <= 1; dy++) {
        for (dx = -1; dx <= 1; dx++) {
            if (dy == 0 && dx == 0)
                continue;

            by = MOD(dy + y, BUFFER_HEIGHT);
            bx = MOD(dx + x, BUFFER_WIDTH);

            if (buffer[by][bx])
                live_neighbor_count++;
        }
    }
    return live_neighbor_count;
}

void create_next_state(void) {
    // reset it next_state_buffer
    memset(next_state_buffer, 0, sizeof(next_state_buffer));
    int y;
    int x;
    int neighbors;
    for (y = 0; y < BUFFER_HEIGHT; y++) {
        for (x = 0; x < BUFFER_WIDTH; x++) {
            neighbors = count_neighbors(y, x);
            if (buffer[y][x]) {
                if (neighbors == 2 || neighbors == 3) {
                    next_state_buffer[y][x] = 1;
                }
            } else { // dead cell regens
                if (neighbors == 3) {
                    next_state_buffer[y][x] = 1;
                }
            }
        }
    }
}

// still lifes

// block = [(0, 0), (0, 1), (1, 0), (1, 1)]
void block(void) {
    buffer[0][0] = 1;
    buffer[0][1] = 1;
    buffer[1][0] = 1;
    buffer[1][1] = 1;
}

// beehive = [(1, 0), (0, 1), (0, 2), (1, 3), (2, 1), (2, 2)]
void bee_hive(void) {
    buffer[1][0] = 1;
    buffer[0][1] = 1;
    buffer[0][2] = 1;
    buffer[1][3] = 1;
    buffer[2][1] = 1;
    buffer[2][2] = 1;
}

// loaf = [(1, 0), (0, 1), (0, 2), (1, 3), (2, 1), (2, 3), (3, 2)]
// boat = [(0, 0), (0, 1), (1, 0), (1, 2), (2, 1)]
// tub = [(0, 1), (1, 0), (1, 2), (2, 1)]

// oscillators
// blinker = [(0, 1), (1, 1), (2, 1)]  # Phase 1 (vertical)
// toad = [(1, 1), (1, 2), (1, 3), (2, 0), (2, 1), (2, 2)]  # Phase 1
// beacon = [(0, 0), (0, 1), (1, 0), (2, 3), (3, 2), (3, 3)]  # Phase 1
// pulsar = [(2,0),(3,0),(4,0), (0,2),(0,3),(0,4), (5,2),(5,3),(5,4),
// (2,5),(3,5),(4,5)]  # One quadrant pentadecathlon = [(1,0), (1,1), ...,
// (1,9)]  # Horizontal line of 10 cells
//
// For Pulsar, mirror the coordinates symmetrically in all four quadrants.
// Pentadecathlon requires a larger grid (at least 20×20 to observe full
// evolution).

// spaceships
// glider = [(0, 1), (1, 2), (2, 0), (2, 1), (2, 2)]
// lwss = [(0, 1), (0, 4), (1, 0), (2, 0), (2, 4), (3, 0), (3, 1), (3, 2), (3,
// 3)]
// mwss = [(0, 2), (0, 5), (1, 0), (2, 0), (2, 5), (3, 0), (3, 1), (3, 2),
// (3, 3), (3, 4)]
// hwss = [(0, 2), (0, 6), (1, 0), (2, 0), (2, 6), (3, 0), (3, 1), (3, 2), (3,
// 3), (3, 4), (3, 5)]
//
// Directionality: Flip/rotate coordinates to change movement direction (e.g.,
// invert x/y for vertical movement).
// Grid Size: Ensure the grid is large enough to avoid boundaries (e.g., 50×50
// for HWSS). Period: All spaceships listed here have a period of 4 (they return
// to their original shape every 4 steps, shifted in space). Visualization Tips:
// Gliders are often used as "signals" in Game of Life computers.
// LWSS/MWSS/HWSS emit "glider streams" when collided with other patterns.

// Methuselahs

// r_pentomino = [(0,1),(0,2), (1,0),(1,1), (2,1)]
void r_pentomino(void) {
    buffer[0][1] = 1;
    buffer[0][2] = 1;
    buffer[1][0] = 1;
    buffer[1][1] = 1;
    buffer[2][1] = 1;
}

// diehard = [(0,6), (1,0),(1,1), (2,1),(2,5),(2,6),(2,7)]
void diehard(void) {
    buffer[0][6] = 1;
    buffer[1][0] = 1;
    buffer[1][1] = 1;
    buffer[2][1] = 1;
    buffer[2][5] = 1;
    buffer[2][6] = 1;
    buffer[2][7] = 1;
}

// acorn = [(0,1), (1,3), (2,0),(2,1),(2,4),(2,5),(2,6)]
void acorn(void) {
    buffer[0][1] = 1;
    buffer[1][3] = 1;
    buffer[2][0] = 1;
    buffer[2][1] = 1;
    buffer[2][4] = 1;
    buffer[2][5] = 1;
    buffer[2][6] = 1;
}

int main(int argc, char **argv) {
    printf(ANSI_SCREEN_CLEAR);
    acorn();
    while (1) {
        printf(ANSI_CURSOR_HIDE);
        printf(ANSI_CURSOR_SAVE);
        display_buffer();
        create_next_state();
        memcpy(buffer, next_state_buffer, sizeof(buffer));
        printf(ANSI_CURSOR_RESTORE);
        // FIX: cursor should show if CTRL-C is pressed
        printf(ANSI_CURSOR_SHOW);
        usleep(100 * 1000);
        if (check_empty_buffer()) {
            display_buffer();
            usleep(100 * 1000);
            return 0;
        }
    }
    return 0;
}
