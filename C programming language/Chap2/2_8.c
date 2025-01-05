//Write a function rightrot(x,n) that returns the value of the integer x rotated to the right by n positions.  

#include <stdio.h>

// Function to determine the number of bits in an unsigned integer
unsigned int num_bits() {
    return sizeof(unsigned) * 8; // Size of unsigned in bytes * 8 (bits per byte)
}

// Function to rotate x to the right by n positions
unsigned rightrot(unsigned x, int n) {
    unsigned int bits = num_bits(); // Total bits in unsigned integer

    // Ensure n is within a valid range (handle rotations larger than bit width)
    n = n % bits;

    // Perform the rotation:
    // 1. Shift x right by n bits
    // 2. Shift the n rightmost bits of x to the leftmost position
    // 3. Combine the results with bitwise OR
    unsigned rotated = (x >> n) | (x << (bits - n));

    return rotated;
}

int main() {
    unsigned x = 0b11011101; // Example: binary 221
    int n = 3;               // Number of positions to rotate

    unsigned result = rightrot(x, n);

    printf("Original: 0b%08b\n", x);
    printf("Rotated:  0b%08b\n", result);
    return 0;
}
