#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c, discriminant, root1, root2;
    
    printf("Enter coefficients of quadratic equation ax^2 + bx + c = 0:\n");
    printf("Enter a: ");
    scanf("%lf", &a);
    printf("Enter b: ");
    scanf("%lf", &b);
    printf("Enter c: ");
    scanf("%lf", &c);
    
    // Check if it's a valid quadratic equation
    if (a == 0) {
        printf("Error: 'a' cannot be zero. Not a quadratic equation.\n");
        return 1;
    }
    
    // Calculate discriminant
    discriminant = (b * b) - (4 * a * c);
    
    // Categorize and find roots based on discriminant
    if (discriminant > 0) {
        // Two distinct real roots
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("\nRoots are real and distinct:\n");
        printf("Root 1: %.2lf\n", root1);
        printf("Root 2: %.2lf\n", root2);
    }
    else if (discriminant == 0) {
        // One repeated real root
        root1 = -b / (2 * a);
        printf("\nRoots are real and equal:\n");
        printf("Root: %.2lf\n", root1);
    }
    else {
        // Complex roots
        double realPart = -b / (2 * a);
        double imaginaryPart = sqrt(-discriminant) / (2 * a);
        printf("\nRoots are complex and conjugate:\n");
        printf("Root 1: %.2lf + %.2lfi\n", realPart, imaginaryPart);
        printf("Root 2: %.2lf - %.2lfi\n", realPart, imaginaryPart);
    }
    
    return 0;
}