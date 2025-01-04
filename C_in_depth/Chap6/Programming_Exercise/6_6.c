// Write a function that accepts a character in lower case and returns its upper case equivalent.
#include <stdio.h>

// Function to convert a lowercase character to uppercase
char toUpperCase(char ch) {
    if (ch >= 'a' && ch <= 'z') { // Check if the character is lowercase
        return ch - ('a' - 'A'); // Convert to uppercase
    }
    return ch; // If not lowercase, return the character as is
}

int main() {
    char lower, upper;

    // Input the lowercase character
    printf("Enter a lowercase character: ");
    scanf("%c", &lower);

    // Call the function
    upper = toUpperCase(lower);

    // Output the uppercase equivalent
    printf("The uppercase equivalent is: %c\n", upper);

    return 0;
}
