#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    size_t capacity = 128;
    size_t length = 0;
    char *text = malloc(capacity);
    if (text == NULL) {
        perror("malloc");
        return 1;
    }

    int ch;
    while ((ch = getchar()) != EOF && ch != '\n') {
        if (length + 1 >= capacity) {
            if (capacity > SIZE_MAX / 2) {
                fprintf(stderr, "Input is too long.\n");
                free(text);
                return 1;
            }

            size_t new_capacity = capacity * 2;
            char *new_text = realloc(text, new_capacity);
            if (new_text == NULL) {
                perror("realloc");
                free(text);
                return 1;
            }
            text = new_text;
            capacity = new_capacity;
        }
        text[length++] = (char)ch;
    }

    if (ch == EOF && ferror(stdin)) {
        perror("input");
        free(text);
        return 1;
    }

    if (length > 0 && text[length - 1] == '\r') {
        --length;
    }
    text[length] = '\0';

    int capitalize_next = 1;
    for (size_t i = 0; i < length; ++i) {
        unsigned char current = (unsigned char)text[i];
        if (isalpha(current)) {
            text[i] = (char)(capitalize_next ? toupper(current) : tolower(current));
            capitalize_next = 0;
        } else if (current == '.' || current == '?' || current == '!') {
            capitalize_next = 1;
        }
    }

    printf("%s\n", text);
    free(text);
    return 0;
}