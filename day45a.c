#include <stdio.h>
#include <string.h>

int main() {
    char str[100], ch;
    int count = 0, i;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    printf("Enter a character to count: ");
    scanf(" %c", &ch);

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == ch) {
            count++;
        }
    }

    printf("Frequency of '%c' in \"%s\" is %d\n", ch, str, count);
    return 0;
}
