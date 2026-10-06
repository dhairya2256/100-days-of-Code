#include <stdio.h>

int main(void) {
	int numbers[100];
	int nextGreater[100];
	int stack[100];
	int stackSize = 0;
	int n;

	printf("Enter number of elements: ");
	if (scanf("%d", &n) != 1 || n < 0 || n > 100) {
		printf("Invalid number of elements.\n");
		return 1;
	}

	printf("Enter %d elements:\n", n);
	for (int index = 0; index < n; index++) {
		if (scanf("%d", &numbers[index]) != 1) {
			printf("Invalid array element.\n");
			return 1;
		}
	}

	for (int index = n - 1; index >= 0; index--) {
		while (stackSize > 0 && stack[stackSize - 1] <= numbers[index]) {
			stackSize--;
		}

		nextGreater[index] = stackSize > 0 ? stack[stackSize - 1] : -1;
		stack[stackSize++] = numbers[index];
	}

	printf("Next greater elements: ");
	for (int index = 0; index < n; index++) {
		printf("%d", nextGreater[index]);
		if (index < n - 1) {
			printf(" ");
		}
	}
	printf("\n");

	return 0;
}
