#ifndef STACK_H
#define STACK_H

#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 *  Defining stack node
 *  @var    data    Data stored by node
 *  @var    next    Pointer to next node
 */
typedef struct _stack_node StackNode;
struct _stack_node {
    void* data;
    StackNode* next;
};

/**
 *  Defining stack
 *  @var    top     Pointer to top node of stack
 *  @var    size    No. of nodes in stack
 */
typedef struct _stack Stack;
struct _stack {
    StackNode* top;
    int size;
};

/* --------------------------- Stack Node Functions -------------------------- */

/**
 *  Create a stack node object
 *  @param  data            Data stored by the node
 *  @return new_stack_node  New node created
 */
StackNode* stack_node_create(void* data);

/**
 *  Delete a stack node object
 *  @param  stack_node_ptr  Pointer to a stack node
 *  @return data            Data stored by deleted node
 */
void* stack_node_destroy(StackNode** stack_node_ptr);

/* ----------------------------- Stack Functions ---------------------------- */

/**
 *  Create a new stack object
 *  @return new_stack   New stack created
 */
Stack* stack_create();

/**
 *  Add node to the stack
 *  @param  stack               Stack object
 *  @param  data                Data stored in new node
 *  @return (status: bool)      True, if there are no errors, else False
 */
bool stack_push(Stack* stack, void* data);

/**
 *  Delete node from the stack
 *  @param  stack               Stack object
 *  @return removed_node_data   Data stored in removed stack node
 */
void* stack_pop(Stack* stack);

/**
 *  Get value of the top node
 *  @param  stack   Stack object
 *  @return data    Data stored by top node
 */
void* stack_peek(Stack* stack);

/**
 *  Checks if stack is empty
 *  @param  stack           Stack object
 *  @return (status: bool)  True, if there are no errors, else False
 */
bool stack_is_empty(Stack* stack);

/**
 *  Destroy stack object    
 *  @param  stack_ptr       Pointer to stack object
 *  @return (status: bool)  True, if there are no errors, else False
 */
bool stack_destroy(Stack** stack_ptr);

#endif