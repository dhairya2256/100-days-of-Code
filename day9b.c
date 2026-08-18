#include <stdio.h>

int main() {
    int percentage;
    char grade;
    
    printf("Enter the percentage (0-100): ");
    scanf("%d", &percentage);
    
    // Validate input
    if (percentage < 0 || percentage > 100) {
        printf("Error: Percentage must be between 0 and 100.\n");
        return 1;
    }
    
    // Assign grade based on percentage
    if (percentage >= 90) {
        grade = 'A';
    }
    else if (percentage >= 80) {
        grade = 'B';
    }
    else if (percentage >= 70) {
        grade = 'C';
    }
    else if (percentage >= 60) {
        grade = 'D';
    }
    else {
        grade = 'F';
    }
    
    // Display results
    printf("\nPercentage: %d%%\n", percentage);
    printf("Grade: %c\n", grade);
    
    return 0;
}