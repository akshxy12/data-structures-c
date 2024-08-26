#include "../../../../include/data-structures/non-linear-ds/trees/tree.h"

TreeNode* tree_node_create(void* data, TreeNode* left_child, TreeNode* right_child) {
    TreeNode* new_node = (TreeNode*) malloc(sizeof(TreeNode));

    if(new_node == NULL) return NULL;

    new_node->data = data;
    new_node->left_child = left_child;
    new_node->right_child = right_child;

    return new_node;
}

void tree_node_destroy(TreeNode** tree_node_ptr) {
    if(*tree_node_ptr == NULL) return;

    free((*tree_node_ptr)->data);
    (*tree_node_ptr)->data = NULL;

    (*tree_node_ptr)->left_child = NULL;
    (*tree_node_ptr)->right_child = NULL;

    free(*tree_node_ptr);
    *tree_node_ptr = NULL;
}

/* ----------------------------- Tree Functions ----------------------------- */
Tree* tree_create() {
    Tree* new_tree = (Tree*) malloc(sizeof(Tree));

    if(new_tree == NULL) return NULL;

    new_tree->root = NULL;
    new_tree->depth = 0;

    return new_tree;
}

void tree_inorder_traversal(Tree* tree) {
    
}

void tree_preorder_traversal(Tree* tree);
void tree_postorder_traversal(Tree* tree);
void tree_destroy(Tree** treePtr);