//Write a program to accept n numbers in array and display the addition of all even numbers and
//.multiplication of all odd numbers.
#include <stdio.h>

int main() {
    int n, i;
    int sumEven = 0, productOdd = 1;
    int hasOdd = 0; // To check if there is at least one odd number

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int numbers[n];

    printf("Enter %d numbers:\n", n);
    for (i = 0; i < n; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    for (i = 0; i < n; i++) {
        if (numbers[i] % 2 == 0) {
            sumEven += numbers[i];  // Add even numbers
        } else {
            productOdd *= numbers[i];  // Multiply odd numbers
            hasOdd = 1;
        }
    }

    printf("Sum of even numbers: %d\n", sumEven);

    if (hasOdd) {
        printf("Product of odd numbers: %d\n", productOdd);
    } else {
        printf("No odd numbers entered, product is 0.\n");
    }

    return 0;
}
