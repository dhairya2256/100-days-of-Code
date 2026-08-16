/*
Q14: Write a program to input a character and check whether it is a vowel or consonant using if–else.
*/
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char ch;
    printf("Enter a character: ");
    if (scanf(" %c", &ch) != 1) {
        fprintf(stderr, "Invalid input\n");
        return 1;
    }

    if (!isalpha((unsigned char)ch)) {
        printf("%c is not an alphabet character\n", ch);
        return 0;
    }

    char lower = tolower((unsigned char)ch);
    if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u')
        printf("%c is a vowel\n", ch);
    else
        printf("%c is a consonant\n", ch);

    return 0;
}
