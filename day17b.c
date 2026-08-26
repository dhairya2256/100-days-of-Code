
/*
Q34 (Loops without Arrays/Strings)

Write a program to check if a number is prime.
*/

#include <stdio.h>

int main() {
	int number;
	int is_prime = 1;

	printf("Enter a number: ");
	scanf("%d", &number);

	if (number < 2) {
		is_prime = 0;
	} else {
		for (int i = 2; i * i <= number; i++) {
			if (number % i == 0) {
				is_prime = 0;
				break;
			}
		}
	}

	if (is_prime) {
		printf("Prime number\n");
	} else {
		printf("Not a prime number\n");
	}

	return 0;
}
