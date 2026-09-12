#include <stdio.h>

int main(void) {
	int numbers[100], n;
	int largest, secondLargest;
	int hasSecondLargest = 0;

	printf("Enter number of elements: ");
	scanf("%d", &n);

	if (n <= 0 || n > 100) {
		printf("Invalid number of elements.\n");
		return 1;
	}

	printf("Enter %d elements:\n", n);
	for (int index = 0; index < n; index++) {
		scanf("%d", &numbers[index]);
	}

	largest = numbers[0];
	for (int index = 1; index < n; index++) {
		if (numbers[index] > largest) {
			secondLargest = largest;
			largest = numbers[index];
			hasSecondLargest = 1;
		} else if (numbers[index] < largest &&
				   (!hasSecondLargest || numbers[index] > secondLargest)) {
			secondLargest = numbers[index];
			hasSecondLargest = 1;
		}
	}

	if (!hasSecondLargest) {
		printf("There is no second largest element.\n");
	} else {
		printf("Second largest element: %d\n", secondLargest);
	}

	return 0;
}
