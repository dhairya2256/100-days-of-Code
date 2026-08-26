
/*
Q31 (Loops without Arrays/Strings)

Write a program to take a number as input and print its equivalent binary representation.
*/

#include <stdio.h>

int main() {
	unsigned int number;
	unsigned int place = 1;

	printf("Enter a number: ");
	scanf("%u", &number);

	if (number == 0) {
		printf("Binary representation: 0\n");
		return 0;
	}

	while (place <= number / 2) {
		place *= 2;
	}

	printf("Binary representation: ");
	while (place > 0) {
		printf("%u", number / place);
		number %= place;
		place /= 2;
	}
	printf("\n");

	return 0;
}
