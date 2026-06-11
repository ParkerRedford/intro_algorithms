#include <stdio.h>

void quicksort(int a[], int p, int r) {
    if (p < r) {
        int q = partition(a, p, r);
        quicksort(a, p, q - 1);
        quicksort(a, q + 1, r);
    }
}

int partition(int a[], int p, int r) {
    int x = a[r];
    int i = p - 1;

    for (int j = p; j <= r - 1; j++) {
        if (a[j] <= x) {
            i++;

            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

     int temp = a[i + 1];
        a[i + 1] = a[r];
        a[r] = temp;

    return i + 1;
}

int main() {
    int a[] = {2, 8, 7, 1, 3, 5, 6, 4};
    int l = 8;

    for (int i = 0; i < l; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    quicksort(a, 0, l - 1);
    for (int i = 0; i < l; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    getchar();
}

