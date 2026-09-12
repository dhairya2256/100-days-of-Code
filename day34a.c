#include <stdio.h>

int main(void) {
	int numbers[100], n, position, element;

	printf("Enter number of elements: ");
	scanf("%d", &n);

	if (n < 0 || n >= 100) {
		printf("Invalid number of elements.\n");
		return 1;
	}

	printf("Enter %d elements:\n", n);
	for (int index = 0; index < n; index++) {
		scanf("%d", &numbers[index]);
	}

	printf("Enter position (1-%d): ", n + 1);
	scanf("%d", &position);

	if (position < 1 || position > n + 1) {
		printf("Invalid position.\n");
		return 1;
	}

	printf("Enter element to insert: ");
	scanf("%d", &element);

	for (int index = n; index >= position; index--) {
		numbers[index] = numbers[index - 1];
	}
	numbers[position - 1] = element;
	n++;

	printf("Array after insertion: ");
	for (int index = 0; index < n; index++) {
		printf("%d ", numbers[index]);
	}
	printf("\n");

	return 0;
}
