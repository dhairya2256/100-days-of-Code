#include <stdio.h>
// to add 2 numbers taken from user
int main()
{
    int a;
    int b;
    printf("enter your 1st number: ");
    scanf("%d", &a);
    printf("enter your 2nd number: ");
    scanf("%d", &b);
    printf("the sum of both numbers is : %d", a+b);
    return 0;
}