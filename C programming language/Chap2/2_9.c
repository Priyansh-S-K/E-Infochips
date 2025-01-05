// In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit in x. Explain why. Use this observation to write a faster version of bitcount.

/*
Why x &= (x - 1) Deletes the Rightmost 1-Bit
In a two's complement number system:

Binary Representation:

The two's complement representation of an integer x represents negative numbers by inverting the bits of the absolute value and adding 1.
Bit Manipulation of x - 1:

Subtracting 1 from x flips all bits from the least significant bit (LSB) up to the first 1 (inclusive).
For example, consider x = 0b101100:
x - 1 = 0b101011.
Effect of x & (x - 1):

Performing x & (x - 1) clears the rightmost 1 bit in x:
Original: 
𝑥=0𝑏101100
x=0b101100
𝑥−1=0𝑏101011
x−1=0b101011
𝑥&(𝑥−1)=0𝑏101000
x&(x−1)=0b101000
This happens because x - 1 flips all bits starting from the rightmost 1, and the & operation zeros out the rightmost 1 while leaving the other bits unchanged.
*/

#include <stdio.h>

// Faster version of bitcount using x &= (x - 1)
int bitcount(unsigned x) {
    int count = 0;

    // Repeat until x becomes 0
    while (x) {
        x &= (x - 1); // Clear the rightmost 1-bit
        count++;
    }

    return count;
}

int main() {
    unsigned x = 0b101100; // Example: binary 44
    printf("Number of 1 bits in %u (binary %08b): %d\n", x, bitcount(x));
    return 0;
}
