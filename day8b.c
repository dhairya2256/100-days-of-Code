/*
Q16: Write a program to input three numbers and find the largest among them using if–else.
*/
#include <stdio.h>

int main(void)
{
    double a, b, c;
    printf("Enter three numbers separated by spaces: ");
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3) {
        fprintf(stderr, "Invalid input\n");
        return 1;
    }

    if (a >= b && a >= c)
        printf("Largest = %.2f\n", a);
    else if (b >= a && b >= c)
        printf("Largest = %.2f\n", b);
    else
        printf("Largest = %.2f\n", c);

    return 0;
}
