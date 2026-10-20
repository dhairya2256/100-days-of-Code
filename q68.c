#include <stdio.h>

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1 || n < 0) {
        fprintf(stderr, "Invalid array size.\n");
        return 1;
    }

    int missing = n;
    for (int i = 0; i < n; ++i) {
        int value;
        if (scanf("%d", &value) != 1) {
            fprintf(stderr, "Invalid array element.\n");
            return 1;
        }
        if (value < 0 || value > n) {
            fprintf(stderr, "Array elements must be between 0 and n.\n");
            return 1;
        }

        missing ^= i ^ value;
    }

    printf("%d\n", missing);
    return 0;
}