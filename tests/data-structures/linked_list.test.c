#include <stdio.h>

#include "include/data-structures/linked_list.h"
#include "include/person.h"
#include "include/string_extra.h"

void print_person_linked_list(LinkedList* ll);

int main() {
    LinkedList* ll = linked_list_create();
    Person* p1 = person_create("John", 22, 'M', 1.7);
    Person* p2 = person_create("Doe", 20, 'F', 1.65);
    Person* p3 = person_create("Marie", 22, 'M', 1.7);
    linked_list_add_beginning(ll, p1);
    linked_list_add_end(ll, p3);
    linked_list_add_middle(ll, p2, 2);

    linked_list_sort_ascending(ll);

    print_person_linked_list(ll);
    printf("\n");

    //  ! Code for testing delete from the end
    // Person* removed_person = linked_list_delete_end(ll);
    // printf("[Person Removed]\n");
    // person_print(removed_person);
    // printf("\n");
    // person_destroy(&removed_person);

    //  ! Code for testing delete from the middle -- Comment "delete from the end" to make this work
    Person* removed_person_middle = linked_list_delete_middle(ll, 2);
    printf("[Person Removed]\n");
    person_print(removed_person_middle);
    printf("\n");
    person_destroy(&removed_person_middle);

    char person_to_find[] = "doe";
    Person* person_found = linked_list_search(ll, (void*)person_to_find);
    if(person_found == NULL) {
        printf("Person %s not found\n", person_to_find);
    } else {
        printf("[Person Found]\n");
        person_print(person_found);
        printf("\n");
    }

    print_person_linked_list(ll);

    linked_list_destroy(&ll);
    
    return 0;
}

void* linked_list_search(LinkedList* linked_list, void* name) {
    if(linked_list == NULL || linked_list_is_empty(linked_list)) return NULL;

    LinkedListNode* cur = linked_list->head;
    Person* cur_person = NULL;

    while(cur != NULL) {
        cur_person = cur->data;

        if(strcmp_case_insensitive(cur_person->name, (char*)name) == 0) return cur_person;

        cur = cur->next;
    }

    return NULL;
}

void linked_list_sort_ascending(LinkedList* linked_list) {
    if(linked_list == NULL || linked_list_is_empty(linked_list)) return;

    LinkedListNode  *start = linked_list->head,
                    *end_unsorted = NULL,
                    *cur = NULL;
    
    Person  *cur_person = NULL,
            *next_person = NULL;
    
    for(int i = 0; i < linked_list->size; i++) {
        cur = start;
        Person* tmp = cur->data;

        while(cur->next != end_unsorted) {
            cur_person = cur->data;
            next_person = cur->next->data;

            if(strcmp_case_insensitive(cur_person->name, next_person->name) > 0) {
                void* next_data = cur->next->data;
                cur->next->data = cur->data;
                cur->data = next_data;
            }

            if(cur == start && end_unsorted == cur->next) break;

            cur = cur->next;
        }

        end_unsorted = cur;
    }
}

void linked_list_sort_descending(LinkedList* linked_list) {
    if(linked_list == NULL || linked_list_is_empty(linked_list)) return;

    LinkedListNode  *start = linked_list->head,
                    *end_unsorted = NULL,
                    *cur = NULL;
    
    Person  *cur_person = NULL,
            *next_person = NULL;
    
    for(int i = 0; i < linked_list->size; i++) {
        cur = start;
        Person* tmp = cur->data;

        while(cur->next != end_unsorted) {
            cur_person = cur->data;
            next_person = cur->next->data;

            if(strcmp_case_insensitive(cur_person->name, next_person->name) < 0) {
                void* next_data = cur->next->data;
                cur->next->data = cur->data;
                cur->data = next_data;
            }

            if(cur == start && end_unsorted == cur->next) break;

            cur = cur->next;
        }

        end_unsorted = cur;
    }
}

void print_person_linked_list(LinkedList* ll) {
    if(ll == NULL || linked_list_is_empty(ll)) return;

    LinkedListNode* cur = ll->head;

    printf("Start Linked List-----------\n");
    for(int i = 1; cur != NULL; i++) {
        printf("[Person %d]\n", i);
        person_print(cur->data);

        if(cur->next != NULL) printf("\n");

        cur = cur->next;
    }
    printf("End Linked List-------------\n");
}
