
/*
Q32: Write a program to check if a number is a palindrome.
10
*/

#include <stdio.h>

int main() {
	int number, original, reversed = 0, remainder;

	printf("Enter a number: ");
	scanf("%d", &number);

	original = number;

	while (number != 0) {
		remainder = number % 10;
		reversed = reversed * 10 + remainder;
		number /= 10;
	}

	if (original == reversed) {
		printf("Palindrome\n");
	} else {
		printf("Not palindrome\n");
	}

	return 0;
}
