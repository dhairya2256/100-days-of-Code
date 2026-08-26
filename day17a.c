
/*
Q33 (Loops without Arrays/Strings)

Write a program to check if a number is an Armstrong number.
*/

#include <stdio.h>

int main() {
	unsigned long long number, original, temporary;
	unsigned long long sum = 0;
	int digits = 0;

	printf("Enter a number: ");
	scanf("%llu", &number);

	original = number;
	temporary = number;

	if (temporary == 0) {
		digits = 1;
	} else {
		while (temporary > 0) {
			digits++;
			temporary /= 10;
		}
	}

	temporary = number;
	while (temporary > 0) {
		unsigned long long digit = temporary % 10;
		unsigned long long power = 1;

		for (int i = 0; i < digits; i++) {
			power *= digit;
		}

		sum += power;
		temporary /= 10;
	}

	if (sum == original) {
		printf("Armstrong number\n");
	} else {
		printf("Not an Armstrong number\n");
	}

	return 0;
}
