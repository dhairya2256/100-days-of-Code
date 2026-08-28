
/*
Q37 (Loops without Arrays/Strings)

Write a program to find the LCM of two numbers.
*/

#include <stdio.h>

int main() {
	int first, second, a, b, remainder;
	int hcf, lcm;

	printf("Enter two numbers: ");
	scanf("%d %d", &first, &second);

	if (first < 0) {
		first = -first;
	}
	if (second < 0) {
		second = -second;
	}

	if (first == 0 || second == 0) {
		lcm = 0;
	} else {
		a = first;
		b = second;

		while (b != 0) {
			remainder = a % b;
			a = b;
			b = remainder;
		}

		hcf = a;
		lcm = (first / hcf) * second;
	}

	printf("LCM = %d\n", lcm);

	return 0;
}
