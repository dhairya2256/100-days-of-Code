/*
Q35 (Loops without Arrays/Strings)

Write a program to print all factors of a given number.
*/

#include <stdio.h>

int main() {
	int number, i;

	printf("Enter a number: ");
	scanf("%d", &number);

	if (number <= 0) {
		printf("Please enter a positive number.\n");
	} else {
		printf("Factors of %d are: ", number);

		for (i = 1; i <= number; i++) {
			if (number % i == 0) {
				printf("%d ", i);
			}
		}

		printf("\n");
	}

	return 0;
}
