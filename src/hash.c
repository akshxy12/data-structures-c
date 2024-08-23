#include "../include/hash.h"

/**
 *  Adds the ascii values of all characters in the string, multiplying each with their position in the string
 *  @param  key     Key
 *  @return hash    Hash value corresponding to the key
 */
int simple_hash(char* key, int hash_size) {
    int hash = 0;

    for(int i = 1; key[i] != '\0'; i++)
    {
        hash += key[i]*i;
    }

    hash %= hash_size;

    return hash;
}