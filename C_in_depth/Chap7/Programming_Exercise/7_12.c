//Write a program to find out the sum of elements of principal and secondary diagonals of a square matrix.

#include <stdio.h>

#define MAX 10

void findDiagonalSums(int matrix[MAX][MAX], int n) {
    int principalDiagonalSum = 0, secondaryDiagonalSum = 0;

    for (int i = 0; i < n; i++) {
        principalDiagonalSum += matrix[i][i];                // Principal diagonal
        secondaryDiagonalSum += matrix[i][n - i - 1];        // Secondary diagonal
    }

    printf("Sum of Principal Diagonal: %d\n", principalDiagonalSum);
    printf("Sum of Secondary Diagonal: %d\n", secondaryDiagonalSum);
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

    // Find and print the diagonal sums
    findDiagonalSums(matrix, n);

    return 0;
}
