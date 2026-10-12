#include <stdio.h>

int main(void) {
	int numbers[100];
	int deque[100];
	int n;
	int k;
	int front = 0;
	int back = 0;

	if (scanf("%d", &n) != 1 || n < 1 || n > 100) {
		fprintf(stderr, "Invalid number of elements.\n");
		return 1;
	}

	for (int index = 0; index < n; index++) {
		if (scanf("%d", &numbers[index]) != 1) {
			fprintf(stderr, "Invalid array element.\n");
			return 1;
		}
	}

	if (scanf("%d", &k) != 1 || k < 1 || k > n) {
		fprintf(stderr, "Invalid window size.\n");
		return 1;
	}

	for (int index = 0; index < n; index++) {
		while (front < back && deque[front] <= index - k) {
			front++;
		}

		while (front < back && numbers[deque[back - 1]] <= numbers[index]) {
			back--;
		}

		deque[back++] = index;

		if (index >= k - 1) {
			if (index > k - 1) {
				printf(" ");
			}
			printf("%d", numbers[deque[front]]);
		}
	}

	printf("\n");
	return 0;
}
