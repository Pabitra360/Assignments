#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct DLLNode {
    int data;
    struct DLLNode* prev;
    struct DLLNode* next;
};

struct DLLNode* head = NULL;
struct DLLNode* prev = NULL;

void inorder_traversal(struct TreeNode* root) {
    if (root == NULL)
        return;

    inorder_traversal(root->left);

    struct DLLNode* new_node = (struct DLLNode*)malloc(sizeof(struct DLLNode));
    new_node->data = root->data;
    new_node->next = NULL;

    if (prev == NULL) {
        head = new_node;
        new_node->prev = NULL;
    } else {
        prev->next = new_node;
        new_node->prev = prev;
    }
    prev = new_node;

    inorder_traversal(root->right);
}

void display() {
    struct DLLNode* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Helper function to create a new tree node
struct TreeNode* create_tree_node(int data) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main() {
    struct TreeNode* root = create_tree_node(4);
    root->left = create_tree_node(2);
    root->right = create_tree_node(6);
    root->left->left = create_tree_node(1);
    root->left->right = create_tree_node(3);
    root->right->left = create_tree_node(5);
    root->right->right = create_tree_node(7);

    inorder_traversal(root);
    printf("Doubly Linked List from Binary Tree:\n");
    display();  // Output: 1 2 3 4 5 6 7

    return 0;
}

