/*
Q11: Write a program to input an integer and check whether it is even or odd using if–else.
*/
#include <stdio.h>

int is_even(int n)
{
    return n % 2 == 0;
}

int main(void)
{
    int n;
    printf("Enter an integer: ");
    if (scanf("%d", &n) != 1) {
        fprintf(stderr, "Invalid input\n");
        return 1;
    }

    if (is_even(n))
        printf("%d is even\n", n);
    else
        printf("%d is odd\n", n);

    return 0;
}
