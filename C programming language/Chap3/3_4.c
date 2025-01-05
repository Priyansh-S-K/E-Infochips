//In a two's complement number representation, our version of itoa does not handle the largest negative number, that is, the value of n equal to -(2wordsize-1). Explain why not. Modify it to print that value correctly, regardless of the machine on which it runs. 

#include <stdio.h>
#include <limits.h> // For INT_MIN and INT_MAX

// Function to convert integer to string
void itoa(int n, char s[]) {
    int i = 0;
    int sign = n;

    // Handle the special case for the most negative number
    if (n == INT_MIN) {
        s[i++] = '-';
        n = -(n + 1);  // Make it a positive number and adjust to avoid overflow
    } else if (n < 0) {
        sign = -n;
        s[i++] = '-';
    }

    // Convert number to string
    int j = i;
    do {
        s[j++] = (sign % 10) + '0';
        sign /= 10;
    } while (sign > 0);

    s[j] = '\0';

    // Reverse the string to get the correct number representation
    int start = i, end = j - 1;
    while (start < end) {
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }
}

int main() {
    int num = INT_MIN;
    char str[20];
    itoa(num, str);
    printf("Integer: %d\n", num);
    printf("String: %s\n", str);
    return 0;
}
