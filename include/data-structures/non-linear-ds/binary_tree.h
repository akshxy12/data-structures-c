#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "../linear-ds/queue.h"

typedef struct _binary_tree_node {
    int data;
    struct _binary_tree_node *left_child;
    struct _binary_tree_node *right_child;
} BinaryTreeNode;

typedef struct _binary_tree {
    BinaryTreeNode* root;
} BinaryTree;

/* --------------------------- Binary Tree Node Functions -------------------------- */
BinaryTreeNode* binary_tree_node_create(int data, BinaryTreeNode* left_child, BinaryTreeNode* right_child);
void binary_tree_node_destroy(BinaryTreeNode** btnodeptr);

/* ----------------------------- Binary Tree Functions ----------------------------- */
BinaryTree* binary_tree_create();

bool binary_tree_insert_by_value(BinaryTree* bt, int data);
bool _binary_tree_insert_by_value_recurse(BinaryTreeNode* btnode, int data);
bool binary_tree_insert_by_level_order(BinaryTree* bt, int data);
bool _binary_tree_insert_by_level_order_recurse(BinaryTreeNode* btnode, Queue* q, int data);

//  ! Note: Did not find a way to delete nodes inserted through level order
bool binary_tree_delete_with_next_smallest(BinaryTree* bt, int data);
BinaryTreeNode* _binary_tree_find_parent_node(BinaryTreeNode* btnode, int data);
BinaryTreeNode* _binary_tree_find_next_smallest_parent(BinaryTreeNode* btnode);
BinaryTreeNode* _binary_tree_find_next_smallest_parent(BinaryTreeNode* btnode); 
bool binary_tree_delete_with_next_biggest(BinaryTree* bt, int data);
BinaryTreeNode* _binary_tree_find_next_biggest_parent(BinaryTreeNode* btnode); 

void binary_tree_inorder(BinaryTree* bt);
void _binary_tree_inorder_traversal(BinaryTreeNode* btnode);

void binary_tree_preorder(BinaryTree* bt);
void _binary_tree_preorder_traversal(BinaryTreeNode* btnode);

void binary_tree_postorder(BinaryTree* bt);
void _binary_tree_postorder_traversal(BinaryTreeNode* btnode);

void binary_tree_print(BinaryTree* bt);
void _binary_tree_print_recurse(BinaryTreeNode* btnode, int level); 

void binary_tree_destroy(BinaryTree** btptr);
void _binary_tree_destroy_recurse(BinaryTreeNode* btnode); 

//  ! Debugging functions
void binary_tree_queue_print(Queue* q);

#endif
