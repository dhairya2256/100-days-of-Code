#include <stdio.h>

enum Direction {
    NORTH = 1,
    EAST,
    SOUTH,
    WEST
};

int main(void) {
    const char *direction_names[] = {"NORTH", "EAST", "SOUTH", "WEST"};

    for (enum Direction direction = NORTH; direction <= WEST; direction++) {
        printf("%s = %d\n", direction_names[direction - NORTH], direction);
    }

    return 0;
}