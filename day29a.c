#include <stdio.h>

int main(void) {
	int numbers[100], n, sum = 0;

	printf("Enter number of elements: ");
	scanf("%d", &n);

	printf("Enter %d elements:\n", n);
	for (int index = 0; index < n; index++) {
		scanf("%d", &numbers[index]);
		sum += numbers[index];
	}

	printf("Sum of array elements: %d\n", sum);

	return 0;
}
