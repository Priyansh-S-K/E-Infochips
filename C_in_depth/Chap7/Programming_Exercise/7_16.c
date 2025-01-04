// Write a program to reverse the columns of a matrix
#include <stdio.h>

#define MAX 10

void reverseColumns(int matrix[MAX][MAX], int n, int m) {
    for (int j = 0; j < m; j++) {
        int top = 0, bottom = n - 1;
        while (top < bottom) {
            // Swap elements in the column
            int temp = matrix[top][j];
            matrix[top][j] = matrix[bottom][j];
            matrix[bottom][j] = temp;

            top++;
            bottom--;
        }
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

    // Reverse the columns of the matrix
    reverseColumns(matrix, n, m);

    // Print the matrix after reversing columns
    printf("Matrix after reversing columns:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
