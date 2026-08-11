// C Program to calculate the area and circumference of a circle

#include <stdio.h>

int main() {
    float radius, area, circumference;
    float pi = 3.14159;

    printf("Enter radius: ");
    scanf("%f", &radius);

    area = pi * radius * radius;
    circumference = 2 * pi * radius;

    printf("Area = %.2f\n", area);
    printf("Circumference = %.2f\n", circumference);

    return 0;
}