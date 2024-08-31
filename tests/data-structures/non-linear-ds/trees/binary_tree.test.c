#include <stdio.h>
#include "include/data-structures/non-linear-ds/tree.h"

int main() {
    BinaryTree* t = binary_tree_create();
    BinaryTreeNode* tn1 = binary_tree_node_create(1, NULL, NULL);
    BinaryTreeNode* tn2 = binary_tree_node_create(2, NULL, NULL);
    BinaryTreeNode* tn3 = binary_tree_node_create(3, NULL, NULL);
    BinaryTreeNode* tn4 = binary_tree_node_create(4, NULL, NULL);
    BinaryTreeNode* tn5 = binary_tree_node_create(5, NULL, NULL);
    BinaryTreeNode* tn6 = binary_tree_node_create(6, NULL, NULL);
    BinaryTreeNode* tn7 = binary_tree_node_create(7, NULL, NULL);
    BinaryTreeNode* tn8 = binary_tree_node_create(8, NULL, NULL);

    t->root = tn1;
    tn1->left_child = tn2;
    tn1->right_child = tn5;

    tn2->left_child = tn3;
    tn2->right_child = tn4;

    tn5->left_child = tn6;
    tn5->right_child = tn7;

    tn7->left_child = tn8;

    binary_tree_inorder_traversal(t);
    binary_tree_preorder_traversal(t);
    binary_tree_postorder_traversal(t);

    binary_tree_destroy(&t);

    return 0;
}
