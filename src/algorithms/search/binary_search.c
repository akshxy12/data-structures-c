#include "../../../include/algorithms/search/binary_search.h"

int binary_search(int* arr, unsigned int arrSize, int searchFor) {
    int startIndex = 0,
        endIndex = arrSize-1,
        middleIndex = 0;
    
    while(startIndex <= endIndex) {
        middleIndex = (int)(startIndex + endIndex)/2;

        if(arr[middleIndex] == searchFor)
            return middleIndex;
        else if(arr[middleIndex] < searchFor) {
            startIndex = middleIndex+1;
        } else {
            endIndex = middleIndex-1;
        }
    }

    return BINARY_SEARCH_NOT_FOUND;
}