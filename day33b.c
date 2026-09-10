#include <stdio.h>

int main(void) {
	int numbers[100], n, element;

	printf("Enter number of elements: ");
	scanf("%d", &n);

	printf("Enter %d sorted elements:\n", n);
	for (int index = 0; index < n; index++) {
		scanf("%d", &numbers[index]);
	}

	printf("Enter element to insert: ");
	scanf("%d", &element);

	int index = n - 1;
	while (index >= 0 && numbers[index] > element) {
		numbers[index + 1] = numbers[index];
		index--;
	}
	numbers[index + 1] = element;

	printf("Array after insertion: ");
	for (int position = 0; position <= n; position++) {
		printf("%d ", numbers[position]);
	}
	printf("\n");

	return 0;
}
