#include <stdio.h>

int main(void) {
	int nums[100];
	long long prefix[100];
	long long suffix[100];
	long long answer[100];
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

	if (n == 0) {
		printf("Array answer: \n");
		return 0;
	}

	prefix[0] = 1;
	for (int i = 1; i < n; i++) {
		prefix[i] = prefix[i - 1] * nums[i - 1];
	}

	suffix[n - 1] = 1;
	for (int i = n - 2; i >= 0; i--) {
		suffix[i] = suffix[i + 1] * nums[i + 1];
	}

	for (int i = 0; i < n; i++) {
		answer[i] = prefix[i] * suffix[i];
	}

	printf("Array answer: ");
	for (int i = 0; i < n; i++) {
		printf("%lld", answer[i]);
		if (i < n - 1) {
			printf(" ");
		}
	}
	printf("\n");

	return 0;
}
