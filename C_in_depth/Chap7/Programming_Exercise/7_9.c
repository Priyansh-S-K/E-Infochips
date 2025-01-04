//Write a program to find out whether a matrix is symmetric or not. A matrix is symmetric iftranspose
//of the matrix is equal to the matrix.
#include <stdio.h>

#define MAX 10

int isSymmetric(int matrix[MAX][MAX], int n) {
    // Check if the matrix is equal to its transpose
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                return 0; // Not symmetric
            }
        }
    }
    return 1; // Symmetric
}

int main() {
    int matrix[MAX][MAX], n;

    // Input matrix size
    printf("Enter the size of the matrix (n x n): ");
    scanf("%d", &n);

    // Input matrix elements
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Check and print whether the matrix is symmetric
    if (isSymmetric(matrix, n)) {
        printf("The matrix is symmetric.\n");
    } else {
        printf("The matrix is not symmetric.\n");
    }

    return 0;
}
