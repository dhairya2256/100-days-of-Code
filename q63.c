#include <stdio.h>

int main(void) {
	int arr[100];
	int n;
	int k;

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

	if (scanf("%d", &k) != 1 || k < 1 || k > n) {
		fprintf(stderr, "Invalid value of k.\n");
		return 1;
	}

	for (int i = 1; i < n; i++) {
		int value = arr[i];
		int j = i - 1;

		while (j >= 0 && arr[j] > value) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = value;
	}

	printf("%d\n", arr[k - 1]);
	return 0;
}