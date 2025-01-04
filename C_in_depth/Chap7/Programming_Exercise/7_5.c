// Write a_program to modify the elements of an array such that the last element becomes the first
 //element of the array and all other elements are shifted to right.
 //123456789-7 9 12 34 5 678
 #include <stdio.h>

void shiftRight(int arr[], int n) {
    int temp = arr[n - 1];
    
    for (int i = n - 2; i >= 0; i--) {
        arr[i + 1] = arr[i];
    }
    
    arr[0] = temp;
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

    shiftRight(arr, n);

    printf("Array after shifting: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
