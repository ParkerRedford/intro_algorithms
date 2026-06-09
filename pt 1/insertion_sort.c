#include <stdio.h>

void insertion_sort(int a[], int l) {
    for (int i = 1; i < l; i++) {
        int k = a[i];

        int j = i - 1;
        while (j > -1 && a[j] > k) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = k;
    }
}

int main() {
    int a[] = {5, 2, 4, 6, 1, 3};
    int l = 6;

    for (int i = 0; i < l; i++) {
        printf("%d", a[i]);
    }
    printf("\n");

    insertion_sort(a, l);
    for (int i = 0; i < l; i++) {
        printf("%d", a[i]);
    }
    printf("\n");

    getchar();
}