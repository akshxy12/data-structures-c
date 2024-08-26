#include <stdio.h>
#include "include/hash_table.h"
#include "include/hash.h"
#include "include/person.h"

void print_person_hash_table(HashTable *ht);

int main()
{
    HashTable *ht = hash_table_create(10, &simple_hash);
    Person *p1 = person_create("John", 22, 'M', 1.7);
    Person *p2 = person_create("Doe", 20, 'F', 1.65);
    Person *p3 = person_create("Marie", 22, 'F', 1.7);
    Person *p4 = person_create("James", 22, 'M', 1.9);
    Person *p5 = person_create("Amy", 26, 'F', 1.5);
    Person *p6 = person_create("Snow", 22, 'F', 1.8);

    hash_table_insert(ht, "john", p1);
    hash_table_insert(ht, "doe", p2);
    hash_table_insert(ht, "marie", p3);
    hash_table_insert(ht, "james", p4);
    hash_table_insert(ht, "amy", p5);
    hash_table_insert(ht, "snow", p6);

    Person *person_deleted = hash_table_delete(ht, "doe");
    printf("[Person Removed]\n");
    person_print(person_deleted);
    printf("\n");

    print_person_hash_table(ht);

    hash_table_destroy(&ht);
    person_destroy(&person_deleted);

    return 0;
}

void print_person_hash_table(HashTable *ht)
{
    if (ht == NULL)
        return;

    printf("Hash Table Start-------------------->\n");
    for (int i = 0; i < ht->size; i++)
    {
        printf("Index [%d]: ", i);

        if (ht->pairs[i] == NULL)
        {
            printf("NULL\n");
        }
        else
        {
            printf("\n");

            HashTableNode *cur = ht->pairs[i];

            for (int j = 1; cur != NULL; j++)
            {
                printf("\tPerson [%d]\n", j);
                printf("Key: %s\n", cur->key);
                person_print(cur->data);

                cur = cur->next;
            }
        }

        if (i < ht->size - 1)
            printf("\n-------\n");
    }
    printf("Hash Table End---------------------->\n");
}