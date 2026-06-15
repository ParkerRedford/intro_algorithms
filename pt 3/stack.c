#include <stdio.h>
#include <stdbool.h>

bool stack_empty(int s[], int* top) {
    if (*top == -1) {
        return true;
    } else {
        return false;
    }
}

void push(int s[], int* top, int x) {
    *top += 1;
    s[*top] = x;
}

int pop(int s[], int* top) {
    if (stack_empty(s, top)) {
        return printf("%s", "underflow");
    } else {
        *top -= 1;
        return s[*top + 1];
    }
}

int main() {
    int s[] = {15, 6, 2, 9, 0, 0, 0};
    int top = 3;
    int l = 7;

    printf("Top before: %d\n", top);
    for (int i = 0; i < l; i++) {
        printf("%d ", s[i]);
    }
    printf("\n");

    push(s, &top, 17);
    push(s, &top, 3);

    pop(s, &top);

    for (int i = 0; i < l; i++) {
        printf("%d ", s[i]);
    }
    printf("\n");

    printf("Top after: %d\n", top);

    getchar();
}