// gol.c
// Every cell interacts with its eight neighbours, which are the cells that are
// horizontally, vertically, or diagonally adjacent
//
// Any live cell with fewer than two live neighbours dies, as if by
// underpopulation. Any live cell with two or three live neighbours lives on to
// the next generation. Any live cell with more than three live neighbours dies,
// as if by overpopulation. Any dead cell with exactly three live neighbours
// becomes a live cell, as if by reproduction.
//
// (-1,-1) (-1,0) (-1,1)
// (0,-1) (0,0) (0,1)
// (1,-1) (1,0) (1,1)

// TODO: modularize and add documentation

// includes
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

// defines
#define BUFFER_HEIGHT 16 // rows
#define BUFFER_WIDTH 16  // cols

#define MOD(a, b) (a % b + b) % b

#define ANSI_CLEAR_SCREEN printf("\x1b[1;1H\e[2J")
#define ANSI_CURSOR_UP(n) "\x1b[" #n "A"
#define ANSI_CURSOR_BACK(n) "\x1b[" #n "D"
#define RESET_CURSOR(x, y) printf(ANSI_CURSOR_UP(x) ANSI_CURSOR_BACK(y))

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
                putchar('#');
            else
                putchar('.');
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
void block(void) {
    buffer[BUFFER_HEIGHT / 2][BUFFER_WIDTH / 2] = 1;
    buffer[BUFFER_HEIGHT / 2][BUFFER_WIDTH / 2 - 1] = 1;
    buffer[BUFFER_HEIGHT / 2 - 1][BUFFER_WIDTH / 2] = 1;
    buffer[BUFFER_HEIGHT / 2 - 1][BUFFER_WIDTH / 2 - 1] = 1;
}

void bee_hive(void) {
    buffer[BUFFER_HEIGHT / 2][BUFFER_WIDTH / 2] = 1;
    buffer[BUFFER_HEIGHT / 2][BUFFER_WIDTH / 2 - 1] = 1;
    buffer[BUFFER_HEIGHT / 2 - 1][BUFFER_WIDTH / 2 + 1] = 1;
    buffer[BUFFER_HEIGHT / 2 - 1][BUFFER_WIDTH / 2 - 1 - 1] = 1;
    buffer[BUFFER_HEIGHT / 2 - 2][BUFFER_WIDTH / 2] = 1;
    buffer[BUFFER_HEIGHT / 2 - 2][BUFFER_WIDTH / 2 - 1] = 1;
}

// oscillators
// spaceships

int main(int argc, char **argv) {
    ANSI_CLEAR_SCREEN;
    bee_hive();
    while (1) {
        display_buffer();
        create_next_state();
        memcpy(buffer, next_state_buffer, sizeof(buffer));
        RESET_CURSOR(BUFFER_HEIGHT, BUFFER_WIDTH);
        usleep(100 * 1000);
        if (check_empty_buffer()) {
            display_buffer();
            usleep(100 * 1000);
            return 0;
        }
    }
    return 0;
}
