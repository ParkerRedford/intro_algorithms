#include <stdio.h>

int left(int i) {
    return 2 * i + 1;
}

int right(int i) {
    return 2 * i + 2;
}

void max_heapify(int a[], int i, int heap_size) {
    int l = left(i);
    int r = right(i);
    int largest = 0;

    if (l <= heap_size && a[l] > a[i]) {
        largest = l;
    } else {
        largest = i;
    }
    if (r <= heap_size && a[r] > a[largest]) {
        largest = r;
    }
    if (largest != i) {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;

        int b = a[i];
        int c = a[largest];

        max_heapify(a, largest, heap_size);
    }
}

void build_max_heap(int a[], int length) {
    int heap_size = length - 1;
    for (int i = (length / 2) - 1; i >= 0; i--) {
        max_heapify(a, i, heap_size);
    }
}

void heapsort(int a[], int l) {
    int heap_size = l;
    build_max_heap(a, l);
    for (int i = l; i >= 1; i--) {
        int temp = a[i];
        a[i] = a[0];
        a[0] = temp;
        heap_size--;

        int b = a[i];
        int c = a[0];

        max_heapify(a, 0, heap_size);
    }
}

int main() {
    int a[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};

    for (int i = 0; i < 10; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    heapsort(a, 9);
    for (int i = 0; i < 10; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    getchar();
}