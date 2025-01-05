//Write a function setbits(x,p,n,y) that returns x with the n bits that begin at position p set to the rightmost n bits of y, leaving the other bits unchanged.  

#include <stdio.h>

// Function to set n bits of x at position p to the rightmost n bits of y
unsigned setbits(unsigned x, int p, int n, unsigned y) {
    // Step 1: Create a mask to isolate n bits of x starting at position p
    unsigned mask = (~(~0 << n)) << (p + 1 - n);

    // Step 2: Clear these bits in x
    x &= ~mask;

    // Step 3: Extract the rightmost n bits of y
    unsigned y_bits = y & ~(~0 << n);

    // Step 4: Shift these bits into position and combine with x
    x |= (y_bits << (p + 1 - n));

    return x;
}

int main() {
    unsigned x = 0b11011101; // Example: binary 221
    unsigned y = 0b00000111; // Example: binary 7
    int p = 4;               // Starting position (0-based from the right)
    int n = 3;               // Number of bits to replace

    unsigned result = setbits(x, p, n, y);

    printf("Result: 0b%08b\n", result); // Display result in binary
    return 0;
}
