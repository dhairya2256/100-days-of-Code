#include <stdio.h>

int main(void) {
	int numbers[100], n, target, foundIndex = -1;

	printf("Enter number of elements: ");
	scanf("%d", &n);

	printf("Enter %d elements:\n", n);
	for (int index = 0; index < n; index++) {
		scanf("%d", &numbers[index]);
	}

	printf("Enter element to search: ");
	scanf("%d", &target);

	for (int index = 0; index < n; index++) {
		if (numbers[index] == target) {
			foundIndex = index;
			break;
		}
	}

	if (foundIndex != -1) {
		printf("Element found at position %d.\n", foundIndex + 1);
	} else {
		printf("Element not found.\n");
	}

	return 0;
}
