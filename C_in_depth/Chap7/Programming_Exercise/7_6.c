// Write a program to find out the determinant of a matrix.
#include <stdio.h>

#define MAX 10

// Function to find the determinant of a matrix
int determinant(int matrix[MAX][MAX], int n) {
    int det = 0, temp[MAX][MAX], sign = 1;
    
    // Base case: if the matrix is 1x1
    if (n == 1) {
        return matrix[0][0];
    }
    
    // Loop through the first row to calculate cofactor expansion
    for (int f = 0; f < n; f++) {
        // Get the cofactor matrix
        int i = 0, j = 0;
        for (int row = 1; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (col != f) {
                    temp[i][j++] = matrix[row][col];
                    if (j == n - 1) {
                        j = 0;
                        i++;
                    }
                }
            }
        }

        // Calculate the determinant using cofactor expansion
        det += sign * matrix[0][f] * determinant(temp, n - 1);

        // Alternate signs
        sign = -sign;
    }

    return det;
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

    // Find and print the determinant
    printf("The determinant of the matrix is: %d\n", determinant(matrix, n));

    return 0;
}
