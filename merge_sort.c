#include <stdio.h>
#include <limits.h>

void merge(int a[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    int left[n1 + 1];
    int right[n2 + 1];

    for (int i = 0; n1 >= i; i++) {
        int k = p + i;
        left[i] = a[p + i];
    }

    for (int j = 0; n2 >= j; j++) {
        int k = q + j -1;
        right[j] = a[q + j + 1];
    }

    left[n1] = INT_MAX;
    right[n2] = INT_MAX;


    int i = 0;
    int j = 0;

    for (int k = p; k <= r; k++) {
        if (left[i] <= right[j]) {
            a[k] = left[i];
            i++;
        } else { 
            a[k] = right[j];
            j++;
        }
    }
}

void merge_sort(int a[], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        merge_sort(a, p, q);
        merge_sort(a, q + 1, r);
        merge(a, p, q, r);
    }

}

int main() {
    int a[] = {5, 2, 4, 7, 1, 3, 2, 6};
    int l = 8;

    for (int i = 0; i < l; i++) {
        printf("%d", a[i]);
    }
    printf("\n");

    merge_sort(a, 0, l - 1);
    for (int i = 0; i < l; i++) {
        printf("%d", a[i]);
    }
    printf("\n");

    getchar();
}