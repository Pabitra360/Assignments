// WAP to perform insertion and deletion of elements at different position of singly circular linked list

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* last = NULL;

void insert_at_beginning(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    if (!last) {
        last = new_node;
        last->next = last;
    } else {
        new_node->next = last->next;
        last->next = new_node;
    }
}

void insert_at_end(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    if (!last) {
        last = new_node;
        last->next = last;
    } else {
        new_node->next = last->next;
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
    struct Node* current = last->next;
    for (int i = 0; i < pos - 2; i++) {
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
    if (current == last) {
        last = new_node;
    }
}

void delete_at_beginning() {
    if (!last) return;
    struct Node* temp = last->next;
    if (last == last->next) {
        last = NULL;
    } else {
        last->next = temp->next;
    }
    free(temp);
}

void delete_at_end() {
    if (!last) return;
    struct Node* current = last->next;
    if (last == last->next) {
        free(last);
        last = NULL;
    } else {
        while (current->next != last) {
            current = current->next;
        }
        current->next = last->next;
        free(last);
        last = current;
    }
}

void delete_at_position(int pos) {
    if (!last) return;
    if (pos == 1) {
        delete_at_beginning();
        return;
    }
    struct Node* current = last->next;
    for (int i = 0; i < pos - 2; i++) {
        current = current->next;
    }
    struct Node* temp = current->next;
    current->next = temp->next;
    if (temp == last) {
        last = current;
    }
    free(temp);
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
