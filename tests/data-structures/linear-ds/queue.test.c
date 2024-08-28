#include <stdio.h>
#include "include/data-structures/queue.h"
#include "include/person.h"

void print_person_queue(Queue* q) {
    if(q == NULL || queue_is_empty(q)) return;

    QueueNode* cur = q->front;

    printf("Queue START-----------\n");
    for(int i = 1; cur != NULL; i++) {
        printf("[Person\t%d]\n", i);

        person_print(cur->data);

        if(cur->next != NULL) {
            printf("\n");
        }

        cur = cur->next;
    }
    printf("Queue END-------------\n");
}

int main() {
    Person* p1 = person_create("John", 22, 'M', 1.7);
    Person* p2 = person_create("Doe", 20, 'F', 1.65);
    Person* p3 = person_create("Marie", 22, 'M', 1.7);
    Queue* q = queue_create();

    queue_enqueue(q, p1);
    queue_enqueue(q, p2);
    queue_enqueue(q, p3);

    Person* removed_person = queue_dequeue(q);
    printf("Removed Person:\n");
    person_print(removed_person);
    printf("\n");

    Person* peek_person = queue_peek(q);
    printf("Person at the front:\n");
    person_print(peek_person);
    printf("\n");

    print_person_queue(q);

    peek_person = NULL;
    queue_destroy(&q);
    person_destroy(&removed_person);
    
    return 0;
}