#include "../../include/data-structures/priority_queue.h"

PriorityQueueNode* priority_queue_node_create(void* data, int priority) {
    PriorityQueueNode* new_priority_queue_node = (PriorityQueueNode*) malloc(sizeof(PriorityQueueNode));

    if(new_priority_queue_node == NULL) return NULL;

    new_priority_queue_node->data = data;
    new_priority_queue_node->priority = priority;
    new_priority_queue_node->next = NULL;

    return new_priority_queue_node;
}

void* priority_queue_node_destroy(PriorityQueueNode** priority_queue_node_ptr) {
    if(*priority_queue_node_ptr == NULL) return NULL;

    void* data = (*priority_queue_node_ptr)->data;

    free(*priority_queue_node_ptr);
    *priority_queue_node_ptr = NULL;

    return data;
}

PriorityQueue* priority_queue_create() {
    PriorityQueue* new_priority_queue = (PriorityQueue*) malloc(sizeof(PriorityQueue));

    if(new_priority_queue == NULL) return NULL;

    new_priority_queue->front = new_priority_queue->rear = NULL;
    new_priority_queue->size = 0;

    return new_priority_queue;
}

bool priority_queue_enqueue(PriorityQueue* priority_queue, void* data, int priority) {
    if(priority_queue == NULL || data == NULL) return false;

    PriorityQueueNode* new_priority_queue_node = priority_queue_node_create(data, priority);

    if(new_priority_queue_node == NULL) return false;

    if(priority_queue->front == NULL && priority_queue->rear == NULL) {
        priority_queue->front = priority_queue->rear = new_priority_queue_node;
    } else {
        PriorityQueueNode   *cur = priority_queue->front,
                            *prev = NULL;
        
        while(cur != NULL && new_priority_queue_node->priority > cur->priority) {
            prev = cur;
            cur = cur->next;
        }

        if(prev == NULL) {
            new_priority_queue_node->next = priority_queue->front;
            priority_queue->front = new_priority_queue_node;
        } else {
            new_priority_queue_node->next = prev->next;
            prev->next = new_priority_queue_node;
        }

        // If node is inserted at the end, update the rear pointer
        if(cur == NULL) {
            priority_queue->rear = new_priority_queue_node;
        }

        cur = NULL;
        prev = NULL;
    }

    ++priority_queue->size;

    return true;
}

void* priority_queue_dequeue(PriorityQueue* priority_queue) {
    if(priority_queue == NULL || priority_queue_is_empty(priority_queue)) return NULL;

    PriorityQueueNode* removed_node = priority_queue->front;

    if(priority_queue->front == priority_queue->rear) priority_queue->front = priority_queue->rear = NULL;
    else {
        priority_queue->front = priority_queue->front->next;
    }

    --priority_queue->size;

    return priority_queue_node_destroy(&removed_node);;
}

bool priority_queue_is_empty(PriorityQueue* priority_queue) {
    if(priority_queue == NULL || priority_queue->front != NULL && priority_queue->rear != NULL) return false;

    return true;
}

void* priority_queue_peek(PriorityQueue* priority_queue) {
    if(priority_queue == NULL || priority_queue_is_empty(priority_queue)) return NULL;

    void* data = priority_queue->front->data;

    return data;
}

void priority_queue_destroy(PriorityQueue** priority_queue_ptr) {
    if(*priority_queue_ptr == NULL) return;

    while(!priority_queue_is_empty(*priority_queue_ptr)) {
        void* data_to_be_deleted = priority_queue_dequeue(*priority_queue_ptr);

        free(data_to_be_deleted);
        data_to_be_deleted = NULL;
    }

    free(*priority_queue_ptr);
    *priority_queue_ptr = NULL;
}