#include <stdio.h>

int main(void)
{
	int a, b;
	printf("Enter two integers: ");
	if (scanf("%d %d", &a, &b) != 2) {
		fprintf(stderr, "Invalid input\n");
		return 1;
	}

	printf("Before swap: a = %d, b = %d\n", a, b);

	/* Swap without third variable using arithmetic */
	a = a + b;
	b = a - b;
	a = a - b;

	printf("After swap (arithmetic): a = %d, b = %d\n", a, b);
	/*
	Alternative XOR method (works for integers):
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	*/

	return 0;

}

