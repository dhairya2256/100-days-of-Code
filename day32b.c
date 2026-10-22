#include <stdio.h>

int main(void) {
	long long number;
	int digitCount[10] = {0};
	int mostFrequentDigit = 0;

	printf("Enter an integer: ");
	scanf("%lld", &number);

	if (number < 0) {
		number = -number;
	}

	if (number == 0) {
		digitCount[0] = 1;
	} else {
		while (number > 0) {
			digitCount[number % 10]++;
			number /= 10;
		}
	}

	for (int digit = 1; digit < 10; digit++) {
		if (digitCount[digit] > digitCount[mostFrequentDigit]) {
			mostFrequentDigit = digit;
		}
	}

	printf("Most frequent digit: %d\n", mostFrequentDigit);

	return 0;
}
