#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <stddef.h>
#define BINARY_SEARCH_ERROR -1
#define BINARY_SEARCH_NOT_FOUND -2

int binary_search(int* arr, unsigned int arrSize, int searchFor);

#endif