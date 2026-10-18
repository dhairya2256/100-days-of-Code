#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int count;
    if (scanf("%d", &count) != 1 || count <= 0) {
        printf("-1 -1\n");
        return 0;
    }

    if ((size_t)count > SIZE_MAX / sizeof(int)) {
        fprintf(stderr, "Array is too large.\n");
        return 1;
    }

    int *nums = malloc((size_t)count * sizeof(*nums));
    if (nums == NULL) {
        perror("malloc");
        return 1;
    }

    for (int i = 0; i < count; ++i) {
        if (scanf("%d", &nums[i]) != 1) {
            fprintf(stderr, "Invalid array element.\n");
            free(nums);
            return 1;
        }
    }

    int target;
    if (scanf("%d", &target) != 1) {
        fprintf(stderr, "Invalid target.\n");
        free(nums);
        return 1;
    }

    for (int i = 0; i < count; ++i) {
        for (int j = i + 1; j < count; ++j) {
            if ((long long)nums[i] + nums[j] == target) {
                printf("%d %d\n", i, j);
                free(nums);
                return 0;
            }
        }
    }

    printf("-1 -1\n");
    free(nums);
    return 0;
}