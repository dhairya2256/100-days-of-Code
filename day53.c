#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int count;

	if (scanf("%d", &count) != 1 || count <= 0) {
		printf("-1\n");
		return 0;
	}

	int *values = malloc((size_t)count * sizeof(*values));
	if (values == NULL) {
		return 1;
	}

	long long total = 0;
	for (int i = 0; i < count; i++) {
		if (scanf("%d", &values[i]) != 1) {
			free(values);
			return 1;
		}
		total += values[i];
	}

	long long leftSum = 0;
	int pivotIndex = -1;
	for (int i = 0; i < count; i++) {
		long long rightSum = total - leftSum - values[i];
		if (leftSum == rightSum) {
			pivotIndex = i;
			break;
		}
		leftSum += values[i];
	}

	printf("%d\n", pivotIndex);
	free(values);
	return 0;
}
