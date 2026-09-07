#include <stdio.h>

int main(void) {
	int numbers[100], n;

	printf("Enter number of elements: ");
	scanf("%d", &n);

	printf("Enter %d elements:\n", n);
	for (int index = 0; index < n; index++) {
		scanf("%d", &numbers[index]);
	}

	int minimum = numbers[0];
	int maximum = numbers[0];

	for (int index = 1; index < n; index++) {
		if (numbers[index] < minimum) {
			minimum = numbers[index];
		}
		if (numbers[index] > maximum) {
			maximum = numbers[index];
		}
	}

	printf("Minimum element: %d\n", minimum);
	printf("Maximum element: %d\n", maximum);

	return 0;
}
