#include <stdio.h>

int main() {
    int num, first, last, digits = 0, temp, swapped, factor;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num < 0) {
        num = -num;
    }

    temp = num;
    while (temp > 0) {
        digits++;
        temp /= 10;
    }

    if (digits < 2) {
        printf("Swapped number: %d\n", num);
        return 0;
    }

    last = num % 10;
    temp = num;
    while (temp >= 10) {
        temp /= 10;
    }
    first = temp;

    factor = 1;
    for (int i = 1; i < digits; i++) {
        factor *= 10;
    }

    swapped = num - (first * factor) - last + (last * factor) + first;
    printf("Swapped number: %d\n", swapped);

    return 0;
}
