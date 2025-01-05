// Rewrite the function lower, which converts upper case letters to lower case, with a conditional expression instead of if-else. 

#include <stdio.h>

// Function to convert uppercase letters to lowercase
int lower(int c) {
    // Use a conditional expression to check and convert
    return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c;
}

int main() {
    char upper = 'G';
    char lowerChar = lower(upper);
    printf("Original: %c, Lowercase: %c\n", upper, lowerChar);

    char nonUpper = 'g';
    char unchanged = lower(nonUpper);
    printf("Original: %c, Lowercase: %c\n", nonUpper, unchanged);

    return 0;
}
