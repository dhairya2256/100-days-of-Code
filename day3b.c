#include <stdio.h>

int main(void)
{
    int a, b, temp;

    printf("Enter first number: ");
    if (scanf("%d", &a) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    printf("Enter second number: ");
    if (scanf("%d", &b) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    printf("Before swap: a = %d, b = %d\n", a, b);

    temp = a;
    a = b;
    b = temp;

    printf("After swap: a = %d, b = %d\n", a, b);
    return 0;
}
