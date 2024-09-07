#include "../../../include/data-structures/non-linear-ds/binary_tree.h"

BinaryTreeNode* binary_tree_node_create(int data, BinaryTreeNode* left_child, BinaryTreeNode* right_child) {
    BinaryTreeNode* new_node = (BinaryTreeNode*) malloc(sizeof(BinaryTreeNode));

    if(new_node == NULL) return NULL;

    new_node->data = data;
    new_node->left_child = left_child;
    new_node->right_child = right_child;

    return new_node;
}
void binary_tree_node_destroy(BinaryTreeNode** bt_nodeptr) {
    if(*bt_nodeptr == NULL) return;

    (*bt_nodeptr)->data = 0;
    (*bt_nodeptr)->left_child = NULL;
    (*bt_nodeptr)->right_child = NULL;

    free(*bt_nodeptr);
    *bt_nodeptr = NULL;
}

BinaryTree* binary_tree_create() {
    BinaryTree* bt = (BinaryTree*) malloc(sizeof(BinaryTree));

    if(bt == NULL) return NULL;

    bt->root = NULL;

    return bt;
}

bool binary_tree_insert_by_value(BinaryTree* bt, int data) {
    if(bt == NULL) return false;

    if(bt->root == NULL) {
        BinaryTreeNode* new_node = binary_tree_node_create(data, NULL, NULL);

        if(new_node == NULL) return false;

        bt->root = new_node;
    }

    return _binary_tree_insert_by_value_recurse(bt->root, data);
}
bool _binary_tree_insert_by_value_recurse(BinaryTreeNode* btnode, int data) {
    if(btnode == NULL || btnode->data == data) return false;

    if(data < btnode->data) {
        if(btnode->left_child != NULL) {
            return _binary_tree_insert_by_value_recurse(btnode->left_child, data);
        }

        BinaryTreeNode* new_node = binary_tree_node_create(data, NULL, NULL);
        btnode->left_child = new_node;
        return true;
    }
    
    if(btnode->right_child != NULL) {
        return _binary_tree_insert_by_value_recurse(btnode->right_child, data);
    }
    
    BinaryTreeNode* new_node = binary_tree_node_create(data, NULL, NULL);
    btnode->right_child = new_node;
    return true;
}

bool binary_tree_insert_by_level_order(BinaryTree* bt, int data) {
    if(bt == NULL) return false;

    if(bt->root == NULL) {
        BinaryTreeNode* new_node = binary_tree_node_create(data, NULL, NULL);
        bt->root = new_node;
        return true;
    }

    Queue* q = queue_create();
    bool result = _binary_tree_insert_by_level_order_recurse(bt->root, q, data);

    //  Remove binary tree nodes from queue; Prevents them from getting deleted, when queue is cleared
    while(!queue_is_empty(q)) queue_dequeue(q); 
    queue_destroy(&q);

    return result;
}
bool _binary_tree_insert_by_level_order_recurse(BinaryTreeNode* btnode, Queue* q, int data) {
    if(btnode == NULL) return false;

    if(btnode->left_child == NULL) {
        BinaryTreeNode* new_node = binary_tree_node_create(data, NULL, NULL);
        btnode->left_child = new_node;
        return true;
    } else if(btnode->right_child == NULL) {
        BinaryTreeNode* new_node = binary_tree_node_create(data, NULL, NULL);
        btnode->right_child = new_node;
        return true;
    }

    queue_enqueue(q, btnode->left_child);
    queue_enqueue(q, btnode->right_child);
    // binary_tree_queue_print(q);
    return _binary_tree_insert_by_level_order_recurse(queue_dequeue(q), q, data);
}

