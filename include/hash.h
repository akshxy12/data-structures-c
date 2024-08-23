#ifndef HASH_H
#define HASH_H

/**
 *  Adds the ascii values of all characters in the string, multiplying each with their position in the string
 *  @param  key         Key
 *  @param  hash_size   Highest value the hash can take
 *  @return hash        Hash value corresponding to the key
 */
int simple_hash(char* key, int hash_size);

#endif