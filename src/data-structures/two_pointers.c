#include "../../include/data-structures/two_pointers.h"

bool sum_equal_to_target(int* arr, int size, int target) {
    if(arr == NULL || size < 0) return false;

    int* start = arr;
    int* end = arr + size-1;
    int sum = 0;

    while(start != end) {
        sum = *start + *end;

        printf("%d + %d = %d\n", *start, *end, sum);

        if(sum == target)
            return true;
        else if(sum > target) {
            end--;
        } else {
            start++;
        }
    }

    return false;
}