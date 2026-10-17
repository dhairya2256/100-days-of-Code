#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    size_t capacity = 128;
    size_t length = 0;
    char *input = malloc(capacity);

    if (input == NULL) {
        perror("malloc");
        return 1;
    }

    int ch;
    while ((ch = getchar()) != EOF && ch != '\n') {
        if (length == capacity) {
            if (capacity > SIZE_MAX / 2) {
                fprintf(stderr, "Input is too large\n");
                free(input);
                return 1;
            }

            size_t new_capacity = capacity * 2;
            char *new_input = realloc(input, new_capacity);
            if (new_input == NULL) {
                perror("realloc");
                free(input);
                return 1;
            }
            input = new_input;
            capacity = new_capacity;
        }

        input[length++] = (char)ch;
    }

    if (length > 0 && input[length - 1] == '\r') {
        --length;
    }

    size_t last_seen[UCHAR_MAX + 1];
    for (size_t i = 0; i < UCHAR_MAX + 1; ++i) {
        last_seen[i] = SIZE_MAX;
    }

    size_t window_start = 0;
    size_t longest = 0;
    for (size_t i = 0; i < length; ++i) {
        unsigned char current = (unsigned char)input[i];

        if (last_seen[current] != SIZE_MAX && last_seen[current] >= window_start) {
            window_start = last_seen[current] + 1;
        }

        last_seen[current] = i;
        size_t window_length = i - window_start + 1;
        if (window_length > longest) {
            longest = window_length;
        }
    }

    printf("%zu\n", longest);
    free(input);
    return 0;
}
