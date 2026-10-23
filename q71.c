#include <stdio.h>
#include <string.h>

int main(void) {
    char name[100];
    int age;

    printf("Enter your name: ");
    if (fgets(name, sizeof(name), stdin) == NULL) {
        fprintf(stderr, "Could not read name.\n");
        return 1;
    }
    name[strcspn(name, "\n")] = '\0';

    printf("Enter your age: ");
    if (scanf("%d", &age) != 1) {
        fprintf(stderr, "Invalid age.\n");
        return 1;
    }

    FILE *file = fopen("info.txt", "w");
    if (file == NULL) {
        perror("Could not open info.txt");
        return 1;
    }

    if (fprintf(file, "Name: %s\nAge: %d\n", name, age) < 0) {
        fprintf(stderr, "Could not write data to info.txt.\n");
        fclose(file);
        return 1;
    }

    if (fclose(file) != 0) {
        perror("Could not close info.txt");
        return 1;
    }

    printf("Data was successfully saved to info.txt.\n");
    return 0;
}