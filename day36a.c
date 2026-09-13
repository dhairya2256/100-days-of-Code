#include <stdio.h>

int main(void) {
	int matrix[10][10], rows, columns;

	printf("Enter number of rows: ");
	scanf("%d", &rows);

	printf("Enter number of columns: ");
	scanf("%d", &columns);

	if (rows <= 0 || rows > 10 || columns <= 0 || columns > 10) {
		printf("Invalid matrix dimensions.\n");
		return 1;
	}

	printf("Enter the matrix elements:\n");
	for (int row = 0; row < rows; row++) {
		for (int column = 0; column < columns; column++) {
			scanf("%d", &matrix[row][column]);
		}
	}

	printf("Matrix:\n");
	for (int row = 0; row < rows; row++) {
		for (int column = 0; column < columns; column++) {
			printf("%d ", matrix[row][column]);
		}
		printf("\n");
	}

	return 0;
}
