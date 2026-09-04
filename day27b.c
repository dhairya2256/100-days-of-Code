#include <stdio.h>

int main() {
	int row, spaces, stars;

	for (row = 1; row <= 7; row++) {
		if (row <= 4) {
			spaces = 4 - row;
			stars = 2 * row - 1;
		} else {
			spaces = row - 4;
			stars = 2 * (8 - row) - 1;
		}

		for (int column = 1; column <= spaces; column++) {
			printf(" ");
		}

		for (int column = 1; column <= stars; column++) {
			printf("*");
		}

		printf("\n");
	}

	return 0;
}
