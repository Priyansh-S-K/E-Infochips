//Write a program to check that the elements of an array are distinct.
#include <stdio.h>

#define MAX 100

int areDistinct(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                return 0; // Elements are not distinct
            }
        }
    }
    return 1; // Elements are distinct
}

int main() {
    int arr[MAX], n;

    // Input number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Input array elements
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Check and print if the elements are distinct
    if (areDistinct(arr, n)) {
        printf("All elements in the array are distinct.\n");
    } else {
        printf("The elements in the array are not distinct.\n");
    }

    return 0;
}
