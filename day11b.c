// Q22 (Conditional Statements): Write a program to find profit or loss percentage given cost price and selling price.

#include <stdio.h>

int main(void) {
	double costPrice, sellingPrice, percentage;

	printf("Enter the cost price: ");
	if (scanf("%lf", &costPrice) != 1) {
		printf("Invalid input.\n");
		return 1;
	}

	printf("Enter the selling price: ");
	if (scanf("%lf", &sellingPrice) != 1) {
		printf("Invalid input.\n");
		return 1;
	}

	if (costPrice <= 0) {
		printf("Cost price must be greater than zero.\n");
	}
	else if (sellingPrice > costPrice) {
		percentage = ((sellingPrice - costPrice) / costPrice) * 100;
		printf("Profit: %.2f%%\n", percentage);
	}
	else if (sellingPrice < costPrice) {
		percentage = ((costPrice - sellingPrice) / costPrice) * 100;
		printf("Loss: %.2f%%\n", percentage);
	}
	else {
		printf("No profit, no loss.\n");
	}

	return 0;
}
