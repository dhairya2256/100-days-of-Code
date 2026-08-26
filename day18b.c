
/*
Q36 (Loops without Arrays/Strings)

Write a program to find the HCF (GCD) of two numbers.
*/

#include <stdio.h>

int main(void) {
	int first, second, remainder;

	printf("Enter two numbers: ");
	scanf("%d %d", &first, &second);

	if (first < 0) {
		first = -first;
	}
	if (second < 0) {
		second = -second;
	}

	while (second != 0) {
		remainder = first % second;
		first = second;
		second = remainder;
	}

	printf("HCF (GCD) = %d\n", first);

	return 0;
}
