#include <stdio.h>

int main(void) {
	int arr[100];
	int n;
	long long currentSum;
	long long maximumSum;

	if (scanf("%d", &n) != 1 || n < 1 || n > 100) {
		fprintf(stderr, "Invalid number of elements.\n");
		return 1;
	}

	for (int i = 0; i < n; i++) {
		if (scanf("%d", &arr[i]) != 1) {
			fprintf(stderr, "Invalid array element.\n");
			return 1;
		}
	}

	currentSum = arr[0];
	maximumSum = arr[0];

	for (int i = 1; i < n; i++) {
		if (currentSum < 0) {
			currentSum = arr[i];
		} else {
			currentSum += arr[i];
		}

		if (currentSum > maximumSum) {
			maximumSum = currentSum;
		}
	}

	printf("%lld\n", maximumSum);
	return 0;
}