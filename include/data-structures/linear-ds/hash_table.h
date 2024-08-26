#ifndef HASH_TABLE_C
#define HASH_TABLE_C

#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../../string_extra.h"

#define KEY_MAX_LEN 20

/* ----------------------------- Data Structures ---------------------------- */

/**
 *  Hash Table node structure
 *  @var    key             Key
 *  @var    data            Data stored by the node
 *  @var    next            Pointer to the next node
 */
typedef struct _hash_table_node {
    char key[KEY_MAX_LEN];
    void* data;
    struct _hash_table_node *next;
} HashTableNode;

/**
 *  Hash Table structure
 *  @var    pairs           Array of key-value pairs
 *  @var    hash_function   Pointer to a hash function
 *  @var    size            Total no. of indexes in the table
 */
typedef struct _hash_table {
    HashTableNode **pairs;
    int (*hash_function) (char* key, int hash_table_size);
    int size;
} HashTable;

/* ------------------------ Hash Table Node Functions ----------------------- */

/**
 *  Creates a hash table node object
 *  @param  key         Key
 *  @param  data        Data associated with the key 
 *  @return new_node    Newly created hash table node
 */
HashTableNode* hash_table_node_create(char* key, void* data);

/**
 *  Destroys a newly created hash table node
 *  @param  hash_table_node_ptr     Pointer to a hash table node
 *  @return data_of_deleted_node    Data stored by the deleted node
 */
void* hash_table_node_destroy(HashTableNode** hash_table_node_ptr);

/* -------------------------- Hash Table Functions -------------------------- */

/**
 *  Creates a hash table object
 *  @param  size            Maximum no. of indices in the table
 *  @param  hash_function   Hash function used by the hash table
 *  @return hash_table      Newly created hash table
 */
HashTable* hash_table_create(int size, int (*hash_function) (char* key, int hash_table_size));

/**
 *  Insert a key-value pair to the table
 *  @param  hash_table      Hash table object
 *  @param  key             Key
 *  @param  value           Data associated with the key
 *  @return (status: bool)  True, if key-value pair is successfully added, else False
 */
bool hash_table_insert(HashTable* hash_table, char* key, void* data);

/**
 *  Delete a key-value pair from the table
 *  @param  hash_table              Hash table object
 *  @param  key                     Key used to identify the node to be removed
 *  @return data_of_deleted_node    Data stored by the deleted node
 */
void* hash_table_delete(HashTable* hash_table, char* key);

/**
 *  Search for a key-value pair in the table
 *  @param  hash_table                  Hash table object
 *  @param  key                         Key used to identify the node to be retrieved
 *  @return data_of_searched_node       Data stored by the searched node
 */
void* hash_table_search(HashTable* hash_table, char* key);

/**
 *  Destroy a hash table object
 *  @param  hash_table_ptr  Pointer to the hash table
 */
void hash_table_destroy(HashTable** hash_table_ptr);

#endif
