#include <stdio.h>
#include <stdlib.h>

// The actual implementation in C for the matrix divide-and-conquer algorithm might be a little excessive for an intro algorithm


int** square_matrix_multiply(int **a, int **b, int n) {
    int **c = (int**)malloc(n * sizeof(int*));
    for (int i = 0; n > i; i++) {
        c[i] = (int*)malloc(n * sizeof(int));

        for (int j = 0; j < n; j++) {
            c[i][j] += a[i][j] * b[j][i];
        }
    }
    
    return c;
}

// Inefficient due to the overhead of malloc but works
int** slice(int **a, int rows, int cols, int n) {
    int **c = (int**)malloc(n + sizeof(int*));

    for (int i = 0; n > i; i++) {
        c[i] = (int*)malloc(cols * sizeof(int));

        for (int j = 0; n > j; j++) {
            c[i][j] = a[rows + i][cols + j];
        }
    }

    return c;
}

int** merge(int **c11, int **c12, int **c21, int **c22, int n) {
    int size = n * 2;

    int **c = (int**)malloc(size * sizeof(int*));

    for (int i = 0; size > i; i++) {
        c[i] = (int*)malloc(size * sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c[i][j] = c11[i][j];
            c[i][j + n] = c12[i][j];
            c[i + n][j] = c21[i][j];
            c[i + n][j + n] = c22[i][j]; 
        }
    }

    return c;
}

int** add(int **a, int **b, int n) {
    int **c = (int**)malloc(n * sizeof(int*));

    for (int i = 0; i < n; i++) {
        c[i] = (int*)malloc(n * sizeof(int));

        for (int j = 0; j < n; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }

    return c;
}

void free_matrix(int **m, int n) {
    if (m == NULL) {
        return;
    }

    for (int i = 0; i < n; i++) {
        free(m[i]);
    }

    free(m);
}

int** square_matrix_multiply_recursive(int **a, int **b, int n) {
    if (n == 1) {
        int **c = (int**)malloc(sizeof(int*));
        c[0] = (int*)malloc(sizeof(int));
        c[0][0] = a[0][0] * b[0][0];

        return c;

    } else {
        int m = n / 2;

        int **a11 = slice(a, 0, 0, m);
        int **a12 = slice(a, 0, m, m);
        int **a21 = slice(a, m, 0, m);
        int **a22 = slice(a, m, m, m);

        int **b11 = slice(b, 0, 0, m);
        int **b12 = slice(b, 0, m, m);
        int **b21 = slice(b, m, 0, m);
        int **b22 = slice(b, m, m, m);

        int **c11 = add(square_matrix_multiply(a11, b11, m), square_matrix_multiply(a12, b21, m), m);
        int **c12 = add(square_matrix_multiply(a11, b12, m), square_matrix_multiply(a12, b22, m), m);
        int **c21 = add(square_matrix_multiply(a21, b11, m), square_matrix_multiply(a22, b21, m), m);
        int **c22 = add(square_matrix_multiply(a21, b12, m), square_matrix_multiply(a22, b22, m), m);

        free_matrix(a11, m);
        free_matrix(a12, m);
        free_matrix(a21, m);
        free_matrix(a22, m);

        free_matrix(b11, m);
        free_matrix(b12, m);
        free_matrix(b21, m);
        free_matrix(b22, m);

        int **c = merge(c11, c12, c21, c22, m);

        free_matrix(c11, m);
        free_matrix(c12, m);
        free_matrix(c21, m);
        free_matrix(c22, m);

        return c;
    }
}

int main() {
    int **a = (int**)malloc(2 * sizeof(int*));
    int **b = (int**)malloc(2 * sizeof(int*));
    for (int i = 0; i < 2; i++) {
        a[i] = (int*)malloc(2 * sizeof(int));
        b[i] = (int*)malloc(2 * sizeof(int));
    }
    
    a[0][0] = 1;
    a[0][1] = 2;
    a[1][0] = 3;
    a[1][1] = 4;

    b[0][0] = 5;
    b[0][1] = 6;
    b[1][0] = 7;
    b[1][1] = 8;

    int **c = square_matrix_multiply_recursive(a, b, 2);

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", c[i][j]);
        }
    }

    printf("\n");

    for (int i = 0; i < 2; i++) {
        free(c[i]);
        free(a[i]);
        free(b[i]);
    }
    free(a);
    free(b);
    free(c);

    getchar();
}

