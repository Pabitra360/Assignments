// WAP to perform insertion and deletion of elements at different position of a doubly circular linked list
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* last = NULL;

void insert_at_beginning(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    if (!last) {
        last = new_node;
        new_node->next = new_node->prev = new_node;
    } else {
        new_node->next = last->next;
        new_node->prev = last;
        last->next->prev = new_node;
        last->next = new_node;
    }
}

void insert_at_end(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    if (!last) {
        last = new_node;
        new_node->next = new_node->prev = new_node;
    } else {
        new_node->next = last->next;
        new_node->prev = last;
        last->next->prev = new_node;
        last->next = new_node;
        last = new_node;
    }
}

void insert_at_position(int data, int pos) {
    if (pos == 1) {
        insert_at_beginning(data);
        return;
    }
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    struct Node* temp = last->next;
    for (int i = 1; i < pos - 1 && temp != last; i++) {
        temp = temp->next;
    }
    new_node->next = temp->next;
    new_node->prev = temp;
    temp->next->prev = new_node;
    temp->next = new_node;
    if (temp == last) {
        last = new_node;
    }
}

void delete_at_beginning() {
    if (!last) return;
    struct Node* temp = last->next;
    if (last == last->next) {
        free(last);
        last = NULL;
    } else {
        last->next = temp->next;
        temp->next->prev = last;
        free(temp);
    }
}

void delete_at_end() {
    if (!last) return;
    struct Node* temp = last;
    if (last == last->next) {
        free(last);
        last = NULL;
    } else {
        last->prev->next = last->next;
        last->next->prev = last->prev;
        last = last->prev;
        free(temp);
    }
}

void delete_at_position(int pos) {
    if (!last) return;
    if (pos == 1) {
        delete_at_beginning();
        return;
    }
    struct Node* temp = last->next;
    for (int i = 1; i < pos - 1 && temp != last; i++) {
        temp = temp->next;
    }
    struct Node* to_delete = temp->next;
    temp->next = to_delete->next;
    to_delete->next->prev = temp;
    if (to_delete == last) {
        last = temp;
    }
    free(to_delete);
}

void display() {
    if (!last) return;
    struct Node* temp = last->next;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
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

