#include <stdio.h>
#include <string.h>

#define FILENAME_SIZE 256
#define TEXT_SIZE 1024

int main(void) {
    char filename[FILENAME_SIZE];
    char text[TEXT_SIZE];

    printf("Enter filename: ");
    if (fgets(filename, sizeof(filename), stdin) == NULL) {
        fprintf(stderr, "Could not read filename.\n");
        return 1;
    }

    size_t filename_length = strcspn(filename, "\n");
    if (filename[filename_length] == '\n') {
        filename[filename_length] = '\0';
    } else if (!feof(stdin)) {
        int character;
        while ((character = getchar()) != '\n' && character != EOF) {
        }
        fprintf(stderr, "Filename is too long.\n");
        return 1;
    }

    if (filename[0] == '\0') {
        fprintf(stderr, "Filename cannot be empty.\n");
        return 1;
    }

    printf("Enter a line of text to append: ");
    if (fgets(text, sizeof(text), stdin) == NULL) {
        fprintf(stderr, "Could not read text.\n");
        return 1;
    }

    size_t text_length = strcspn(text, "\n");
    if (text[text_length] == '\n') {
        text[text_length] = '\0';
    } else if (!feof(stdin)) {
        int character;
        while ((character = getchar()) != '\n' && character != EOF) {
        }
        fprintf(stderr, "Text is too long.\n");
        return 1;
    }

    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        perror("Could not open file in append mode");
        return 1;
    }

    if (fprintf(file, "%s\n", text) < 0) {
        perror("Could not append text");
        fclose(file);
        return 1;
    }

    if (fclose(file) != 0) {
        perror("Could not close file");
        return 1;
    }

    printf("Text appended successfully.\n");
    return 0;
}