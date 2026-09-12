#include <stdio.h>

int main(void) {
	int numbers[100], rotated[100], n, k;

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

	printf("Enter number of positions to rotate: ");
	scanf("%d", &k);

	if (k < 0) {
		printf("Invalid number of positions.\n");
		return 1;
	}

	k %= n;
	for (int index = 0; index < n; index++) {
		rotated[(index + k) % n] = numbers[index];
	}

	printf("Array after right rotation: ");
	for (int index = 0; index < n; index++) {
		printf("%d ", rotated[index]);
	}
	printf("\n");

	return 0;
}
