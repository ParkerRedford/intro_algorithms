#include <stdio.h>

// Book represented nodes as arrays, but I'll use structs here
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* pref;
} Node;

Node* list_search(Node* head, int key) {
    Node* x = head;

    while (x != NULL && x->data != key) {
        x = x->next;
    }

    return x;
}

void list_insert(Node** head, Node* x) {
    x->next = *head;

    if (*head != NULL) {
        (*head)->pref = x;
    }

    *head = x;
    x->pref = NULL;
}

void list_delete(Node** head, Node* x) {
    if (x->pref != NULL) {
        x->pref->next = x->next;
    } else {
        *head = x->next;
        x->next->pref = x->pref;
    }
    if (x->next != NULL) {
        x->next->pref = x->pref;
    }
}

int main() {


    getchar();
}
