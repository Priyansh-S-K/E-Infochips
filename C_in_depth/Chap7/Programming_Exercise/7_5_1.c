// Now modify tile'above program so that we can rotate the array by any number of elements.
#include <stdio.h>

void rotateArray(int arr[], int n, int k) {
    int temp[k];

    // Store first k elements in temp array
    for (int i = 0; i < k; i++) {
        temp[i] = arr[n-k+i];
    }

    // Shift remaining elements to the right
    for (int i = n-k-1; i>=0; i--) {
        arr[i + k] = arr[i];
    }

    // Copy the k elements from temp to the end of the array
    for (int i = 0; i < k; i++) {
        arr[i] = temp[i];
    }
}

int main() {
    int n, k, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d numbers:\n", n);
    for (i = 0; i < n; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Enter the number of positions to rotate: ");
    scanf("%d", &k);

    // Ensure k is within the array bounds
    k = k % n;

    rotateArray(arr, n, k);

    printf("Array after rotating by %d positions: ", k);
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
