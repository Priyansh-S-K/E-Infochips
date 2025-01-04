//Write a program to count the occurrences of a number in a matrix.
#include <stdio.h>

#define MAX 10

int countOccurrences(int matrix[MAX][MAX], int n, int num) {
    int count = 0;

    // Loop through the matrix to count occurrences of num
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == num) {
                count++;
            }
        }
    }
    
    return count;
}

int main() {
    int matrix[MAX][MAX], n, num;

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

    // Input the number to count its occurrences
    printf("Enter the number to count its occurrences: ");
    scanf("%d", &num);

    // Count occurrences and print the result
    int count = countOccurrences(matrix, n, num);
    printf("The number %d occurs %d times in the matrix.\n", num, count);

    return 0;
}
