#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int m;
    int n;
    if (scanf("%d %d", &m, &n) != 2 || m < 0 || n < 0) {
        fprintf(stderr, "Invalid array sizes.\n");
        return 1;
    }

    size_t first_count = (size_t)m;
    size_t second_count = (size_t)n;
    if (first_count > SIZE_MAX - second_count) {
        fprintf(stderr, "Combined array size is too large.\n");
        return 1;
    }

    size_t total_count = first_count + second_count;
    if (total_count > SIZE_MAX / sizeof(int)) {
        fprintf(stderr, "Combined array size is too large.\n");
        return 1;
    }

    int *first = first_count == 0 ? NULL : malloc(first_count * sizeof(*first));
    int *second = second_count == 0 ? NULL : malloc(second_count * sizeof(*second));
    int *merged = total_count == 0 ? NULL : malloc(total_count * sizeof(*merged));
    if ((first_count > 0 && first == NULL) ||
        (second_count > 0 && second == NULL) ||
        (total_count > 0 && merged == NULL)) {
        perror("malloc");
        free(first);
        free(second);
        free(merged);
        return 1;
    }

    for (size_t i = 0; i < first_count; ++i) {
        if (scanf("%d", &first[i]) != 1) {
            fprintf(stderr, "Invalid element in the first array.\n");
            free(first);
            free(second);
            free(merged);
            return 1;
        }
    }

    for (size_t i = 0; i < second_count; ++i) {
        if (scanf("%d", &second[i]) != 1) {
            fprintf(stderr, "Invalid element in the second array.\n");
            free(first);
            free(second);
            free(merged);
            return 1;
        }
    }

    size_t i = 0;
    size_t j = 0;
    size_t k = 0;
    while (i < first_count && j < second_count) {
        if (first[i] <= second[j]) {
            merged[k++] = first[i++];
        } else {
            merged[k++] = second[j++];
        }
    }

    while (i < first_count) {
        merged[k++] = first[i++];
    }
    while (j < second_count) {
        merged[k++] = second[j++];
    }

    for (size_t index = 0; index < total_count; ++index) {
        if (index > 0) {
            putchar(' ');
        }
        printf("%d", merged[index]);
    }
    putchar('\n');

    free(first);
    free(second);
    free(merged);
    return 0;
}