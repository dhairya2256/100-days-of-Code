#include <stdio.h>

int main(void) {
	int numbers[100], n, target;
	int left, right, middle, foundIndex = -1;

	printf("Enter number of elements: ");
	scanf("%d", &n);

	printf("Enter %d sorted elements:\n", n);
	for (int index = 0; index < n; index++) {
		scanf("%d", &numbers[index]);
	}

	printf("Enter element to search: ");
	scanf("%d", &target);

	left = 0;
	right = n - 1;
	while (left <= right) {
		middle = left + (right - left) / 2;

		if (numbers[middle] == target) {
			foundIndex = middle;
			break;
		}

		if (numbers[middle] < target) {
			left = middle + 1;
		} else {
			right = middle - 1;
		}
	}

	if (foundIndex != -1) {
		printf("Element found at position %d.\n", foundIndex + 1);
	} else {
		printf("Element not found.\n");
	}

	return 0;
}
