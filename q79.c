#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define TOKEN_SIZE 256

int main(void) {
    FILE *file = fopen("numbers.txt", "r");
    if (file == NULL) {
        perror("Could not open numbers.txt");
        return 1;
    }

    long long sum = 0;
    unsigned long long count = 0;
    char token[TOKEN_SIZE];
    int status;

    while ((status = fscanf(file, "%255s", token)) == 1) {
        char *end;
        errno = 0;
        long long value = strtoll(token, &end, 10);
        if (errno == ERANGE || end == token || *end != '\0') {
            fprintf(stderr, "Invalid integer in numbers.txt: %s\n", token);
            fclose(file);
            return 1;
        }

        if ((value > 0 && sum > LLONG_MAX - value) ||
            (value < 0 && sum < LLONG_MIN - value)) {
            fprintf(stderr, "Sum exceeds the supported integer range.\n");
            fclose(file);
            return 1;
        }
        if (count == ULLONG_MAX) {
            fprintf(stderr, "Too many integers in numbers.txt.\n");
            fclose(file);
            return 1;
        }

        sum += value;
        count++;
    }

    if (ferror(file)) {
        perror("Could not read numbers.txt");
        fclose(file);
        return 1;
    }

    if (fclose(file) != 0) {
        perror("Could not close numbers.txt");
        return 1;
    }

    if (status != EOF) {
        fprintf(stderr, "Could not read an integer from numbers.txt.\n");
        return 1;
    }

    if (count == 0) {
        fprintf(stderr, "numbers.txt contains no integers.\n");
        return 1;
    }

    printf("Sum: %lld\n", sum);
    printf("Average: %.2f\n", (double)sum / (double)count);
    return 0;
}