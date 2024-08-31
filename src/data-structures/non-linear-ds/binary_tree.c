#include "../../../include/data-structures/non-linear-ds/binary_tree.h"

BinaryTreeNode *binary_tree_node_create(int data, BinaryTreeNode *left_child, BinaryTreeNode *right_child)
{
    BinaryTreeNode *new_node = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));

    if (new_node == NULL)
        return NULL;

    new_node->data = data;
    new_node->left_child = left_child;
    new_node->right_child = right_child;

    return new_node;
}
void binary_tree_node_destroy(BinaryTreeNode **treeNodePtr)
{
    if (*treeNodePtr == NULL)
        return;

    (*treeNodePtr)->data = 0;
    (*treeNodePtr)->left_child = NULL;
    (*treeNodePtr)->right_child = NULL;

    free(*treeNodePtr);
    *treeNodePtr = NULL;
}

BinaryTree *binary_tree_create()
{
    BinaryTree *new_tree = (BinaryTree *)malloc(sizeof(BinaryTree));

    if (new_tree == NULL)
        return NULL;

    new_tree->root = NULL;

    return new_tree;
}

bool binary_tree_insertion(BinaryTree *tree, int data)
{
    if (tree == NULL)
        return false;

    if (tree->root == NULL)
    {
        BinaryTreeNode *new_node = binary_tree_node_create(data, NULL, NULL);
        tree->root = new_node;
    }
    else
    {
        return _binary_tree_insertion_recurse(tree->root, data);
    }
}

bool _binary_tree_insertion_recurse(BinaryTreeNode *parent_node, int data)
{
    if (parent_node == NULL)
        false;

    if (data < parent_node->data)
    {
        if (parent_node->left_child != NULL)
        {
            return _binary_tree_insertion_recurse(parent_node->left_child, data);
        }

        BinaryTreeNode *new_node = binary_tree_node_create(data, NULL, NULL);
        parent_node->left_child = new_node;
    }
    else
    {
        if (parent_node->right_child != NULL)
        {
            return _binary_tree_insertion_recurse(parent_node->right_child, data);
        }

        BinaryTreeNode *new_node = binary_tree_node_create(data, NULL, NULL);
        parent_node->right_child = new_node;
    }
}

// ! All possible cases were NOT COVERED
/*   
 *  Let's say we want to delete the node 'x'
 *      Case 1: 'x' has no children --- NEED TO DO
 *      Case 2: 'x' has one child node --- NEED TO DO
 *      Case 3: 'x' has two child node --- COMPLETED
 */  
bool binary_tree_deletion(BinaryTree *tree, int data)
{
    if (tree == NULL || tree->root == NULL)
        return false;

    BinaryTreeNode* node_to_be_deleted = NULL;

    //  Case 1: Removing root node
    if (tree->root->data == data)
    {
        //  Assign new root node
        node_to_be_deleted = tree->root;
        tree->root = tree->root->left_child;

        //  Connect root's child node to it
        BinaryTreeNode *rightmost_child_of_new_root = _binary_tree_find_rightmost_leaf_node(tree->root);
        rightmost_child_of_new_root->right_child = node_to_be_deleted->right_child;
    }
    else
    {
        //  Case 2: Removing internal node
        //  Finding parent node
        BinaryTreeNode* parent_node = _binary_tree_find_parent_node(tree->root, data);
        bool is_left_child = false;

        if(parent_node == NULL) return false;

        if(parent_node->left_child->data == data) is_left_child = true;
        node_to_be_deleted = (is_left_child) ? parent_node->left_child : parent_node->right_child;

        //  Reconnecting child nodes to the tree
        BinaryTreeNode* rightmost_child_of_left_child_node = _binary_tree_find_rightmost_leaf_node(node_to_be_deleted->left_child);
        rightmost_child_of_left_child_node->right_child = node_to_be_deleted->right_child;

        if(is_left_child) {
            parent_node->left_child = node_to_be_deleted->left_child;
        } else {
            parent_node->right_child = node_to_be_deleted->left_child;
        }
    }

    //  Deleting node from memory
    binary_tree_node_destroy(&node_to_be_deleted);
    return true;
}

