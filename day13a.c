/*
Q25 (Conditional Statements)

Write a program to implement a basic calculator using switch-case for +, -, *, /, %.
*/

#include <stdio.h>

int main() {
    char op;
    double a, b, result;

    printf("Enter operator (+, -, *, /, %%): ");
    scanf(" %c", &op);

    printf("Enter two numbers: ");
    scanf("%lf %lf", &a, &b);

    switch (op) {
        case '+':
            result = a + b;
            printf("Result: %.2lf\n", result);
            break;
        case '-':
            result = a - b;
            printf("Result: %.2lf\n", result);
            break;
        case '*':
            result = a * b;
            printf("Result: %.2lf\n", result);
            break;
        case '/':
            if (b == 0) {
                printf("Error: Division by zero is not allowed.\n");
            } else {
                result = a / b;
                printf("Result: %.2lf\n", result);
            }
            break;
        case '%':
            if ((int)b == 0) {
                printf("Error: Modulo by zero is not allowed.\n");
            } else {
                result = (int)a % (int)b;
                printf("Result: %.0lf\n", result);
            }
            break;
        default:
            printf("Invalid operator.\n");
    }

    return 0;
}
