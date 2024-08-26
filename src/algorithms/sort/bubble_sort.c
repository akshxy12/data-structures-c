#include "../../../include/algorithms/sort/bubble_sort.h"

void bubble_sort_ascending(int* arr, int size) {
    int tmp = 0;
    
    for(int i = 0; i < size-1; i++) {
        for(int j = 0; j < size-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}