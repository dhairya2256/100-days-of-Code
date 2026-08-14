(#include <stdio.h>
#/*
Q9: Write a program to calculate simple and compound interest for given principal, rate, and time.
*/
#include <stdio.h>
#include <math.h>

int main(void)
{
	double P, R, T;
	int n;

	printf("Enter principal (P): ");
	if (scanf("%lf", &P) != 1) {
		fprintf(stderr, "Invalid principal\n");
		return 1;
	}

	printf("Enter annual rate (R) in percent: ");
	if (scanf("%lf", &R) != 1) {
		fprintf(stderr, "Invalid rate\n");
		return 1;
	}

	printf("Enter time (T) in years: ");
	if (scanf("%lf", &T) != 1) {
		fprintf(stderr, "Invalid time\n");
		return 1;
	}

	printf("Enter number of times interest applied per year (n, e.g., 1): ");
	if (scanf("%d", &n) != 1 || n <= 0) {
		fprintf(stderr, "Invalid compounding frequency, using n = 1\n");
		n = 1;
	}

	double simple = (P * R * T) / 100.0;
	double amount = P * pow(1.0 + (R / 100.0) / n, n * T);
	double compound = amount - P;

	printf("\nSimple Interest = %.2f\n", simple);
	printf("Amount after simple interest = %.2f\n", P + simple);
	printf("\nCompound Interest = %.2f\n", compound);
	printf("Amount after compound interest = %.2f\n", amount);

	return 0;
}

