#include <stdio.h>
#include "include/data-structures/non-linear-ds/binary_tree.h"

int main() {
    BinaryTree* bt = binary_tree_create();
    if(bt == NULL) {
        printf("Binary Tree not allocated.\n");
    }
/*
    BinaryTreeNode* tn1 = binary_tree_node_create(1, NULL, NULL);
    BinaryTreeNode* tn2 = binary_tree_node_create(2, NULL, NULL);
    BinaryTreeNode* tn3 = binary_tree_node_create(3, NULL, NULL);
    BinaryTreeNode* tn4 = binary_tree_node_create(4, NULL, NULL);
    BinaryTreeNode* tn5 = binary_tree_node_create(5, NULL, NULL);
    BinaryTreeNode* tn6 = binary_tree_node_create(6, NULL, NULL);
    BinaryTreeNode* tn7 = binary_tree_node_create(7, NULL, NULL);
    BinaryTreeNode* tn8 = binary_tree_node_create(8, NULL, NULL);
    BinaryTreeNode* tn99 = binary_tree_node_create(99, NULL, NULL);
*/
    binary_tree_insert_by_level_order(bt, 1);
    binary_tree_insert_by_level_order(bt, 2);
    binary_tree_insert_by_level_order(bt, 3);
    binary_tree_insert_by_level_order(bt, 4);
    binary_tree_insert_by_level_order(bt, 5);
    binary_tree_insert_by_level_order(bt, 6);
    binary_tree_insert_by_level_order(bt, 7);
    binary_tree_insert_by_level_order(bt, 8);
    binary_tree_insert_by_level_order(bt, 9);
   
    // binary_tree_destroy(&bt);
    binary_tree_print(bt);
    return 0;
}
