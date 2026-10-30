#include <ctype.h>
#include <stdio.h>

int main(void) {
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        perror("Could not open input.txt");
        return 1;
    }

    unsigned long long vowel_count = 0;
    unsigned long long consonant_count = 0;
    int character;

    while ((character = fgetc(file)) != EOF) {
        if (isalpha((unsigned char)character)) {
            int lowercase_character = tolower((unsigned char)character);
            if (lowercase_character == 'a' || lowercase_character == 'e' ||
                lowercase_character == 'i' || lowercase_character == 'o' ||
                lowercase_character == 'u') {
                vowel_count++;
            } else {
                consonant_count++;
            }
        }
    }

    if (ferror(file)) {
        perror("Could not read input.txt");
        fclose(file);
        return 1;
    }

    if (fclose(file) != 0) {
        perror("Could not close input.txt");
        return 1;
    }

    printf("Vowels: %llu\n", vowel_count);
    printf("Consonants: %llu\n", consonant_count);
    return 0;
}