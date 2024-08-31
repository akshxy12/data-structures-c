#include <stdio.h>
#include "include/data-structures/non-linear-ds/binary_tree.h"

int main() {
    BinaryTree* bt = binary_tree_create();

    BinaryTreeNode* tn1 = binary_tree_node_create(1, NULL, NULL);
    BinaryTreeNode* tn2 = binary_tree_node_create(2, NULL, NULL);
    BinaryTreeNode* tn3 = binary_tree_node_create(3, NULL, NULL);
    BinaryTreeNode* tn4 = binary_tree_node_create(4, NULL, NULL);
    BinaryTreeNode* tn5 = binary_tree_node_create(5, NULL, NULL);
    BinaryTreeNode* tn6 = binary_tree_node_create(6, NULL, NULL);
    BinaryTreeNode* tn7 = binary_tree_node_create(7, NULL, NULL);
    BinaryTreeNode* tn8 = binary_tree_node_create(8, NULL, NULL);
    BinaryTreeNode* tn99 = binary_tree_node_create(99, NULL, NULL);

    bt->root = tn1;
    tn1->left_child = tn2;
    tn1->right_child = tn5;

    tn2->left_child = tn3;
    tn2->right_child = tn4;

    tn3->right_child = tn99;

    tn5->left_child = tn6;
    tn5->right_child = tn7;

    tn7->left_child = tn8;

    binary_tree_insertion(bt, 10);

    binary_tree_deletion(bt, 1);
    binary_tree_deletion(bt, 2);
    
    binary_tree_print(bt);

    printf("Inorder: ");
    binary_tree_inorder_traversal(bt);
    printf("\n");
    printf("Pre-order: ");
    binary_tree_preorder_traversal(bt);
    printf("\n");
    printf("Post-order: ");
    binary_tree_postorder_traversal(bt);
    printf("\n");

    binary_tree_destroy(&bt);
    return 0;
}