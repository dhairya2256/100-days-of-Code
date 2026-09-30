#include <stdio.h>

int main() {
	int arr[100];
	int size, x;
	int left, right, result = -1;

	printf("Enter the size of the sorted array: ");
	if (scanf("%d", &size) != 1 || size < 0 || size > 100) {
		printf("Invalid array size.\n");
		return 1;
	}

	printf("Enter the sorted array: ");
	for (int i = 0; i < size; i++) {
		if (scanf("%d", &arr[i]) != 1) {
			printf("Invalid array element.\n");
			return 1;
		}
	}

	printf("Enter x: ");
	if (scanf("%d", &x) != 1) {
		printf("Invalid value for x.\n");
		return 1;
	}

	left = 0;
	right = size - 1;

	while (left <= right) {
		int middle = left + (right - left) / 2;

		if (arr[middle] >= x) {
			result = middle;
			right = middle - 1;
		} else {
			left = middle + 1;
		}
	}

	printf("Ceil index: %d\n", result);
	return 0;
}
