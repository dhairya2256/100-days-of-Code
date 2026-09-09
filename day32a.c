#include <stdio.h>

int main(void) {
	int first[100], second[100], merged[200];
	int firstSize, secondSize;

	printf("Enter number of elements in the first array: ");
	scanf("%d", &firstSize);

	printf("Enter %d elements:\n", firstSize);
	for (int index = 0; index < firstSize; index++) {
		scanf("%d", &first[index]);
		merged[index] = first[index];
	}

	printf("Enter number of elements in the second array: ");
	scanf("%d", &secondSize);

	printf("Enter %d elements:\n", secondSize);
	for (int index = 0; index < secondSize; index++) {
		scanf("%d", &second[index]);
		merged[firstSize + index] = second[index];
	}

	printf("Merged array: ");
	for (int index = 0; index < firstSize + secondSize; index++) {
		printf("%d ", merged[index]);
	}
	printf("\n");

	return 0;
}
