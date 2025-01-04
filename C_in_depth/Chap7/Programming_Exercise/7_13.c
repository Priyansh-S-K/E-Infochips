//Write a program to enter a square matrix of odd size and then check whether it is a magic matrix or not.

#include <stdio.h>

#define MAX 10

int isMagicMatrix(int matrix[MAX][MAX], int n) {
    int sum = 0;
    
    // Calculate the sum of the first row (as reference)
    for (int i = 0; i < n; i++) {
        sum += matrix[0][i];
    }

    // Check the sum of all rows
    for (int i = 1; i < n; i++) {
        int rowSum = 0;
        for (int j = 0; j < n; j++) {
            rowSum += matrix[i][j];
        }
        if (rowSum != sum) {
            return 0; // Not a magic matrix
        }
    }

    // Check the sum of all columns
    for (int j = 0; j < n; j++) {
        int colSum = 0;
        for (int i = 0; i < n; i++) {
            colSum += matrix[i][j];
        }
        if (colSum != sum) {
            return 0; // Not a magic matrix
        }
    }

    // Check the sum of the principal diagonal
    int principalDiagonalSum = 0;
    for (int i = 0; i < n; i++) {
        principalDiagonalSum += matrix[i][i];
    }
    if (principalDiagonalSum != sum) {
        return 0; // Not a magic matrix
    }

    // Check the sum of the secondary diagonal
    int secondaryDiagonalSum = 0;
    for (int i = 0; i < n; i++) {
        secondaryDiagonalSum += matrix[i][n - i - 1];
    }
    if (secondaryDiagonalSum != sum) {
        return 0; // Not a magic matrix
    }

    return 1; // It is a magic matrix
}

int main() {
    int matrix[MAX][MAX], n;

    // Input matrix size
    printf("Enter the size of the matrix (odd number n x n): ");
    scanf("%d", &n);

    // Ensure matrix size is odd
    if (n % 2 == 0) {
        printf("The matrix size must be odd.\n");
        return 1;
    }

    // Input matrix elements
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Check and print whether it is a magic matrix
    if (isMagicMatrix(matrix, n)) {
        printf("The matrix is a magic matrix.\n");
    } else {
        printf("The matrix is not a magic matrix.\n");
    }

    return 0;
}
