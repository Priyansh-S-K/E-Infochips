// Write a program to store all the elements of a 2-D array in a 1-D array row-wise.
#include <stdio.h>

#define MAX 10

void storeRowWise(int matrix[MAX][MAX], int n, int m, int arr[]) {
    int k = 0;
    
    // Store the elements row-wise in the 1-D array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr[k++] = matrix[i][j];
        }
    }
}

int main() {
    int matrix[MAX][MAX], arr[MAX * MAX], n, m;

    // Input matrix dimensions
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

    // Store the matrix elements in the 1-D array row-wise
    storeRowWise(matrix, n, m, arr);

    // Print the 1-D array
    printf("The elements of the matrix in 1-D array row-wise are:\n");
    for (int i = 0; i < n * m; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
