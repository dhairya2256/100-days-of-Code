
#include <stdio.h>

int main(void)
{
	long long n;
	printf("Enter n: ");
	if (scanf("%lld", &n) != 1) {
		fprintf(stderr, "Invalid input\n");
		return 1;
	}

	if (n <= 0) {
		printf("Sum of first %lld natural numbers = 0\n", n);
		return 0;
	}

	long long sum = n * (n + 1) / 2;
	printf("Sum of first %lld natural numbers = %lld\n", n, sum);

	return 0;
}

