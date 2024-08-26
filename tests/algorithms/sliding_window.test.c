#include <stdio.h>
#include "include/algorithms/sliding_window.h"

int main() {
    int arr[] = {5, 10, 25, 6, 1, 2};
    int size = 6;
    int window_size = 3;

    int* subarr = find_subarray_with_target_sum(arr, size, window_size);

    printf("Sub-array:\n");
    printf("[");
    for(int i = 0; i < window_size; i++) {
        printf("%d", subarr[i]);

        if(i < window_size-1)
            printf(", ");
    }
    printf("]\n");

    free(subarr);
    subarr = NULL;

    return 0;
}