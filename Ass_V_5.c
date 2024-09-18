// WAP to perform insertion and deletion of elements at different position of a doubly linked list

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

void insert_at_beginning(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = head;
    if (head) {
        head->prev = new_node;
    }
    head = new_node;
}

void insert_at_end(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    if (!head) {
        new_node->prev = NULL;
        head = new_node;
        return;
    }
    struct Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->prev = temp;
}

void insert_at_position(int data, int pos) {
    if (pos == 1) {
        insert_at_beginning(data);
        return;
    }
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    struct Node* temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }
    if (!temp) return;
    new_node->next = temp->next;
    if (temp->next) {
        temp->next->prev = new_node;
    }
    temp->next = new_node;
    new_node->prev = temp;
}

void delete_at_beginning() {
    if (!head) return;
    struct Node* temp = head;
    head = head->next;
    if (head) {
        head->prev = NULL;
    }
    free(temp);
}

void delete_at_end() {
    if (!head) return;
    struct Node* temp = head;
    if (!temp->next) {
        free(temp);
        head = NULL;
        return;
    }
    while (temp->next) {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
}

void delete_at_position(int pos) {
    if (!head) return;
    if (pos == 1) {
        delete_at_beginning();
        return;
    }
    struct Node* temp = head;
    for (int i = 1; temp != NULL && i < pos; i++) {
        temp = temp->next;
    }
    if (!temp) return;
    if (temp->next) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev) {
        temp->prev->next = temp->next;
    }
    free(temp);
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
    display();
    insert_at_position(4, 2);
    display();
    delete_at_position(2);
    display();
    return 0;
}
