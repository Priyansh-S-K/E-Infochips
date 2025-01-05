// Our binary search makes two tests inside the loop, when one would suffice (at the price of more tests outside.) Write a version with only one test inside the loop and measure the difference in run-time. 

#include <stdio.h>
#include <time.h>

// Original binary search with two tests inside the loop
int binary_search(int arr[], int size, int target) {
    int low = 0, high = size - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == target) {
            return mid; // Found target
        }
        if (arr[mid] < target) {
            low = mid + 1; // Move the lower bound up
        } else {
            high = mid - 1; // Move the upper bound down
        }
    }
    return -1; // Not found
}

// Optimized binary search with one test inside the loop
int binary_search_optimized(int arr[], int size, int target) {
    int low = 0, high = size - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        // Only one test: check if arr[mid] is equal to the target
        if (arr[mid] == target) {
            return mid; // Found target
        }

        // Adjust bounds based on the target
        low = (arr[mid] < target) ? mid + 1 : low;
        high = (arr[mid] > target) ? mid - 1 : high;
    }

    return -1; // Not found
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17};
    int target = 7;
    int size = sizeof(arr) / sizeof(arr[0]);

    // Measure run-time for original binary search
    clock_t start, end;
    start = clock();
    int result = binary_search(arr, size, target);
    end = clock();
    double time_spent_original = (double)(end - start) / CLOCKS_PER_SEC;

    // Measure run-time for optimized binary search
    start = clock();
    result = binary_search_optimized(arr, size, target);
    end = clock();
    double time_spent_optimized = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Original Binary Search took %f seconds\n", time_spent_original);
    printf("Optimized Binary Search took %f seconds\n", time_spent_optimized);

    if (result != -1) {
        printf("Found at index %d\n", result);
    } else {
        printf("Not found\n");
    }

    return 0;
}
