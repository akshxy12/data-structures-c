#include "../include/linked_list.h"

LinkedListNode* linked_list_node_create(void* data) {
    LinkedListNode* new_node = (LinkedListNode*) malloc(sizeof(LinkedListNode));

    if(new_node == NULL) return NULL;

    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

void* linked_list_node_destroy(LinkedListNode** linked_list_node_ptr) {
    if(*linked_list_node_ptr == NULL) return NULL;

    void* data_of_deleted_node = (*linked_list_node_ptr)->data;

    (*linked_list_node_ptr)->data = NULL;
    (*linked_list_node_ptr)->next = NULL;

    free(*linked_list_node_ptr);
    *linked_list_node_ptr = NULL;

    return data_of_deleted_node;
}

LinkedList* linked_list_create() {
    LinkedList* new_linked_list = (LinkedList*) malloc(sizeof(LinkedList));

    if(new_linked_list == NULL) return NULL;

    new_linked_list->head = NULL;
    new_linked_list->size = 0;

    return new_linked_list;
}

bool linked_list_add_beginning(LinkedList* linked_list, void* data) {
    if(linked_list == NULL || data == NULL) return false;

    LinkedListNode* new_node = linked_list_node_create(data);

    if(linked_list->head == NULL) {
        linked_list->head = new_node;
    } else {
        new_node->next = linked_list->head;
        linked_list->head = new_node;
    }

    ++linked_list->size;
    return true;
}

bool linked_list_add_end(LinkedList* linked_list, void* data) {
    if(linked_list == NULL || data == NULL) return false;

    LinkedListNode* new_node = linked_list_node_create(data);

    if(linked_list->head == NULL) {
        linked_list->head = new_node;
    } else {
        LinkedListNode* cur = linked_list->head;

        while(cur->next != NULL) cur = cur->next;

        cur->next = new_node;
    }

    ++linked_list->size;
}

bool linked_list_add_middle(LinkedList* linked_list, void* data, int position) {
    if(linked_list == NULL || data == NULL || position <= 0) return false;
    //  Below line written separately to make sure linked list is created, before accessing its size
    if(position > linked_list->size+1) return false;

    if(position == 1) return linked_list_add_beginning(linked_list, data);
    else if(position == linked_list->size+1) return linked_list_add_end(linked_list, data);

    LinkedListNode* new_node = linked_list_node_create(data);

    LinkedListNode  *cur = linked_list->head,
                    *prev = NULL;
    for(int i = 1; cur != NULL && i < position; i++) {
        prev = cur;
        cur = cur->next;
    }

    new_node->next = prev->next;
    prev->next = new_node;

    ++linked_list->size;
    return true;
}

void* linked_list_delete_beginning(LinkedList* linked_list) {
    if(linked_list == NULL || linked_list_is_empty(linked_list)) return NULL;

    LinkedListNode* node_to_be_deleted = linked_list->head;
    linked_list->head = linked_list->head->next;

    void* data = linked_list_node_destroy(&node_to_be_deleted);
    
    --linked_list->size;
    return data;
}

void* linked_list_delete_end(LinkedList* linked_list) {
    if(linked_list == NULL || linked_list_is_empty(linked_list)) return NULL;

    LinkedListNode  *node_to_be_deleted = linked_list->head,
                    *prev = NULL;
    void *data = NULL;
    
    while(node_to_be_deleted->next != NULL) {
        prev = node_to_be_deleted;
        node_to_be_deleted = node_to_be_deleted->next;
    }

    if(prev == NULL) {
        linked_list->head = NULL;
    } else {
        prev->next = NULL;
    }

    data = linked_list_node_destroy(&node_to_be_deleted);

    --linked_list->size;
    return data;
}

void* linked_list_delete_middle(LinkedList* linked_list, int position) {
    if(linked_list == NULL) return false;
    //  Below line written separately to make sure linked list is created, before accessing its size
    if(position <= 0 || position > linked_list->size) return false;

    if(position == 1) return linked_list_delete_beginning(linked_list);
    else if(position == linked_list->size) return linked_list_delete_end(linked_list);

    LinkedListNode  *node_to_be_deleted = linked_list->head,
                    *prev = NULL;

    for(int i = 1; node_to_be_deleted != NULL && i < position; i++) {
        prev = node_to_be_deleted;
        node_to_be_deleted = node_to_be_deleted->next;
    }

    prev->next = node_to_be_deleted->next;
    void* data = linked_list_node_destroy(&node_to_be_deleted);

    --linked_list->size;
    return data;
}

bool linked_list_is_empty(LinkedList* linked_list) {
    if(linked_list == NULL || linked_list->head != NULL) return false;

    return true;
}

/**
 *  Destroy linked list destroy
 *  @param  linked_list_ptr     Pointer to linked list object
 */
void linked_list_destroy(LinkedList** linked_list_ptr) {
    if(*linked_list_ptr == NULL) return;

    while(!linked_list_is_empty(*linked_list_ptr)) {
        void *data = linked_list_delete_beginning(*linked_list_ptr);

        free(data);
        data = NULL;
    }

    free(*linked_list_ptr);
    *linked_list_ptr = NULL;
}
