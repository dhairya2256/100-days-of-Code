#include <stdio.h>

int main(void) {
	int arr[100];
	int n;
	int k;
	int windowSum = 0;
	int maximumSum;

	printf("Enter number of elements: ");
	if (scanf("%d", &n) != 1 || n < 0 || n > 100) {
		printf("Invalid number of elements.\n");
		return 1;
	}

	printf("Enter %d elements:\n", n);
	for (int i = 0; i < n; i++) {
		if (scanf("%d", &arr[i]) != 1) {
			printf("Invalid array element.\n");
			return 1;
		}
	}

	printf("Enter k: ");
	if (scanf("%d", &k) != 1 || k <= 0 || k > n) {
		printf("Invalid value of k.\n");
		return 1;
	}

	for (int i = 0; i < k; i++) {
		windowSum += arr[i];
	}
	maximumSum = windowSum;

	for (int i = k; i < n; i++) {
		windowSum += arr[i] - arr[i - k];
		if (windowSum > maximumSum) {
			maximumSum = windowSum;
		}
	}

	printf("Maximum sum: %d\n", maximumSum);
	return 0;
}
