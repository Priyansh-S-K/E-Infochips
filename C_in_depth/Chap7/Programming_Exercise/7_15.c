//Write a program to reverse the rows of a matrix

#include <stdio.h>

#define MAX 10

void reverseRows(int matrix[MAX][MAX], int n, int m) {
    for (int i = 0; i < n; i++) {
        int left = 0, right = m - 1;
        while (left < right) {
            // Swap elements in the row
            int temp = matrix[i][left];
            matrix[i][left] = matrix[i][right];
            matrix[i][right] = temp;

            left++;
            right--;
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

    // Reverse the rows of the matrix
    reverseRows(matrix, n, m);

    // Print the matrix after reversing rows
    printf("Matrix after reversing rows:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
