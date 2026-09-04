#include <stdio.h>

int main() {
	int row, stars;

	for (row = 1; row <= 9; row++) {
		if (row <= 5) {
			stars = 2 * row - 1;
		} else {
			stars = 2 * (10 - row) - 1;
		}

		for (int column = 1; column <= stars; column++) {
			printf("*");
		}

		printf("\n");
	}

	return 0;
}