BinaryTreeNode *_binary_tree_find_rightmost_leaf_node(BinaryTreeNode *node)
{
    if (node == NULL)
        return NULL;

    if (node->right_child == NULL)
        return node;
    else
        return _binary_tree_find_rightmost_leaf_node(node->right_child);
}

BinaryTreeNode *_binary_tree_find_parent_node(BinaryTreeNode *root, int child_node_data)
{
    if (root == NULL || root->data == child_node_data)
        return NULL;

    if (root->left_child->data == child_node_data || root->right_child->data == child_node_data)
        return root;
    else if (child_node_data < root->data)
        return _binary_tree_find_parent_node(root->left_child, child_node_data);
    else
        return _binary_tree_find_parent_node(root->right_child, child_node_data);
}

void binary_tree_inorder_traversal(BinaryTree *tree)
{
    if (tree == NULL || tree->root == NULL)
        return;

    _binary_tree_inorder_traversal_recurse(tree->root);
}

void _binary_tree_inorder_traversal_recurse(BinaryTreeNode *tnode)
{
    if (tnode == NULL)
        return;

    _binary_tree_inorder_traversal_recurse(tnode->left_child);
    printf("%d ", tnode->data);
    _binary_tree_inorder_traversal_recurse(tnode->right_child);
}

void binary_tree_preorder_traversal(BinaryTree *tree)
{
    if (tree == NULL || tree->root == NULL)
        return;

    _binary_tree_preorder_traversal_recurse(tree->root);
}

void _binary_tree_preorder_traversal_recurse(BinaryTreeNode *tnode)
{
    if (tnode == NULL)
        return;

    printf("%d ", tnode->data);
    _binary_tree_preorder_traversal_recurse(tnode->left_child);
    _binary_tree_preorder_traversal_recurse(tnode->right_child);
}

void binary_tree_postorder_traversal(BinaryTree *tree)
{
    if (tree == NULL || tree->root == NULL)
        return;

    _binary_tree_postorder_traversal_recurse(tree->root);
}

void _binary_tree_postorder_traversal_recurse(BinaryTreeNode *tnode)
{
    if (tnode == NULL)
        return;

    _binary_tree_postorder_traversal_recurse(tnode->left_child);
    _binary_tree_postorder_traversal_recurse(tnode->right_child);
    printf("%d ", tnode->data);
}

void binary_tree_print(BinaryTree* tree) {
    if(tree == NULL || tree->root == NULL) return;

    _binary_tree_print_recurse(tree->root);
    printf("\n");    
}

void _binary_tree_print_recurse(BinaryTreeNode* node) {
    if(node == NULL) return;

    printf("Node: %d", node->data);
    printf("--> [");
    if(node->left_child == NULL) {
        printf("NULL, ");
    } else {
        printf("%d, ", node->left_child->data);
    }
    if(node->right_child == NULL) {
        printf("NULL");    
    } else {
        printf("%d", node->right_child->data);
    }
    printf("]\n");

    _binary_tree_print_recurse(node->left_child);
    _binary_tree_print_recurse(node->right_child);
}

void binary_tree_destroy(BinaryTree **treePtr)
{
    if (*treePtr == NULL)
        return;

    if ((*treePtr)->root != NULL)
    {
        _binary_tree_destroy_postorder((*treePtr)->root);
    }

    free(*treePtr);
    *treePtr = NULL;
}
void _binary_tree_destroy_postorder(BinaryTreeNode *tnode)
{
    if (tnode == NULL)
        return;

    _binary_tree_destroy_postorder(tnode->left_child);
    _binary_tree_destroy_postorder(tnode->right_child);

    free(tnode);
    tnode = NULL;
}
