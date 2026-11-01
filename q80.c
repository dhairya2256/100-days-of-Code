#include <stdio.h>
#include <string.h>

#define NAME_SIZE 100
#define RECORDS_FILE "students.txt"

static void discard_line(void) {
    int character;
    while ((character = getchar()) != '\n' && character != EOF) {
    }
}

int main(void) {
    int student_count;
    printf("Enter the number of students: ");
    if (scanf("%d", &student_count) != 1 || student_count <= 0) {
        fprintf(stderr, "Please enter a positive number of students.\n");
        return 1;
    }
    discard_line();

    FILE *file = fopen(RECORDS_FILE, "w");
    if (file == NULL) {
        perror("Could not open students.txt for writing");
        return 1;
    }

    for (int i = 0; i < student_count; i++) {
        char name[NAME_SIZE];
        int roll_number;
        float marks;

        printf("Student %d name: ", i + 1);
        if (fgets(name, sizeof(name), stdin) == NULL) {
            fprintf(stderr, "Could not read student name.\n");
            fclose(file);
            return 1;
        }

        size_t name_length = strcspn(name, "\n");
        if (name[name_length] == '\n') {
            name[name_length] = '\0';
        } else if (!feof(stdin)) {
            discard_line();
            fprintf(stderr, "Name is too long (maximum %d characters).\n",
                    NAME_SIZE - 1);
            fclose(file);
            return 1;
        }
        if (name[0] == '\0' || strchr(name, '\t') != NULL) {
            fprintf(stderr, "Name cannot be empty or contain tabs.\n");
            fclose(file);
            return 1;
        }

        printf("Student %d roll number: ", i + 1);
        if (scanf("%d", &roll_number) != 1 || roll_number <= 0) {
            fprintf(stderr, "Roll number must be a positive integer.\n");
            fclose(file);
            return 1;
        }

        printf("Student %d marks (0-100): ", i + 1);
        if (scanf("%f", &marks) != 1 || !(marks >= 0.0f && marks <= 100.0f)) {
            fprintf(stderr, "Marks must be a number from 0 to 100.\n");
            fclose(file);
            return 1;
        }
        discard_line();

        if (fprintf(file, "%s\t%d\t%.2f\n", name, roll_number, marks) < 0) {
            perror("Could not write student record");
            fclose(file);
            return 1;
        }
    }

    if (fclose(file) != 0) {
        perror("Could not close students.txt after writing");
        return 1;
    }

    file = fopen(RECORDS_FILE, "r");
    if (file == NULL) {
        perror("Could not open students.txt for reading");
        return 1;
    }

    printf("\nStudent records:\n");
    printf("%-30s %-12s %-8s\n", "Name", "Roll number", "Marks");
    for (int i = 0; i < student_count; i++) {
        char name[NAME_SIZE];
        int roll_number;
        float marks;
        if (fscanf(file, "%99[^\t]\t%d\t%f\n", name, &roll_number, &marks) != 3) {
            fprintf(stderr, "Could not read student record %d.\n", i + 1);
            fclose(file);
            return 1;
        }
        printf("%-30s %-12d %-8.2f\n", name, roll_number, marks);
    }

    if (ferror(file)) {
        perror("Could not read students.txt");
        fclose(file);
        return 1;
    }
    if (fclose(file) != 0) {
        perror("Could not close students.txt after reading");
        return 1;
    }

    return 0;
}