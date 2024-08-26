#ifndef TREE_H
#define TREE_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct _tree_node {
    void* data;
    struct _tree *left_child;
    struct _tree *right_child;
} TreeNode;

typedef struct _tree {
    TreeNode* root;
    int depth;
} Tree;

/* --------------------------- Tree Node Functions -------------------------- */
TreeNode* tree_node_create(void* data, TreeNode* left_child, TreeNode* right_child);
void tree_node_destroy(TreeNode** treeNodePtr);

/* ----------------------------- Tree Functions ----------------------------- */
Tree* tree_create();
void tree_inorder_traversal(Tree* tree);
void tree_preorder_traversal(Tree* tree);
void tree_postorder_traversal(Tree* tree);
void tree_destroy(Tree** treePtr);

#endif