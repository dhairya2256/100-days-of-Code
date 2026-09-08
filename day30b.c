#include <stdio.h>

int main(void) {
	int numbers[100], n;
	int positiveCount = 0, negativeCount = 0, zeroCount = 0;

	printf("Enter number of elements: ");
	scanf("%d", &n);

	printf("Enter %d elements:\n", n);
	for (int index = 0; index < n; index++) {
		scanf("%d", &numbers[index]);

		if (numbers[index] > 0) {
			positiveCount++;
		} else if (numbers[index] < 0) {
			negativeCount++;
		} else {
			zeroCount++;
		}
	}

	printf("Positive numbers: %d\n", positiveCount);
	printf("Negative numbers: %d\n", negativeCount);
	printf("Zeroes: %d\n", zeroCount);

	return 0;
}
