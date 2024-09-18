#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* last = NULL;

void add(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    if (!last) {
        last = new_node;
        last->next = last->prev = last;
    } else {
        new_node->next = last->next;  // Corrected syntax
        new_node->prev = last;        // Corrected syntax
        last->next->prev = new_node;  // Corrected syntax
        last->next = new_node;
        last = new_node;
    }
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
    add(1);
    add(2);
    add(3);
    display();
    return 0;
}
