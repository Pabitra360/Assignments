// WAP to remove a particular character from a doubly linked lists
#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL;

void insert_at_end(char data) {
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

void remove_character(char char_to_remove) {
    struct Node* temp = head;
    while (temp) {
        if (temp->data == char_to_remove) {
            if (temp->prev) {
                temp->prev->next = temp->next;
            }
            if (temp->next) {
                temp->next->prev = temp->prev;
            }
            if (temp == head) {
                head = temp->next;
            }
            struct Node* to_delete = temp;
            temp = temp->next;
            free(to_delete);
        } else {
            temp = temp->next;
        }
    }
}

void display() {
    struct Node* temp = head;
    while (temp) {
        printf("%c ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    insert_at_end('a');
    insert_at_end('b');
    insert_at_end('c');
    insert_at_end('b');
    insert_at_end('d');
    display();  // Output: a b c b d
    remove_character('b');
    display();  // Output: a c d
    return 0;
}
