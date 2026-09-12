#include <stdio.h>

int main(void) {
	int numbers[100], n, position;

	printf("Enter number of elements: ");
	scanf("%d", &n);

	if (n <= 0 || n > 100) {
		printf("Invalid number of elements.\n");
		return 1;
	}

	printf("Enter %d elements:\n", n);
	for (int index = 0; index < n; index++) {
		scanf("%d", &numbers[index]);
	}

	printf("Enter position to delete (1-%d): ", n);
	scanf("%d", &position);

	if (position < 1 || position > n) {
		printf("Invalid position.\n");
		return 1;
	}

	for (int index = position - 1; index < n - 1; index++) {
		numbers[index] = numbers[index + 1];
	}
	n--;

	printf("Array after deletion: ");
	for (int index = 0; index < n; index++) {
		printf("%d ", numbers[index]);
	}
	printf("\n");

	return 0;
}
