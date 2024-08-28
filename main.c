#include <stdio.h>
#include "include/data-structures/non-linear-ds/trees/tree.h"

int main() {
    Tree* t = tree_create();
    TreeNode* tn1 = tree_node_create(1, NULL, NULL);
    TreeNode* tn2 = tree_node_create(2, NULL, NULL);
    TreeNode* tn3 = tree_node_create(3, NULL, NULL);
    TreeNode* tn4 = tree_node_create(4, NULL, NULL);
    TreeNode* tn5 = tree_node_create(5, NULL, NULL);
    TreeNode* tn6 = tree_node_create(6, NULL, NULL);
    TreeNode* tn7 = tree_node_create(7, NULL, NULL);
    TreeNode* tn8 = tree_node_create(8, NULL, NULL);

    t->root = tn1;
    tn1->left_child = tn2;
    tn1->right_child = tn5;

    tn2->left_child = tn3;
    tn2->right_child = tn4;

    tn5->left_child = tn6;
    tn5->right_child = tn7;

    tn7->left_child = tn8;

    tree_inorder_traversal(t);
    tree_preorder_traversal(t);
    tree_postorder_traversal(t);

    tree_destroy(&t);

    return 0;
}
