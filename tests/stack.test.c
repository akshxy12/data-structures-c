#include <stdio.h>

#include "../include/stack.h"
#include "../include/person.h"

void print_person_stack(Stack* s) {
    if(s == NULL || stack_is_empty(s)) return;

    StackNode* cur = s->top;
    
    printf("\nStack START--------\n");
    for(int i = 1; cur != NULL; i++) {
        printf("[Person %d]\n", i);

        if(cur->data != NULL) person_print(cur->data);

        if(cur->next != NULL) printf("\n");

        cur = cur->next;
    }
    printf("Stack END----------\n");
}

int main()
{
    Person* p1 = person_create("Akshay", 22, 'M', 1.7);
    Person* p2 = person_create("Anushka", 20, 'F', 1.65);
    Person* p3 = person_create("Arjun", 22, 'M', 1.7);
    Stack* s = stack_create();

    stack_push(s, p1);
    stack_push(s, p2);
    stack_push(s, p3);

    Person* removed_person = stack_pop(s);
    printf("Removed Person: \n");
    person_print(removed_person);
    printf("\n");

    Person* peeked_person = stack_peek(s);
    printf("Person at the top:\n");
    person_print(peeked_person);

    print_person_stack(s);

    peeked_person = NULL;
    stack_destroy(&s);
    person_destroy(&removed_person);

    return 0;
}