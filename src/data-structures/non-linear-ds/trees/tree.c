#include "../../../../include/data-structures/non-linear-ds/trees/tree.h"

TreeNode* tree_node_create(int data, TreeNode* left_child, TreeNode* right_child) {
    TreeNode* new_node = (TreeNode*) malloc(sizeof(TreeNode));

    if(new_node == NULL) return NULL;

    new_node->data = data;
    new_node->left_child = left_child;
    new_node->right_child = right_child;

    return new_node;
}

void tree_node_destroy(TreeNode** tree_node_ptr) {
    if(*tree_node_ptr == NULL) return;

    (*tree_node_ptr)->data = 0;
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
    _tree_inorder_traversal_recurse(tree->root);
    printf("\n");
}

void _tree_inorder_traversal_recurse(TreeNode* tnode) {
    if(tnode == NULL) return;

    _tree_inorder_traversal_recurse(tnode->left_child);
    printf("%d ", tnode->data);
    _tree_inorder_traversal_recurse(tnode->right_child);
}

void tree_preorder_traversal(Tree* tree) {
    _tree_preorder_traversal_recurse(tree->root);
    printf("\n");
}

void _tree_preorder_traversal_recurse(TreeNode* tnode) {
    if(tnode == NULL) return;
    
    printf("%d ", tnode->data);
    _tree_preorder_traversal_recurse(tnode->left_child);
    _tree_preorder_traversal_recurse(tnode->right_child);
}

void tree_postorder_traversal(Tree* tree) {
    _tree_postorder_traversal_recurse(tree->root);
    printf("\n");
}

void _tree_postorder_traversal_recurse(TreeNode* tnode) {
    if(tnode == NULL) return;

    _tree_postorder_traversal_recurse(tnode->left_child);
    _tree_postorder_traversal_recurse(tnode->right_child);
    printf("%d ", tnode->data);
}

void tree_destroy(Tree** treePtr) {
    if(*treePtr == NULL) return;

    if((*treePtr)->root != NULL) {
        _tree_destroy_postorder((*treePtr)->root);
    }

    free(*treePtr);
    *treePtr = NULL;
}

void _tree_destroy_postorder(TreeNode* tnode) {
    if(tnode == NULL) return;

    _tree_destroy_postorder(tnode->left_child);
    _tree_destroy_postorder(tnode->right_child);

    tree_node_destroy(&tnode);
}
