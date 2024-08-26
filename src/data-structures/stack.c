#include "../../include/data-structures/stack.h"

StackNode* stack_node_create(void* data) {
    StackNode* new_stack_node = (StackNode*) malloc(sizeof(StackNode));

    if(new_stack_node == NULL) return NULL;

    //  Initialize stack node
    new_stack_node->data = data;
    new_stack_node->next = NULL;

    return new_stack_node;
}

void* stack_node_destroy(StackNode** stack_node_ptr) {
    if(*stack_node_ptr == NULL) return NULL;

    void* data = (*stack_node_ptr)->data;

    //  Freeing stack node variables
    (*stack_node_ptr)->data = NULL;
    (*stack_node_ptr)->next = NULL;

    //  Destroying stack node
    free((*stack_node_ptr));
    (*stack_node_ptr) = NULL;

    return data;
}

Stack* stack_create() {
    Stack* new_stack = (Stack*) malloc(sizeof(Stack));

    if(new_stack == NULL) {
        return NULL;
    }

    //  Initialize stack
    new_stack->top = NULL;
    new_stack->size = 0;

    return new_stack;
}

bool stack_push(Stack* stack, void* data) {
    if(stack == NULL || data == NULL) return false;

    StackNode* newnode = stack_node_create(data);

    if(stack->top == NULL) {
        stack->top = newnode;
    } else {
        newnode->next = stack->top;
        stack->top = newnode;
    }

    ++stack->size;

    return true;
}

void* stack_pop(Stack* stack) {
    if(stack == NULL || stack_is_empty(stack)) return NULL;

    StackNode* removed_node = stack->top;
    stack->top = stack->top->next;

    --stack->size;

    return stack_node_destroy(&removed_node);
}

void* stack_peek(Stack* stack) {
    if(stack == NULL || stack_is_empty(stack)) return NULL;

    return stack->top->data;
}

bool stack_is_empty(Stack* stack) {
    if(stack == NULL || stack->top != NULL) return false;

    return true;
}

bool stack_destroy(Stack** stack_ptr) {
    if(*stack_ptr == NULL) return true;

    while(!stack_is_empty(*stack_ptr)) {
        void* removed_node_data = stack_pop(*stack_ptr);

        free(removed_node_data);
        removed_node_data = NULL;
    }

    free(*stack_ptr);
    *stack_ptr = NULL;
}