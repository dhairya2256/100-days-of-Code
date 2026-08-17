/*
Q15: Write a program to input a character and check whether it is an uppercase alphabet, lowercase alphabet, digit, or special character.
*/
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int c;
    printf("Enter a character: ");
    if ((c = getchar()) == EOF) {
        fprintf(stderr, "No input\n");
        return 1;
    }

    /* skip newline if user pressed Enter after entering nothing */
    if (c == '\n') {
        c = getchar();
        if (c == EOF) {
            fprintf(stderr, "No input\n");
            return 1;
        }
    }

    if (isupper((unsigned char)c))
        printf("%c is an uppercase alphabet\n", c);
    else if (islower((unsigned char)c))
        printf("%c is a lowercase alphabet\n", c);
    else if (isdigit((unsigned char)c))
        printf("%c is a digit\n", c);
    else
        printf("%c is a special character\n", c);

    return 0;
}