bool binary_tree_delete_with_next_smallest(BinaryTree* bt, int data) {
    if(bt == NULL || bt->root == NULL) return false;

    // 1. Finding parent node
    BinaryTreeNode* parent = _binary_tree_find_parent_node(bt->root, data);
    BinaryTreeNode* node_to_be_deleted = NULL;
    BinaryTreeNode* next_smallest_parent = NULL;
    bool child_is_left = false;

    //  If parent->data = data, removing root node
    if(parent->data == data) {
        node_to_be_deleted = parent;
    } else { // 2. Finding child node
        if(parent->left_child != NULL && parent->left_child->data == data) {
            node_to_be_deleted = parent->left_child;
            child_is_left = true;
        }
        else if(parent->right_child != NULL) {
            node_to_be_deleted = parent->right_child;
        }
    }

    // 3. Finding next smallest node
    if(node_to_be_deleted->left_child != NULL) next_smallest_parent = _binary_tree_find_next_smallest_parent(node_to_be_deleted->left_child);

    if(next_smallest_parent != NULL && next_smallest_parent->right_child != NULL) {
        node_to_be_deleted->data = next_smallest_parent->right_child->data;
        node_to_be_deleted = next_smallest_parent->right_child;
        next_smallest_parent->right_child = NULL;
    } else { // Deleting leaf node
        if(child_is_left) parent->left_child = NULL;
        else parent->right_child = NULL;
    }

    binary_tree_node_destroy(&node_to_be_deleted);
    
    return true;
}
BinaryTreeNode* _binary_tree_find_parent_node(BinaryTreeNode* btnode, int data) {
    if(btnode == NULL) {
        return NULL;
    }


    if(data == btnode->data || 
    (btnode->left_child != NULL && btnode->left_child->data == data) || 
    (btnode->right_child != NULL && btnode->right_child->data == data)) {
        return btnode;
    } else if(data < btnode->data) {
        return _binary_tree_find_parent_node(btnode->left_child, data);
    }

    return _binary_tree_find_parent_node(btnode->right_child, data);
}
BinaryTreeNode* _binary_tree_find_next_smallest_parent(BinaryTreeNode* btnode) {
    if(btnode == NULL || btnode->right_child == NULL) return NULL;

    if(btnode->right_child->right_child == NULL) return btnode;
    return _binary_tree_find_next_smallest_parent(btnode->right_child);
}

bool binary_tree_delete_with_next_biggest(BinaryTree* bt, int data) {
    if(bt == NULL || bt->root == NULL) {

    }
}
BinaryTreeNode* _binary_tree_find_next_biggest_parent(BinaryTreeNode* btnode); 

void binary_tree_inorder(BinaryTree* bt) {
    if(bt == NULL || bt->root == NULL) return;

    _binary_tree_inorder_traversal(bt->root);
}
void _binary_tree_inorder_traversal(BinaryTreeNode* btnode) {
    if(btnode == NULL) return;

    _binary_tree_inorder_traversal(btnode->left_child);
    printf("%d ", btnode->data);
    _binary_tree_inorder_traversal(btnode->right_child);
}

void binary_tree_preorder(BinaryTree* bt) {
    if(bt == NULL || bt->root == NULL) return;

    _binary_tree_preorder_traversal(bt->root);
}
void _binary_tree_preorder_traversal(BinaryTreeNode* btnode) {
    if(btnode == NULL) return;

    printf("%d ", btnode->data);
    _binary_tree_preorder_traversal(btnode->left_child);
    _binary_tree_preorder_traversal(btnode->right_child);
}

void binary_tree_postorder(BinaryTree* bt) {
    if(bt == NULL || bt->root == NULL) return;

    _binary_tree_postorder_traversal(bt->root);
}
void _binary_tree_postorder_traversal(BinaryTreeNode* btnode) {
    if(btnode == NULL) return;

    _binary_tree_postorder_traversal(btnode->left_child);
    _binary_tree_postorder_traversal(btnode->right_child);
    printf("%d ", btnode->data);
}

void binary_tree_print(BinaryTree* bt) {
    if(bt == NULL || bt->root == NULL) return;

    _binary_tree_print_recurse(bt->root, 1);
    printf("\n");
}
void _binary_tree_print_recurse(BinaryTreeNode* btnode, int level) {
    if(btnode == NULL) return;

    for(int i = 1; i < level; i++)
        printf("\t");

    printf("|-- %d\n", btnode->data);

    _binary_tree_print_recurse(btnode->left_child, level+1);
    _binary_tree_print_recurse(btnode->right_child, level+1);
}

void binary_tree_destroy(BinaryTree** btptr) {
    if(*btptr == NULL) return;

    if((*btptr)->root != NULL)
        _binary_tree_destroy_recurse((*btptr)->root);

    free(*btptr);
    *btptr = NULL;
}
void _binary_tree_destroy_recurse(BinaryTreeNode* btnode) {
    if(btnode == NULL) return;
    
    _binary_tree_destroy_recurse(btnode->left_child);
    _binary_tree_destroy_recurse(btnode->right_child);

    binary_tree_node_destroy(&btnode);
}

//  ! Debugging functions
void binary_tree_queue_print(Queue* q) {
    if(q == NULL || queue_is_empty(q)) return;

    QueueNode* cur = q->front;

    printf("[");
    while(cur != NULL) {
        BinaryTreeNode* cur_btnode = cur->data;

        printf("%d", cur_btnode->data);

        if(cur->next != NULL)
            printf(", ");
        
        cur = cur->next;
    }
    printf("]");
    printf("\n");
}

