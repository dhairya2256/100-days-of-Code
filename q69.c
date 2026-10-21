#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

static size_t hash_int(int value)
{
    uint32_t hash = (uint32_t)value;
    hash ^= hash >> 16;
    hash *= UINT32_C(0x7feb352d);
    hash ^= hash >> 15;
    hash *= UINT32_C(0x846ca68b);
    hash ^= hash >> 16;
    return (size_t)hash;
}

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Invalid array size.\n");
        return 1;
    }

    size_t count = (size_t)n;
    if (count > SIZE_MAX / 2) {
        fprintf(stderr, "Array is too large.\n");
        return 1;
    }

    size_t capacity = 1;
    size_t minimum_capacity = count * 2;
    while (capacity < minimum_capacity) {
        if (capacity > SIZE_MAX / 2) {
            fprintf(stderr, "Array is too large.\n");
            return 1;
        }
        capacity *= 2;
    }

    if (capacity > SIZE_MAX / sizeof(int)) {
        fprintf(stderr, "Array is too large.\n");
        return 1;
    }

    int *values = malloc(capacity * sizeof(*values));
    unsigned char *occupied = calloc(capacity, sizeof(*occupied));
    if (values == NULL || occupied == NULL) {
        perror("memory allocation");
        free(values);
        free(occupied);
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        int value;
        if (scanf("%d", &value) != 1) {
            fprintf(stderr, "Invalid array element.\n");
            free(values);
            free(occupied);
            return 1;
        }

        size_t index = hash_int(value) & (capacity - 1);
        while (occupied[index] && values[index] != value) {
            index = (index + 1) & (capacity - 1);
        }

        if (occupied[index]) {
            printf("%d\n", value);
            free(values);
            free(occupied);
            return 0;
        }

        values[index] = value;
        occupied[index] = 1;
    }

    fprintf(stderr, "No repeated element found.\n");
    free(values);
    free(occupied);
    return 1;
}