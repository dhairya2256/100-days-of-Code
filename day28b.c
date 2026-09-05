#include <stdio.h>

int main(void) {
	int n;

	scanf("%d", &n);
	int numbers[n];

	for (int index = 0; index < n; index++) {
		scanf("%d", &numbers[index]);
	}

	for (int index = 0; index < n; index++) {
		printf("%d ", numbers[index]);
	}

	return 0;
}
