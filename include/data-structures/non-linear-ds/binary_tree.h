#ifndef TREE_H
#define TREE_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct _binary_tree_node {
    int data;
    struct _binary_tree_node *left_child;
    struct _binary_tree_node *right_child;
} BinaryTreeNode;

typedef struct _tree {
    BinaryTreeNode* root;
} BinaryTree;

/* --------------------------- Binary Tree Node Functions -------------------------- */
BinaryTreeNode* binary_tree_node_create(int data, BinaryTreeNode* left_child, BinaryTreeNode* right_child);
void binary_tree_node_destroy(BinaryTreeNode** treeNodePtr);

/* ----------------------------- Binary Tree Functions ----------------------------- */
BinaryTree* binary_tree_create();

bool binary_tree_insertion(BinaryTree* tree, int data);
bool _binary_tree_insertion_recurse(BinaryTreeNode* parent_node, int data);

bool binary_tree_deletion(BinaryTree* tree, int data);
BinaryTreeNode* _binary_tree_find_rightmost_leaf_node(BinaryTreeNode* node);
BinaryTreeNode* _binary_tree_find_parent_node(BinaryTreeNode* root, int child_node_data);
bool _binary_tree_deletion_recurse(BinaryTreeNode* parent_node, int data);

void binary_tree_inorder_traversal(BinaryTree* tree);
void _binary_tree_inorder_traversal_recurse(BinaryTreeNode* tnode);

void binary_tree_preorder_traversal(BinaryTree* tree);
void _binary_tree_preorder_traversal_recurse(BinaryTreeNode* tnode);

void binary_tree_postorder_traversal(BinaryTree* tree);
void _binary_tree_postorder_traversal_recurse(BinaryTreeNode* tnode);

void binary_tree_print(BinaryTree* tree);
void _binary_tree_print_recurse(BinaryTreeNode* node);

void binary_tree_destroy(BinaryTree** treePtr);
void _binary_tree_destroy_postorder(BinaryTreeNode* tnode);

#endif
