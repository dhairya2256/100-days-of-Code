/*
Q12: Write a program to input an integer and check whether it is positive, negative or zero using nested if–else.
*/
#include <stdio.h>

int main(void)
{
    int n;
    printf("Enter an integer: ");
    if (scanf("%d", &n) != 1) {
        fprintf(stderr, "Invalid input\n");
        return 1;
    }

    if (n >= 0) {
        if (n == 0)
            printf("%d is zero\n", n);
        else
            printf("%d is positive\n", n);
    } else {
        printf("%d is negative\n", n);
    }

    return 0;
}
