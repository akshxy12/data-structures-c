#include <stdio.h>
#include "include/data-structures/two_pointers.h"

int main() {
    int arr[] = {2, 5, 3, 10, 66};
    int size = 5;
    int target = 8;

    int tmp = 0;
    for(int i = 0; i < size-1; i++) {
        for(int j = i+1; j < size; j++) {
            if(arr[i] > arr[j]) {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }

    if(sum_equal_to_target(arr, size, 8)) {
        printf("Sum is equal to target\n");
    } else {
        printf("Sum is not equal to target\n");
    }

    return 0;
}