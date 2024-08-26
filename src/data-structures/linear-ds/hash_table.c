#include "../../../include/data-structures/linear-ds/hash_table.h"

#include <stdio.h>
#include "../../../include/person.h"

HashTableNode *hash_table_node_create(char *key, void *data)
{
    HashTableNode *new_node = (HashTableNode *)malloc(sizeof(HashTableNode));

    if (new_node == NULL)
        return NULL;

    strcpy(new_node->key, key);
    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

void* hash_table_node_destroy(HashTableNode **hash_table_node_ptr)
{
    if (*hash_table_node_ptr == NULL)
        return NULL;

    void* data_of_deleted_node = (*hash_table_node_ptr)->data;

    (*hash_table_node_ptr)->data = NULL;
    (*hash_table_node_ptr)->next = NULL;

    free(*hash_table_node_ptr);
    *hash_table_node_ptr = NULL;

    return data_of_deleted_node;
}

HashTable *hash_table_create(int size, int (*hash_function)(char *key, int hash_table_size))
{
    HashTable *hash_table = (HashTable *)malloc(sizeof(HashTable));

    if (hash_table == NULL)
        return NULL;

    hash_table->size = size;
    hash_table->pairs = (HashTableNode **) malloc(size * sizeof(HashTableNode *));

    for(int i = 0; i < size; i++)
    {
        hash_table->pairs[i] = NULL;
    }

    hash_table->hash_function = hash_function;

    return hash_table;
}

bool hash_table_insert(HashTable *hash_table, char *key, void *data)
{
    if (hash_table == NULL || key == NULL || data == NULL)
        return false;

    HashTableNode *new_node = hash_table_node_create(key, data);

    if (new_node == NULL)
        return false;

    int index = hash_table->hash_function(key, hash_table->size);

    new_node->next = hash_table->pairs[index];
    hash_table->pairs[index] = new_node;

    return true;
}

void *hash_table_delete(HashTable *hash_table, char *key)
{
    if (hash_table == NULL || key == NULL)
        return NULL;

    int index = hash_table->hash_function(key, hash_table->size);
    void *data_of_deleted_node = NULL;

    if (hash_table->pairs[index] == NULL)
        return false;

    HashTableNode *to_delete = hash_table->pairs[index],
                  *prev = NULL;

    while (strcmp_case_insensitive(to_delete->key, key) != 0 && to_delete != NULL)
    {
        prev = to_delete;
        to_delete = to_delete->next;
    }

    if (prev == NULL)
    {
        hash_table->pairs[index] = to_delete->next;
    }
    else
    {
        prev->next = to_delete->next;
    }

    data_of_deleted_node = hash_table_node_destroy(&to_delete);
    return data_of_deleted_node;
}

void *hash_table_search(HashTable *hash_table, char *key)
{
    if (hash_table == NULL || key == NULL)
        return NULL;

    int index = hash_table->hash_function(key, hash_table->size);
    void *data_of_searched_node = NULL;

    if (hash_table->pairs[index] == NULL)
        return false;

    HashTableNode *cur = hash_table->pairs[index];

    while (strcmp_case_insensitive(cur->key, key) != 0 && cur != NULL)
    {
        cur = cur->next;
    }

    if(cur == NULL) return NULL;

    data_of_searched_node = cur->data;

    return data_of_searched_node;
}

void hash_table_destroy(HashTable **hash_table_ptr) {
    if(*hash_table_ptr == NULL) return;

    for(int i = 0; i < (*hash_table_ptr)->size; i++) {
        if((*hash_table_ptr)->pairs[i] == NULL)
            continue;
        
        HashTableNode   *cur = (*hash_table_ptr)->pairs[i],
                        *node_to_be_deleted = NULL;
        void* data_to_be_deleted = NULL;

        while(cur != NULL) {
            node_to_be_deleted = cur;
            cur = cur->next;

            data_to_be_deleted = hash_table_node_destroy(&node_to_be_deleted);
            free(data_to_be_deleted);
            data_to_be_deleted = NULL;
        }
    }

    (*hash_table_ptr)->hash_function = NULL;

    free((*hash_table_ptr)->pairs);
    (*hash_table_ptr)->pairs = NULL;

    free(*hash_table_ptr);
    *hash_table_ptr = NULL;
}