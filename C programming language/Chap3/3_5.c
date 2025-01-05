//Write the function itob(n,s,b) that converts the integer n into a base b character representation in the string s. In particular, itob(n,s,16) formats s as a hexadecimal integer in s.  

#include <stdio.h>

void itob(int n, char s[], int b) {
    int i = 0, sign = n;

    // Handle the case for zero explicitly
    if (n == 0) {
        s[i++] = '0';
    }
    
    // Handle negative numbers by converting to positive for base conversion
    if (n < 0) {
        n = -n;
    }

    // Convert integer to string in base b
    while (n > 0) {
        int digit = n % b;
        if (digit < 10) {
            s[i++] = digit + '0';  // For digits 0-9
        } else {
            s[i++] = digit - 10 + 'a';  // For digits a-f (hexadecimal)
        }
        n /= b;
    }

    // If the number was negative, add the minus sign
    if (sign < 0) {
        s[i++] = '-';
    }

    s[i] = '\0';  // Null-terminate the string

    // Reverse the string to get the correct order
    int start = 0, end = i - 1;
    while (start < end) {
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }
}

int main() {
    int n = -255;
    char s[50];

    itob(n, s, 16);  // Convert to hexadecimal
    printf("Hexadecimal: %s\n", s);

    itob(n, s, 2);  // Convert to binary
    printf("Binary: %s\n", s);

    itob(n, s, 10);  // Convert to decimal
    printf("Decimal: %s\n", s);

    return 0;
}
