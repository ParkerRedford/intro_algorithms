#include <stdio.h>
#include <limits.h>
#include "heapsort.h"

int heap_extract_max(int a[], int heap_size) {
    if (heap_size < 0) {
        printf("heap overflow");
        return -1;
    }

    int max = a[0];
    a[0] = a[heap_size];
    heap_size--;
    max_heapify(a, 0, heap_size);

    return max;
}

int parent(int i) {
    return i / 2;
}

void heap_increase__key(int a[], int i, int key) {
    if (key < a[i]) {
        printf("new key is smaller than current key");
        return -1;
    }

    a[i] = key;
    while (i > 0 && a[parent(i)] < a[i]) {
        int temp = a[i];
        a[i] = a[parent(i)];
        a[parent(i)] = temp;

        i = parent(i / 2);
    }
}

void max_heap_insert(int a[], int key, int heap_size) {
    heap_size++;
    a[heap_size] = INT_MIN;
    heap_increase__key(a, heap_size, key);
}

int main () {
    

    getchar();
}