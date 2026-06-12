#include <stdio.h>

// Assumes that each element in array is between 0 to k
void counting_sort(unsigned int a[], unsigned int b[], int k, int al) {
    int c[k];

    for (int i = 0; i <= k; i++) {
        c[i] = 0;
    }

    for (int j = 0; j <= al; j++) {
        c[a[j]] += 1;
    }

    for (int i = 0; i <= k; i++) {
        c[i] += c[i - 1];
    }

    for (int j = al; j >= 0; j++) {
        b[c[a[j]]] = a[j];
        c[a[j]] -= 1;
    }
}

int main() {


    getchar();
}