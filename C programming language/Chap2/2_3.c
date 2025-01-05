//Write a function htoi(s), which converts a string of hexadecimal digits (including an optional 0x or 0X) into its equivalent integer value. The allowable digits are 0 through 9, a through f, and A through F. 
#include <stdio.h>
#include <ctype.h>

int htoi(const char *s) {
    int result = 0; // Initialize the result
    int i = 0;      // Index for traversing the string

    // Skip optional "0x" or "0X"
    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
        i = 2; // Start after the prefix
    }

    // Convert each character
    while (s[i] != '\0') {
        int value = 0;

        if (isdigit(s[i])) { // Numeric digits (0-9)
            value = s[i] - '0';
        } else if (s[i] >= 'a' && s[i] <= 'f') { // Lowercase hex letters (a-f)
            value = s[i] - 'a' + 10;
        } else if (s[i] >= 'A' && s[i] <= 'F') { // Uppercase hex letters (A-F)
            value = s[i] - 'A' + 10;
        } else { // Invalid character
            printf("Invalid hexadecimal digit: %c\n", s[i]);
            return -1; // Return -1 for invalid input
        }

        // Accumulate the result
        result = result * 16 + value;
        i++;
    }

    return result;
}

int main() {
    // Test the function with different inputs
    const char *hex1 = "0x1A3F";
    const char *hex2 = "7b";
    const char *hex3 = "0Xff";
    const char *hex4 = "123";
    const char *hex5 = "g12"; // Invalid example

    printf("Hexadecimal %s to integer: %d\n", hex1, htoi(hex1));
    printf("Hexadecimal %s to integer: %d\n", hex2, htoi(hex2));
    printf("Hexadecimal %s to integer: %d\n", hex3, htoi(hex3));
    printf("Hexadecimal %s to integer: %d\n", hex4, htoi(hex4));
    printf("Hexadecimal %s to integer: %d\n", hex5, htoi(hex5));

    return 0;
}
