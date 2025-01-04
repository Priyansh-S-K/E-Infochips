//Write a program to sort numbers of a one-d array in descending order using
 //(i) selection sort (ii) bubble sort (iii) insertion sort
 #include <stdio.h>

void selectionSort(int arr[], int n) {
    int i, j, temp, maxIdx;
    
    for (i = 0; i < n-1; i++) {
        maxIdx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] > arr[maxIdx]) {
                maxIdx = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[maxIdx];
        arr[maxIdx] = temp;
    }
}

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] < arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void insertionSort(int arr[], int n) {
    int i, key, j;
    
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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

    // Selection Sort
    selectionSort(arr, n);
    printf("Selection Sorted array in descending order: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Input the numbers again for Bubble Sort and Insertion Sort
    printf("Enter %d numbers again for sorting: \n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Bubble Sort
    bubbleSort(arr, n);
    printf("Bubble Sorted array in descending order: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Input the numbers again for Insertion Sort
    printf("Enter %d numbers again for sorting: \n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Insertion Sort
    insertionSort(arr, n);
    printf("Insertion Sorted array in descending order: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
