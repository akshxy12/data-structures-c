#ifndef TREE_H
#define TREE_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct _tree_node {
    int data;
    struct _tree_node *left_child;
    struct _tree_node *right_child;
} TreeNode;

typedef struct _tree {
    TreeNode* root;
    int depth;
} Tree;

/* --------------------------- Tree Node Functions -------------------------- */
TreeNode* tree_node_create(int data, TreeNode* left_child, TreeNode* right_child);
void tree_node_destroy(TreeNode** treeNodePtr);

/* ----------------------------- Tree Functions ----------------------------- */
Tree* tree_create();

void tree_inorder_traversal(Tree* tree);
void _tree_inorder_traversal_recurse(TreeNode* tnode);

void tree_preorder_traversal(Tree* tree);
void _tree_preorder_traversal_recurse(TreeNode* tnode);

void tree_postorder_traversal(Tree* tree);
void _tree_postorder_traversal_recurse(TreeNode* tnode);

void tree_destroy(Tree** treePtr);
void _tree_destroy_postorder(TreeNode* tnode);

#endif
