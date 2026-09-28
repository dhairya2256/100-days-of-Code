#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char date[20];
    int day, month, year;
    char *monthName[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                         "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    printf("Enter date in dd/mm/yyyy format: ");
    scanf("%s", date);

    sscanf(date, "%d/%d/%d", &day, &month, &year);

    if (month < 1 || month > 12) {
        printf("Invalid month value.\n");
        return 1;
    }

    printf("Formatted date: %02d-%s-%d\n", day, monthName[month - 1], year);
    return 0;
}
