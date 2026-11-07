#include <stdio.h>

enum Operation {
    ADD = 1,
    SUBTRACT,
    MULTIPLY
};

int main(void) {
    int choice;
    double first_number;
    double second_number;

    printf("Choose an operation:\n");
    printf("%d. ADD\n", ADD);
    printf("%d. SUBTRACT\n", SUBTRACT);
    printf("%d. MULTIPLY\n", MULTIPLY);
    printf("Enter your choice: ");

    if (scanf("%d", &choice) != 1) {
        fprintf(stderr, "Invalid choice. Enter 1, 2, or 3.\n");
        return 1;
    }

    if (choice < ADD || choice > MULTIPLY) {
        fprintf(stderr, "Invalid choice. Enter 1, 2, or 3.\n");
        return 1;
    }

    printf("Enter two numbers: ");
    if (scanf("%lf %lf", &first_number, &second_number) != 2) {
        fprintf(stderr, "Invalid input. Enter two numbers.\n");
        return 1;
    }

    switch ((enum Operation)choice) {
        case ADD:
            printf("Result: %.2f\n", first_number + second_number);
            break;
        case SUBTRACT:
            printf("Result: %.2f\n", first_number - second_number);
            break;
        case MULTIPLY:
            printf("Result: %.2f\n", first_number * second_number);
            break;
    }

    return 0;
}