#include <ctype.h>
#include <stdio.h>

int main(void) {
    FILE *input = fopen("input.txt", "r");
    if (input == NULL) {
        perror("Could not open input.txt");
        return 1;
    }

    FILE *output = fopen("output.txt", "w");
    if (output == NULL) {
        perror("Could not open output.txt");
        fclose(input);
        return 1;
    }

    int character;
    while ((character = fgetc(input)) != EOF) {
        int uppercase_character = toupper((unsigned char)character);
        if (fputc(uppercase_character, output) == EOF) {
            perror("Could not write to output.txt");
            fclose(input);
            fclose(output);
            return 1;
        }
    }

    if (ferror(input)) {
        perror("Could not read input.txt");
        fclose(input);
        fclose(output);
        return 1;
    }

    if (fclose(input) != 0) {
        perror("Could not close input.txt");
        fclose(output);
        return 1;
    }

    if (fclose(output) != 0) {
        perror("Could not close output.txt");
        return 1;
    }

    printf("Converted text written to output.txt.\n");
    return 0;
}
