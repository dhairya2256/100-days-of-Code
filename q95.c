#include <stdio.h>

#define STUDENT_COUNT 5

struct Student {
    char name[50];
    int roll_no;
    float marks;
};

struct Student find_top_student(const struct Student students[], int count) {
    int highest_index = 0;
    for (int i = 1; i < count; i++) {
        if (students[i].marks > students[highest_index].marks) {
            highest_index = i;
        }
    }

    return students[highest_index];
}

int main(void) {
    struct Student students[STUDENT_COUNT];

    for (int i = 0; i < STUDENT_COUNT; i++) {
        printf("Student %d name: ", i + 1);
        if (scanf("%49s", students[i].name) != 1) {
            fprintf(stderr, "Could not read student name.\n");
            return 1;
        }

        printf("Student %d roll number: ", i + 1);
        if (scanf("%d", &students[i].roll_no) != 1) {
            fprintf(stderr, "Invalid roll number.\n");
            return 1;
        }

        printf("Student %d marks: ", i + 1);
        if (scanf("%f", &students[i].marks) != 1) {
            fprintf(stderr, "Invalid marks.\n");
            return 1;
        }
    }

    struct Student top_student = find_top_student(students, STUDENT_COUNT);
    printf("\nStudent with the highest marks:\n");
    printf("Name: %s\n", top_student.name);
    printf("Roll number: %d\n", top_student.roll_no);
    printf("Marks: %.2f\n", top_student.marks);

    return 0;
}