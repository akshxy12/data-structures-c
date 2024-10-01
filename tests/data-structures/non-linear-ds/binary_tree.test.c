#include <stdio.h>
#include "include/data-structures/non-linear-ds/binary_tree.h"

int main() {
    BinaryTree* bt = binary_tree_create();
   
    binary_tree_insert_by_value(bt, 10);
    binary_tree_insert_by_value(bt, 8);
    binary_tree_insert_by_value(bt, 6);
    binary_tree_insert_by_value(bt, 9);
    binary_tree_insert_by_value(bt, 20);
    binary_tree_insert_by_value(bt, 10);
    binary_tree_insert_by_value(bt, 35);
    binary_tree_insert_by_value(bt, 13);
    binary_tree_insert_by_value(bt, 15);
    binary_tree_insert_by_value(bt, 4);
    binary_tree_insert_by_value(bt, 1);
    binary_tree_insert_by_value(bt, 16);

    binary_tree_print(bt);
    binary_tree_insert_by_value(bt, 1000);
    binary_tree_delete_with_next_smallest(bt, 1);
    binary_tree_print(bt);
    
    binary_tree_destroy(&bt);
    return 0;
}
