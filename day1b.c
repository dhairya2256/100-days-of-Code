//program to take 2 values from user and do all the arithmetic operations
#include <stdio.h>
int main()
{
int a,b,c,d,e,g;
    printf("enter two numbers");
    scanf("%d %d",&a,&b);
    c=a+b;
    d=a-b;
    e=a/b;
    g=a*b;
    printf("your sum is: %d\n",c);
    printf("your difference is: %d\n",d);
    printf("your division is: %d\n",e);
    printf("your product is: %d\n",g);
return 0;
}
