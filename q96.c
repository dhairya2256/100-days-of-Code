#include <stdio.h>

struct Date {
    int day;
    int month;
    int year;
};

struct Employee {
    char name[50];
    int employee_id;
    float salary;
    struct Date joining_date;
};

int main(void) {
    struct Employee employee;

    printf("Enter employee name: ");
    if (scanf("%49s", employee.name) != 1) {
        fprintf(stderr, "Could not read employee name.\n");
        return 1;
    }

    printf("Enter employee ID: ");
    if (scanf("%d", &employee.employee_id) != 1) {
        fprintf(stderr, "Invalid employee ID.\n");
        return 1;
    }

    printf("Enter salary: ");
    if (scanf("%f", &employee.salary) != 1) {
        fprintf(stderr, "Invalid salary.\n");
        return 1;
    }

    printf("Enter joining date (day month year): ");
    if (scanf("%d %d %d", &employee.joining_date.day,
              &employee.joining_date.month, &employee.joining_date.year) != 3) {
        fprintf(stderr, "Invalid joining date.\n");
        return 1;
    }

    printf("\nEmployee details:\n");
    printf("Name: %s\n", employee.name);
    printf("Employee ID: %d\n", employee.employee_id);
    printf("Salary: %.2f\n", employee.salary);
    printf("Joining date: %02d/%02d/%04d\n",
           employee.joining_date.day, employee.joining_date.month,
           employee.joining_date.year);

    return 0;
}