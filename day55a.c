#include <stdio.h>

int main(void) {
	int numbers[100];
	int n;
	int candidate = 0;
	int count = 0;

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

		if (count == 0) {
			candidate = numbers[index];
			count = 1;
		} else if (numbers[index] == candidate) {
			count++;
		} else {
			count--;
		}
	}

	count = 0;
	for (int index = 0; index < n; index++) {
		if (numbers[index] == candidate) {
			count++;
		}
	}

	if (count > n / 2) {
		printf("Majority element: %d\n", candidate);
	} else {
		printf("-1\n");
	}

	return 0;
}
