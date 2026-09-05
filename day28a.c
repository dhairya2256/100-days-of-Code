#include <stdio.h>

int main(void) {
	int n, number, divisor, isPrime;

	scanf("%d", &n);

	for (number = 2; number <= n; number++) {
		isPrime = 1;

		for (divisor = 2; divisor < number; divisor++) {
			if (number % divisor == 0) {
				isPrime = 0;
				break;
			}
		}

		if (isPrime) {
			printf("%d ", number);
		}
	}
		printf("\n");

	return 0;
}
