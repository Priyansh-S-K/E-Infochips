// Write a recursive function to find the sum of digits of a number.


#include <stdio.h>

// Recursive function to calculate the sum of digits of a number
int sumOfDigits(int num) {
    if (num == 0) {
        return 0; // Base case: if the number is 0, return 0
    }
    return (num % 10) + sumOfDigits(num / 10); // Add the last digit and recurse
}

int main() {
    int num;

    // Input the number
    printf("Enter a number: ");
    scanf("%d", &num);

    // Handle negative numbers
    if (num < 0) {
        num = -num;
    }

    // Call the recursive function
    printf("The sum of digits is: %d\n", sumOfDigits(num));

    return 0;
}
