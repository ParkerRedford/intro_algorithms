#include <stdio.h>

void enqueue(int q[], int* tail, int* length, int* x) {
    q[*tail] = *x;
    if (*tail == *length) {
        *tail = 0;
    } else {
        *tail += 1;
    }
}

int dequeue(int q[], int* head, int* length) {
    int x = q[*head];
    if(*head == *length) {
        *head = 1;
    } else {
        *head += 1;
    }

    return x;
}

int main() {


    getchar();
}