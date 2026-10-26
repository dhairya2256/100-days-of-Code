#include <stdio.h>
#include <string.h>

#define FILENAME_SIZE 256

static int read_filename(const char *prompt, char filename[FILENAME_SIZE]) {
    printf("%s", prompt);
    if (fgets(filename, FILENAME_SIZE, stdin) == NULL) {
        fprintf(stderr, "Could not read filename.\n");
        return 0;
    }

    size_t length = strcspn(filename, "\n");
    if (filename[length] == '\n') {
        filename[length] = '\0';
    } else if (!feof(stdin)) {
        int character;
        while ((character = getchar()) != '\n' && character != EOF) {
        }
        fprintf(stderr, "Filename is too long (maximum %d characters).\n",
                FILENAME_SIZE - 1);
        return 0;
    }

    if (filename[0] == '\0') {
        fprintf(stderr, "Filename cannot be empty.\n");
        return 0;
    }

    return 1;
}

int main(void) {
    char source_name[FILENAME_SIZE];
    char destination_name[FILENAME_SIZE];

    if (!read_filename("Enter source filename: ", source_name) ||
        !read_filename("Enter destination filename: ", destination_name)) {
        return 1;
    }

    if (strcmp(source_name, destination_name) == 0) {
        fprintf(stderr, "Source and destination filenames must be different.\n");
        return 1;
    }

    FILE *source = fopen(source_name, "r");
    if (source == NULL) {
        perror("Could not open source file");
        return 1;
    }

    FILE *destination = fopen(destination_name, "w");
    if (destination == NULL) {
        perror("Could not open destination file");
        fclose(source);
        return 1;
    }

    int character;
    while ((character = fgetc(source)) != EOF) {
        if (fputc(character, destination) == EOF) {
            perror("Could not write to destination file");
            fclose(source);
            fclose(destination);
            return 1;
        }
    }

    if (ferror(source)) {
        perror("Could not read source file");
        fclose(source);
        fclose(destination);
        return 1;
    }

    if (fclose(source) != 0) {
        perror("Could not close source file");
        fclose(destination);
        return 1;
    }

    if (fclose(destination) != 0) {
        perror("Could not close destination file");
        return 1;
    }

    printf("File copied successfully.\n");
    return 0;
}