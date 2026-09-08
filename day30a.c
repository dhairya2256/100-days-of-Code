#include <stdio.h>

int main(void) {
	int numbers[100], n, evenCount = 0, oddCount = 0;

	printf("Enter number of elements: ");
	scanf("%d", &n);

	printf("Enter %d elements:\n", n);
	for (int index = 0; index < n; index++) {
		scanf("%d", &numbers[index]);

		if (numbers[index] % 2 == 0) {
			evenCount++;
		} else {
			oddCount++;
		}
	}

	printf("Even numbers: %d\n", evenCount);
	printf("Odd numbers: %d\n", oddCount);

	return 0;
}
