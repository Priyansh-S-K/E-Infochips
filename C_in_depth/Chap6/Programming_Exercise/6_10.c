// Write a program to print number in words using recursion. For example if we have a number
//31246, then the program should print "
//Three one Two four Six
#include <stdio.h>

// Array of digit words
const char *digits[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};

// Recursive function to print digits in words
void printInWords(int num) {
    if (num == 0) {
        return; // Base case: If the number becomes 0, stop recursion
    }

    // Process the preceding digits first
    printInWords(num / 10);

    // Print the last digit in words
    printf("%s ", digits[num % 10]);
}

int main() {
    int num;

    // Input a number
    printf("Enter a number: ");
    scanf("%d", &num);

    // Handle the case for 0 explicitly
    if (num == 0) {
        printf("Zero\n");
    } else {
        // Handle negative numbers
        if (num < 0) {
            printf("Minus ");
            num = -num; // Convert to positive
        }

        // Call the recursive function
        printInWords(num);
        printf("\n"); // Print a newline at the end
    }

    return 0;
}
