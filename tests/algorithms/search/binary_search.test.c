#include <stdio.h>
#include "include/algorithms/sort/bubble_sort.h"
#include "include/algorithms/search/binary_search.h"

int main() {
    int arr[] = {2, 6, 5, 10, 82, 25, 34};
    int size = 7;
    int searchFor = 82;

    bubble_sort_ascending(arr, size);
    
    int index = binary_search(arr, size, searchFor);

    printf("Element %d found at index: %d\n", searchFor, index);
    printf("arr[%d] = %d\n", index, arr[index]);

    return 0;
}