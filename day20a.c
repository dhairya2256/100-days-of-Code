/*
Q39: Write a program to find the product of odd digits of a number.
*/

#include <stdio.h>

int main() {
    int number, digit, product = 1;

    printf("Enter a number: ");
    scanf("%d", &number);

    if (number < 0) {
        number = -number;
    }

    if (number == 0) {
        printf("Product of odd digits = 0\n");
        return 0;
    }

    while (number > 0) {
        digit = number % 10;
        if (digit % 2 != 0) {
            product *= digit;
        }
        number /= 10;
    }

    printf("Product of odd digits = %d\n", product);
    return 0;
}
