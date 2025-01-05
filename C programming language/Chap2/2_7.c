//Write a function invert(x,p,n) that returns x with the n bits that begin at position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.  

#include <stdio.h>

// Function to invert n bits of x starting at position p
unsigned invert(unsigned x, int p, int n) {
    // Step 1: Create a mask with n bits set to 1 at position p
    unsigned mask = (~(~0 << n)) << (p + 1 - n);

    // Step 2: XOR x with the mask to invert the desired bits
    x ^= mask;

    return x;
}

int main() {
    unsigned x = 0b11011101; // Example: binary 221
    int p = 4;               // Starting position (0-based from the right)
    int n = 3;               // Number of bits to invert

    unsigned result = invert(x, p, n);

    printf("Original: 0b%08b\n", x);
    printf("Result:   0b%08b\n", result); // Display result in binary
    return 0;
}
