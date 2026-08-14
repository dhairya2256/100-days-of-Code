/*
Q10: Write a program to input time in seconds and convert it to hours:minutes:seconds format.
*/
#include <stdio.h>

int main(void)
{
    long seconds;

    printf("Enter time in seconds: ");
    if (scanf("%ld", &seconds) != 1) {
        fprintf(stderr, "Invalid input\n");
        return 1;
    }

    if (seconds < 0) {
        fprintf(stderr, "Negative seconds not allowed\n");
        return 1;
    }

    long hours = seconds / 3600;
    long minutes = (seconds % 3600) / 60;
    long secs = seconds % 60;

    printf("%ld seconds = %02ld:%02ld:%02ld\n", seconds, hours, minutes, secs);

    return 0;
}
