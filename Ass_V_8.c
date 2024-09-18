// WAP to divide doubly linked list from middle and rejoin them in reverse manner
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL;

void insert_at_end(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    if (!head) {
        new_node->prev = NULL;
        head = new_node;
    } else {
        struct Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->prev = temp;
    }
}

struct Node* reverse_list(struct Node* head) {
    struct Node* temp = NULL;
    struct Node* current = head;
    while (current) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp) {
        head = temp->prev;
    }
    return head;
}

struct Node* find_middle() {
    struct Node* slow = head;
    struct Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void divide_and_reverse() {
    if (!head || !head->next) return;

    struct Node* mid = find_middle();

    struct Node* second_half = mid->next;
    mid->next = NULL;
    if (second_half) {
        second_half->prev = NULL;
    }

    struct Node* first_half = reverse_list(head);
    second_half = reverse_list(second_half);

    struct Node* temp = first_half;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = second_half;
    if (second_half) {
        second_half->prev = temp;
    }

    head = first_half;
}

void display() {
    struct Node* temp = head;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    insert_at_end(1);
    insert_at_end(2);
    insert_at_end(3);
    insert_at_end(4);
    insert_at_end(5);
    insert_at_end(6);

    printf("Original List:\n");
    display();  // Output: 1 2 3 4 5 6

    divide_and_reverse();

    printf("After Dividing and Reversing:\n");
    display();  // Output: 3 2 1 6 5 4

    return 0;
}
