#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i, j, len;

    printf("Enter a string: ");
    scanf("%s", str);

    len = strlen(str);

    printf("All substrings are:\n");
    for (i = 0; i < len; i++) {
        for (j = i; j < len; j++) {
            printf("%.*s\n", j - i + 1, &str[i]);
        }
    }

    return 0;
}
