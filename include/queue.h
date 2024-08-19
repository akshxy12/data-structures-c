#ifndef QUEUE_H
#define QUEUE_H

#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 *  Defining queue node object
 *  @var    data    Data stored by the node
 *  @var    next
 */
typedef struct _queue_node {
    void* data;
    struct _queue_node* next;
} QueueNode;

/**
 *  Defining queue object
 *  @var    front   Pointer to the front of the queue
 *  @var    rear    Pointer to the back of the queue
 *  @var    size    No. of nodes in the queue
 */
typedef struct _queue {
    QueueNode* front;
    QueueNode* rear;
    int size;
} Queue;

/* -------------------------- Queue Node Functions -------------------------- */

/**
 *  Creates queue node object
 *  @param  data        Data stored by the node
 *  @return new_node    Newly created queue node
 */
QueueNode* queue_node_create(void* data);

/**
 *  Destroys queue node object
 *  @param  queue_node_ptr  Pointer to queue object
 *  @return node_data       Data stored by the node
 */
void* queue_node_destroy(QueueNode** queue_node_ptr);

/* ----------------------------- Queue Functions ---------------------------- */

/**
 *  Create queue object
 *  @return new_queue   Newly created queue object
 */
Queue* queue_create();

/**
 *  Add nodes to the front of the queue
 *  @param  queue           Queue object
 *  @param  data            Data to be added to the queue
 *  @return (status: bool)  True, if no errors occurs, else False
 */
bool queue_enqueue(Queue* queue, void* data);

/**
 *  Delete nodes from the back of the queue
 *  @param  queue   Queue object
 *  @return data    Data stored by the removed node
 */
void* queue_dequeue(Queue* queue);

/**
 *  Checks if the queue is empty
 *  @param  queue           Queue object
 *  @return (status: bool)  True, if queue is empty, else False
 */
bool queue_is_empty(Queue* queue);

/**
 *  Get data stored by the front node
 *  @param  queue   Queue object
 *  @return data    Data stored by the front node
 */
void* queue_peek(Queue* queue);

/**
 *  Destroy queue object
 *  @param  queue_ptr   Pointer to queue object
 */
void queue_destroy(Queue** queue_ptr);

#endif