#include <stdio.h>
#include "include/hash_table.h"
#include "include/hash.h"
#include "include/person.h"

void print_person_hash_table(HashTable* ht);

int main()
{
    HashTable* ht = hash_table_create(10, &simple_hash);
    Person* p1 = person_create("John", 22, 'M', 1.7);
    Person* p2 = person_create("Doe", 20, 'F', 1.65);
    Person* p3 = person_create("Marie", 22, 'M', 1.7);
    
    hash_table_insert(ht, "john", p1);
    hash_table_insert(ht, "doe", p2);
    hash_table_insert(ht, "marie", p3);
    
    print_person_hash_table(ht);

    hash_table_destroy(&ht);

    return 0;
}

void print_person_hash_table(HashTable* ht) {
    if(ht == NULL) return;

    for(int i = 0; i < ht->size; i++) {
        printf("Index [%d]\n", i);

        if(ht->pairs[i] = NULL) {
            printf("NULL\n");
            continue;
        }

        printf("Key: %s\n", ht->pairs[i]->key);
        printf("\n");
    }
}