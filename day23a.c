#include <stdio.h>

int main() {
    int n, i;
    float sum = 0.0f;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        int numerator = 2 * i;
        int denominator = 2 * i + 1;
        sum += (float)numerator / denominator;
    }

    printf("Sum of the series = %.2f\n", sum);
    return 0;
}
