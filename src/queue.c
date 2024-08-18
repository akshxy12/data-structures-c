#include "../include/queue.h"

QueueNode* queue_node_create(void* data) {
    QueueNode* new_node = (QueueNode*) malloc(sizeof(QueueNode));

    if(new_node == NULL) return NULL;

    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

void* queue_node_destroy(QueueNode** queue_node_ptr) {
    if(*queue_node_ptr == NULL) return NULL;

    void* node_data = (*queue_node_ptr)->data;
    free(*queue_node_ptr);
    *queue_node_ptr = NULL;

    return node_data;
}

Queue* queue_create() {
    Queue* new_queue = (Queue*) malloc(sizeof(Queue));

    if(new_queue == NULL) {
        free(new_queue);

        return NULL;
    }

    new_queue->front = NULL;
    new_queue->rear = NULL;
    new_queue->size = 0;

    return new_queue;
}

bool queue_enqueue(Queue* queue, void* data) {
    if(queue == NULL || data == NULL) return false;

    QueueNode* new_node = queue_node_create(data);

    if(new_node == NULL) return false;

    if(queue->front == NULL && queue->rear == NULL) {
        queue->front = queue->rear = new_node;
    } else {
        queue->rear->next = new_node;
        queue->rear = new_node;
    }

    ++queue->size;

    return true;
}

void* queue_dequeue(Queue* queue) {
    if(queue == NULL || queue_is_empty(queue)) return NULL;

    QueueNode* removed_node = queue->front;
    void* removed_node_data = removed_node->data;

    if(queue->front == queue->rear) queue->front = queue->rear = NULL;
    else {
        queue->front = queue->front->next;
    }

    queue_node_destroy(&removed_node);
    --queue->size;

    return removed_node_data;
}

bool queue_is_empty(Queue* queue) {
    if(queue == NULL || (queue->front != NULL && queue->rear != NULL)) return false;

    return true;
}

void* queue_peek(Queue* queue) {
    if(queue == NULL || queue_is_empty(queue)) return NULL;

    void* data = queue->front->data;

    return data;
}

void queue_destroy(Queue** queue_ptr) {
    if(*queue_ptr == NULL) return;

    while(!queue_is_empty(*queue_ptr)) {
        void* data = queue_dequeue(*queue_ptr);

        free(data);
        data = NULL;
    }

    free(*queue_ptr);
    *queue_ptr = NULL;
}