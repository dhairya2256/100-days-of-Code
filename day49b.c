#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char name[100];
    char *token;
    char *lastName = NULL;
    char *words[20];
    int count = 0, i;

    printf("Enter a name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    token = strtok(name, " ");
    while (token != NULL) {
        words[count++] = token;
        lastName = token;
        token = strtok(NULL, " ");
    }

    for (i = 0; i < count - 1; i++) {
        printf("%c.", toupper((unsigned char)words[i][0]));
        if (i < count - 2)
            printf(" ");
    }

    if (count > 1) {
        printf(" %s", lastName);
    } else if (count == 1) {
        printf("%s", lastName);
    }

    printf("\n");
    return 0;
}
