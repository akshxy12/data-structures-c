#include <stdio.h>
#include "include/data-structures/linear-ds/two_pointers.h"
#include "include/algorithms/sort/bubble_sort.h"

int main() {
    int arr[] = {2, 5, 3, 10, 66};
    int size = 5;
    int target = 7;

    if(sum_equal_to_target(arr, size, target)) {
        printf("Sum is equal to target(%d)\n", target);
    } else {
        printf("Sum is not equal to target(%d)\n", target);
    }

    return 0;
}