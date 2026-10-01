#include <stdio.h>

int main(void)
{
	long long n;
	if (scanf("%lld", &n) != 1 || n <= 0) {
		printf("-1\n");
		return 0;
	}

	__int128 target = (__int128)n * (n + 1) / 2;
	long long low = 1;
	long long high = n;

	while (low <= high) {
		long long middle = low + (high - low) / 2;
		__int128 square = (__int128)middle * middle;

		if (square == target) {
			printf("%lld\n", middle);
			return 0;
		}
		if (square < target) {
			low = middle + 1;
		} else {
			high = middle - 1;
		}
	}

	printf("-1\n");
	return 0;
}
