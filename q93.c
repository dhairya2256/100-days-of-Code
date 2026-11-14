#include <stdio.h>

#define STUDENT_COUNT 5

struct Student {
    char name[50];
    int roll_no;
    float marks;
};

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

    int highest_index = 0;
    for (int i = 1; i < STUDENT_COUNT; i++) {
        if (students[i].marks > students[highest_index].marks) {
            highest_index = i;
        }
    }

    printf("\nStudent with the highest marks:\n");
    printf("Name: %s\n", students[highest_index].name);
    printf("Roll number: %d\n", students[highest_index].roll_no);
    printf("Marks: %.2f\n", students[highest_index].marks);

    return 0;
}