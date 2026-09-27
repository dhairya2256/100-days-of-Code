#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char name[100];
    int i, len;
    int printInitial = 1;

    printf("Enter a name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    len = strlen(name);

    for (i = 0; i < len; i++) {
        if (printInitial && name[i] != ' ') {
            printf("%c", toupper((unsigned char)name[i]));
            printInitial = 0;
        } else if (name[i] == ' ') {
            printInitial = 1;
        }
    }

    printf("\n");
    return 0;
}
