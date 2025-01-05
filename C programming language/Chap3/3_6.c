//Write a version of itoa that accepts three arguments instead of two. The third argument is a minimum field width; the converted number must be padded with blanks on the left if necessary to make it wide enough.

#include <stdio.h>

void itoa_with_width(int n, char s[], int width) {
    int i = 0, sign = n;

    // Handle the case for zero explicitly
    if (n == 0) {
        s[i++] = '0';
    }
    
    // Handle negative numbers by converting to positive for base conversion
    if (n < 0) {
        n = -n;
        s[i++] = '-';  // Add the negative sign
    }

    // Convert integer to string
    int j = i;
    while (n > 0) {
        s[j++] = (n % 10) + '0';
        n /= 10;
    }

    // If number is zero, add '0' at the first position
    if (j == i) {
        s[j++] = '0';
    }

    s[j] = '\0';  // Null-terminate the string

    // Reverse the string to get the correct order
    int start = i, end = j - 1;
    while (start < end) {
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }

    // Calculate how much padding is needed
    int len = j;
    if (len < width) {
        // Shift the string to the right to make space for padding
        for (int k = len; k >= 0; k--) {
            s[k + (width - len)] = s[k];
        }

        // Fill the padding with spaces
        for (int k = 0; k < (width - len); k++) {
            s[k] = ' ';
        }
    }
}

int main() {
    int num = -42;
    char str[50];
    itoa_with_width(num, str, 8);  // Convert to string with width of 8
    printf("Result: '%s'\n", str);  // The output should be padded with spaces

    return 0;
}
