 #include <stdio.h>

int firstOccurrence(int nums[], int size, int target) {
	int left = 0, right = size - 1, result = -1;

	while (left <= right) {
		int middle = left + (right - left) / 2;

		if (nums[middle] == target) {
			result = middle;
			right = middle - 1;
		} else if (nums[middle] < target) {
			left = middle + 1;
		} else {
			right = middle - 1;
		}
	}

	return result;
}

int lastOccurrence(int nums[], int size, int target) {
	int left = 0, right = size - 1, result = -1;

	while (left <= right) {
		int middle = left + (right - left) / 2;

		if (nums[middle] == target) {
			result = middle;
			left = middle + 1;
		} else if (nums[middle] < target) {
			left = middle + 1;
		} else {
			right = middle - 1;
		}
	}

	return result;
}

int main() {
	int nums[100], size, target;
	int first, last;

	printf("Enter the size of the sorted array: ");
	scanf("%d", &size);

	printf("Enter the sorted array: ");
	for (int i = 0; i < size; i++) {
		scanf("%d", &nums[i]);
	}

	printf("Enter the target: ");
	scanf("%d", &target);

	first = firstOccurrence(nums, size, target);
	last = lastOccurrence(nums, size, target);

	printf("First occurrence: %d\n", first);
	printf("Last occurrence: %d\n", last);
	printf("Indices: %d, %d\n", first, last);

	return 0;
}
