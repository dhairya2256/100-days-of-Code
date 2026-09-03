#include <stdio.h>

int main() {
	int row, number;

	for (row = 1; row <= 5; row++) {
		for (number = 1; number <= 5 - row; number++) {
			printf(" ");
		}

		for (number = 6 - row; number <= 5; number++) {
			printf("%d", number);
		}

		printf("\n");
	}

	return 0;
}
