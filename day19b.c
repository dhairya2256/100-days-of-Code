
/*
Q38 (Loops without Arrays/Strings)

Write a program to find the sum of digits of a number.
*/

#include <stdio.h>

int main() {
	int number, digit, sum = 0;

	printf("Enter a number: ");
	scanf("%d", &number);

	if (number < 0) {
		number = -number;
	}

	while (number > 0) {
		digit = number % 10;
		sum += digit;
		number /= 10;
	}

	printf("Sum of digits = %d\n", sum);

	return 0;
}
