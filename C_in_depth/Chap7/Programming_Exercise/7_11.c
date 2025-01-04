//Write a program to check that the elements of a matrix are distinct.
#include <stdio.h>

#define MAX 10

int areElementsDistinct(int matrix[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = i; k < n; k++) {
                for (int l = (k == i) ? j + 1 : 0; l < n; l++) {
                    if (matrix[i][j] == matrix[k][l]) {
                        return 0; // Elements are not distinct
                    }
                }
            }
        }
    }
    return 1; // All elements are distinct
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

    // Check and print whether the elements are distinct
    if (areElementsDistinct(matrix, n)) {
        printf("All elements in the matrix are distinct.\n");
    } else {
        printf("The elements in the matrix are not distinct.\n");
    }

    return 0;
}
