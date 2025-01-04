//Write a program to sort the elements of a matrix (i) row-wise (ii) column-wise
#include <stdio.h>

#define MAX 10

void sortRowWise(int matrix[MAX][MAX], int n, int m) {
    for (int i = 0; i < n; i++) {
        // Sorting each row using Bubble Sort
        for (int j = 0; j < m - 1; j++) {
            for (int k = 0; k < m - j - 1; k++) {
                if (matrix[i][k] > matrix[i][k + 1]) {
                    int temp = matrix[i][k];
                    matrix[i][k] = matrix[i][k + 1];
                    matrix[i][k + 1] = temp;
                }
            }
        }
    }
}

void sortColumnWise(int matrix[MAX][MAX], int n, int m) {
    for (int j = 0; j < m; j++) {
        // Sorting each column using Bubble Sort
        for (int i = 0; i < n - 1; i++) {
            for (int k = 0; k < n - i - 1; k++) {
                if (matrix[k][j] > matrix[k + 1][j]) {
                    int temp = matrix[k][j];
                    matrix[k][j] = matrix[k + 1][j];
                    matrix[k + 1][j] = temp;
                }
            }
        }
    }
}

void printMatrix(int matrix[MAX][MAX], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix[MAX][MAX], n, m;

    // Input matrix size (n x m)
    printf("Enter the number of rows (n): ");
    scanf("%d", &n);
    printf("Enter the number of columns (m): ");
    scanf("%d", &m);

    // Input matrix elements
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Sort the matrix row-wise
    sortRowWise(matrix, n, m);
    printf("Matrix after sorting row-wise:\n");
    printMatrix(matrix, n, m);

    // Sort the matrix column-wise
    sortColumnWise(matrix, n, m);
    printf("Matrix after sorting column-wise:\n");
    printMatrix(matrix, n, m);

    return 0;
}
