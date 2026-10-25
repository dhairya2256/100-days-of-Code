#include <stdio.h>

int main(void) {
    FILE *file = fopen("info.txt", "r");
    if (file == NULL) {
        perror("Could not open info.txt");
        return 1;
    }

    unsigned long long character_count = 0;
    unsigned long long word_count = 0;
    unsigned long long line_count = 0;
    int in_word = 0;
    int last_character = '\0';
    int character;

    while ((character = fgetc(file)) != EOF) {
        character_count++;
        last_character = character;

        if (character == '\n') {
            line_count++;
        }

        if (character == ' ' || character == '\n') {
            in_word = 0;
        } else if (!in_word) {
            word_count++;
            in_word = 1;
        }
    }

    if (ferror(file)) {
        perror("Could not read info.txt");
        fclose(file);
        return 1;
    }

    if (character_count > 0 && last_character != '\n') {
        line_count++;
    }

    if (fclose(file) != 0) {
        perror("Could not close info.txt");
        return 1;
    }

    printf("Characters: %llu\n", character_count);
    printf("Words: %llu\n", word_count);
    printf("Lines: %llu\n", line_count);

    return 0;
}