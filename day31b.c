#include <stdio.h>

int main(void) {
	int numbers[100], n, temporary;

	printf("Enter number of elements: ");
	scanf("%d", &n);

	printf("Enter %d elements:\n", n);
	for (int index = 0; index < n; index++) {
		scanf("%d", &numbers[index]);
	}

	for (int left = 0, right = n - 1; left < right; left++, right--) {
		temporary = numbers[left];
		numbers[left] = numbers[right];
		numbers[right] = temporary;
	}

	printf("Reversed array: ");
	for (int index = 0; index < n; index++) {
		printf("%d ", numbers[index]);
	}
	printf("\n");

	return 0;
}
