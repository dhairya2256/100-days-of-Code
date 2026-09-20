#include <stdio.h>

int main() {
    char str[100];
    int length = 0, i, j;
    char temp;

    printf("Enter a string: ");
    scanf("%s", str);

    while (str[length] != '\0') {
        length++;
    }

    for (i = 0, j = length - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }

    printf("Reversed string: %s\n", str);

    return 0;
}
