#include <stdio.h>

int main(void) {
	int nums[100];
	int candidate = 0;
	int count = 0;
	int n;

	printf("Enter number of elements: ");
	if (scanf("%d", &n) != 1 || n < 0 || n > 100) {
		printf("Invalid number of elements.\n");
		return 1;
	}

	printf("Enter %d elements:\n", n);
	for (int i = 0; i < n; i++) {
		if (scanf("%d", &nums[i]) != 1) {
			printf("Invalid array element.\n");
			return 1;
		}
	}

	for (int i = 0; i < n; i++) {
		if (count == 0) {
			candidate = nums[i];
			count = 1;
		} else if (nums[i] == candidate) {
			count++;
		} else {
			count--;
		}
	}

	int frequency = 0;
	for (int i = 0; i < n; i++) {
		if (nums[i] == candidate) {
			frequency++;
		}
	}

	if (frequency > n / 2) {
		printf("%d\n", candidate);
	} else {
		printf("-1\n");
	}

	return 0;
}
