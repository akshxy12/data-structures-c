#include <stdio.h>
#include <stdlib.h>
#include "include/data-structures/priority_queue.h"
#include "include/person.h"

void print_person_priority_queue(PriorityQueue *priority_queue)
{
    if (priority_queue == NULL || priority_queue_is_empty(priority_queue))
        return;

    PriorityQueueNode *cur = priority_queue->front;

    printf("Priority Queue Start-------\n");
    for (int i = 1; cur != NULL; i++)
    {
        printf("[Person %d]\n", i);
        printf("[Priority: %d]\n", cur->priority);
        person_print(cur->data);

        if (cur->next != NULL)
            printf("\n");

        cur = cur->next;
    }
    printf("Priority Queue End---------\n");
}

int main()
{
    Person* p1 = person_create("John", 22, 'M', 1.7);
    Person* p2 = person_create("Doe", 20, 'F', 1.65);
    Person* p3 = person_create("Marie", 22, 'M', 1.7);
    PriorityQueue *pq = priority_queue_create();

    priority_queue_enqueue(pq, p1, 2);
    priority_queue_enqueue(pq, p2, 1);
    priority_queue_enqueue(pq, p3, 3);

    Person *removed_person = priority_queue_dequeue(pq);
    printf("Removed person:\n");
    person_print(removed_person);
    printf("\n");

    print_person_priority_queue(pq);

    priority_queue_destroy(&pq);
    person_destroy(&removed_person);

    return 0;
}