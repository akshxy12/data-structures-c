#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/* ----------------------------- Data Structures ---------------------------- */
/**
 *  Linked list node structure
 *  @var    data    Data stored by the node
 *  @var    next    Pointer to the next node
 */
typedef struct _linked_list_node {
    void* data;
    struct _linked_list_node* next;
} LinkedListNode;

/**
 *  Linked list structure
 *  @var    head    Pointer to the first element of the list
 */
typedef struct _linked_list {
    LinkedListNode* head;
    int size;
} LinkedList;


/* ----------------------- Linked List Node Functions ----------------------- */

/**
 *  Create a linked list node object
 *  @param  data        Data stored by the node
 *  @return new_node    Newly created node
 */
LinkedListNode* linked_list_node_create(void* data);

/**
 *  Destroy a linked list node object
 *  @param  linked_list_node_ptr    Pointer to linked list object
 *  @return data                    Data stored by the node
 */
void* linked_list_node_destroy(LinkedListNode** linked_list_node_ptr);

/* -------------------------- Linked List Functions ------------------------- */

/**
 *  Create a linked list object
 *  @return new_linked_list Newly create linked list
 */
LinkedList* linked_list_create();

/**
 *  Insert node to the start of the linked list
 *  @param  linked_list     Linked list
 *  @param  data            Data stored by the new node added
 *  @return (status: bool)  True, if operation performed successfully, else False
 */
bool linked_list_add_beginning(LinkedList* linked_list, void* data);

/**
 *  Insert node to the end of the linked list
 *  @param  linked_list     Linked list
 *  @param  data            Data stored by the new node added
 *  @return (status: bool)  True, if operation performed successfully, else False
 */
bool linked_list_add_end(LinkedList* linked_list, void* data);

/**
 *  Insert node to the middle of the linked list
 *  @param  linked_list     Linked list
 *  @param  data            Data stored by the new node added
 *  @param  position        Position in which node is to be added
 *  @return (status: bool)  True, if operation performed successfully, else False
 */
bool linked_list_add_middle(LinkedList* linked_list, void* data, int position);

/**
 *  Delete node from the start of the linked list
 *  @param  linked_list Linked list
 *  @return data        Data stored by deleted node
 */
void* linked_list_delete_beginning(LinkedList* linked_list);

/**
 *  Delete node from the end of the linked list
 *  @param  linked_list Linked list
 *  @return data        Data stored by deleted node
 */
void* linked_list_delete_end(LinkedList* linked_list);

/**
 *  Delete node from the middle of the linked list
 *  @param  linked_list Linked list
 *  @param  position    Position of the node to be deleted
 *  @return data        Data stored by deleted node
 */
void* linked_list_delete_middle(LinkedList* linked_list, int position);

/** 
 *  ! Implementation to be done for your data
 *  Search for a node in linked list
 *  @param  linked_list Linked list
 *  @param  to_search   Variable used to identify the node
 *  @return data        Data stored by the node
 */
void* linked_list_search(LinkedList* linked_list, void* to_search);

/**
 *  ! Implementation to be done for your data
 *  Sorting linked list in ascending order using bubble sort
 *  @param  linked_list Linked list
 */
void linked_list_sort_ascending(LinkedList* linked_list);

/**
 *  ! Implementation to be done for your data
 *  Sorting linked list in descending order using bubble sort
 *  @param  linked_list Linked list
 */
void linked_list_sort_descending(LinkedList* linked_list);

/**
 *  Check if linked list is empty
 *  @param  linked_list     Linked list
 *  @return (status: bool)  True, if linked list is empty, else False
 */
bool linked_list_is_empty(LinkedList* linked_list);

/**
 *  Destroy linked list destroy
 *  @param  linked_list_ptr     Pointer to linked list object
 */
void linked_list_destroy(LinkedList** linked_list_ptr);

#endif