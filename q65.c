#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

static char *read_word(void)
{
    size_t capacity = 128;
    size_t length = 0;
    char *word = malloc(capacity);

    if (word == NULL) {
        return NULL;
    }

    int ch;
    do {
        ch = getchar();
    } while (ch != EOF && (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r' ||
                           ch == '\f' || ch == '\v'));

    if (ch == EOF) {
        free(word);
        return NULL;
    }

    do {
        if (length + 1 == capacity) {
            if (capacity > SIZE_MAX / 2) {
                free(word);
                return NULL;
            }

            size_t new_capacity = capacity * 2;
            char *new_word = realloc(word, new_capacity);
            if (new_word == NULL) {
                free(word);
                return NULL;
            }
            word = new_word;
            capacity = new_capacity;
        }

        word[length++] = (char)ch;
        ch = getchar();
    } while (ch != EOF && ch != ' ' && ch != '\t' && ch != '\n' && ch != '\r' &&
             ch != '\f' && ch != '\v');

    word[length] = '\0';
    return word;
}

int main(void)
{
    char *s = read_word();
    if (s == NULL) {
        fprintf(stderr, "Failed to read the first string.\n");
        return 1;
    }

    char *t = read_word();
    if (t == NULL) {
        fprintf(stderr, "Failed to read the second string.\n");
        free(s);
        return 1;
    }

    size_t frequencies[26] = {0};
    for (size_t i = 0; s[i] != '\0'; ++i) {
        ++frequencies[s[i] - 'a'];
    }
    int is_anagram = 1;
    for (size_t i = 0; t[i] != '\0'; ++i) {
        size_t letter = (size_t)(t[i] - 'a');
        if (frequencies[letter] == 0) {
            is_anagram = 0;
        } else {
            --frequencies[letter];
        }
    }

    for (size_t i = 0; i < 26; ++i) {
        if (frequencies[i] != 0) {
            is_anagram = 0;
            break;
        }
    }

    printf("%s\n", is_anagram ? "Anagram" : "Not Anagram");
    free(s);
    free(t);
    return 0;
}