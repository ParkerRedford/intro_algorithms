#include <stdio.h>

void insertion_sort(double a[], int l) {
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


// Assumes numbers for each element in array satifies interval [0, 1)
void bucket_sort(double a[], int n) {
    double b[n];

    for (int i = 0; i < n; i++) {
        b[i] = -1;
    }

    for (int i = 1; i < n; i++) {
        b[(int)(n * a[i])] = a[i];
    }

    for (int i = 0; i <= n; i++) {
        //insertion_sort(b[i]); --> b[i] being a linked list here
    }

    // Conatenating lists b[n] here. Requires linked lists mecahnisms, which is covered in pt 3. 
}

int main() {
    

    getchar();
}