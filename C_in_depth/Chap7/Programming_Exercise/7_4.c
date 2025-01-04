//Write a function to reverse only first n elements of an array.
#include <stdio.h>

void reverseFirstNElements(int arr[], int n) {
    int temp, i;
    for (i = 0; i < n / 2; i++) {
        temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}

int main() {
    int n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d numbers:\n", n);
    for (i = 0; i < n; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int k;
    printf("Enter the number of elements to reverse: ");
    scanf("%d", &k);

    reverseFirstNElements(arr, k);

    printf("Array after reversing first %d elements: ", k);
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
