#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/* ----------------------------- Data Structures ---------------------------- */

/**
 *  Defining priority queue node object
 *  @var    data        Data stored by node
 *  @var    priotity    Priority of the node(1 => highest priority, 10 => lowest priority)
 *  @var    next        Pointer to the next node
 */
typedef struct _priority_queue_node {
    void* data;
    int priority;
    struct _priority_queue_node* next;
} PriorityQueueNode;

/**
 *  Defining priority queue object
 *  @var    front   Pointer to the first node of the queue
 *  @var    rear    Pointer to the last node of the queue
 *  @var    size    No. of nodes in the queue
 */
typedef struct _priority_queue {
    PriorityQueueNode* front;
    PriorityQueueNode* rear;
    int size;
} PriorityQueue;

/* ---------------------- Priority Queue Node Functions --------------------- */

/**
 *  Create a priority queue node object
 *  @param  data                        Data stored by the node
 *  @param  priority                    Priority of the new node
 *  @return new_priority_queue_node     Newly created node
 */
PriorityQueueNode* priority_queue_node_create(void* data, int priority);

/**
 *  Destroying a priority queue node object
 *  @param  priority_queue_node_ptr     Pointer to a priority queue node
 *  @return data                        Data stored by the removed node
 */
void* priority_queue_node_destroy(PriorityQueueNode** priority_queue_node_ptr);

/* ------------------------ Priority Queue Functions ------------------------ */

/**
 *  Create a priority queue object
 *  @return new_priority_queue  Newly created priority queue
 */
PriorityQueue* priority_queue_create();

/**
 *  Add node to the queue
 *  @param  priority_queue  Priority queue
 *  @param  data            Data to be stored by new node
 *  @param  priority        Priority of the new node
 *  @return (status: bool)  True, if no errors found, else False
 */
bool priority_queue_enqueue(PriorityQueue* priority_queue, void* data, int priority);

/**
 *  Delete node from the queue
 *  @param  priority_queue  Priority queue
 *  @return data            Data stored by the deleted node
 */
void* priority_queue_dequeue(PriorityQueue* priority_queue);

/**
 *  Check if queue is empty
 *  @param  priority_queue  Priority queue
 *  @return (status: bool)  True, if queue is empty, else False
 */
bool priority_queue_is_empty(PriorityQueue* priority_queue);

/**
 *  Get data stored by the front node
 *  @param  priority_queue  Priority queue
 *  @return data            Data stored by the front node
 */
void* priority_queue_peek(PriorityQueue* priority_queue);

/**
 *  Destroy a priority queue object
 *  @param  priority_queue_ptr  Pointer to a priority queue
 */
void priority_queue_destroy(PriorityQueue** priority_queue_ptr);

#endif