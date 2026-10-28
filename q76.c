#include <stdio.h>
#include <string.h>

#define FILENAME_SIZE 256

int main(void) {
    char filename[FILENAME_SIZE];

    printf("Enter filename: ");
    if (fgets(filename, sizeof(filename), stdin) == NULL) {
        fprintf(stderr, "Could not read filename.\n");
        return 1;
    }

    size_t length = strcspn(filename, "\n");
    if (filename[length] == '\n') {
        filename[length] = '\0';
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

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Could not open file");
        return 1;
    }

    int character;
    while ((character = fgetc(file)) != EOF) {
        if (putchar(character) == EOF) {
            perror("Could not display file content");
            fclose(file);
            return 1;
        }
    }

    if (ferror(file)) {
        perror("Could not read file");
        fclose(file);
        return 1;
    }

    if (fclose(file) != 0) {
        perror("Could not close file");
        return 1;
    }

    return 0;
}