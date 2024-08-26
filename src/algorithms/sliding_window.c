#include "../../include/algorithms/sliding_window.h"

int* find_subarray_with_target_sum(int* arr, int size, int subarr_size) {
    int *window_start = arr;
    int *window_end = arr+subarr_size-1;
    int max_sum = 0;
    int cur_sum = 0;
    int *max_subarr = (int*) malloc(sizeof(int)*subarr_size);
    int i = 0,
        j = 0;

    int* cur = window_start;
    //  Calculate sum of all elements in the first iteration
    for(int i = 0; cur != window_end+1; i++) {
        cur_sum += *cur;
        max_subarr[i] = *cur;

        cur++;
    }

    window_start++;
    window_end++;
    max_sum = cur_sum;

    for(; window_end != &arr[size]; i++, window_start++, window_end++) {
        cur_sum -= *(window_start-1);
        cur_sum += *window_end;

        if(cur_sum > max_sum) {
            max_sum = cur_sum;

            cur = window_start;
            for(j = 0; cur != window_end+1; j++, cur++)
                max_subarr[j] = *cur;
        }
    }

    return max_subarr;
}