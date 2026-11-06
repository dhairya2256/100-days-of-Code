#include <stdio.h>

enum Number {
    FIRST = 10,
    SECOND = 11,
    THIRD = 12
};

int main(void) {
    printf("FIRST = %d\n", FIRST);
    printf("SECOND = %d\n", SECOND);
    printf("THIRD = %d\n", THIRD);

    return 0;
}