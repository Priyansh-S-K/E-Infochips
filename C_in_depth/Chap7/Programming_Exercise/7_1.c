//Write a program to accept n numbers and display the sum of the highest and lowest numbers
#include <stdio.h>

int main() {
    int n, i, sum;
    
    // Input the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Number of elements should be greater than zero.\n");
        return 1; // Exit with an error
    }

    int numbers[n];  // Array to store the numbers

    // Input the numbers into the array
    printf("Enter %d numbers:\n", n);
    for (i = 0; i < n; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    // Initialize highest and lowest
    int highest = numbers[0];
    int lowest = numbers[0];

    // Find the highest and lowest number
    for (i = 1; i < n; i++) {
        if (numbers[i] > highest) {
            highest = numbers[i];
        }
        if (numbers[i] < lowest) {
            lowest = numbers[i];
        }
    }

    // Calculate the sum of highest and lowest numbers
    sum = highest + lowest;

    // Display the result
    printf("Highest number: %d\n", highest);
    printf("Lowest number: %d\n", lowest);
    printf("Sum of highest and lowest numbers: %d\n", sum);

    return 0;
}
