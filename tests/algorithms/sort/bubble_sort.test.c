#include <stdio.h>
#include "include/algorithms/sort/bubble_sort.h"

void print_array(int* arr, int size);

int main() {
    int arr[] = {2, 6, 5, 10, 82, 25, 34};
    int size = 7;
    int searchFor = 82;

    bubble_sort_ascending(arr, size);
    print_array(arr, size);

    return 0;
}

void print_array(int* arr, int size) {
    if(arr == NULL) return;

    printf("Array START----------------\n");
    for(int i = 0; i < size; i++) {
        printf("[%d] %d\n", i, arr[i]);
    }
    printf("Array END------------------\n");
}