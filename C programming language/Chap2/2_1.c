//Write a program to determine the ranges of char, short, int, and long variables, both signed and unsigned, by printing appropriate values from standard headers and by direct computation. Harder if you compute them: determine the ranges of the various floating-point types. 

#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>

// Function to compute the range of signed integers
void compute_signed_range(int bits, long long *min, long long *max) {
    *max = (1LL << (bits - 1)) - 1; // 2^(n-1) - 1
    *min = -(1LL << (bits - 1));    // -2^(n-1)
}

// Function to compute the range of unsigned integers
void compute_unsigned_range(int bits, unsigned long long *max) {
    *max = (1ULL << bits) - 1;      // 2^n - 1
}

int main() {
    printf("Using <limits.h>:\n");
    printf("Signed char range: %d to %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("Unsigned char range: 0 to %u\n", UCHAR_MAX);
    printf("Signed short range: %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("Unsigned short range: 0 to %u\n", USHRT_MAX);
    printf("Signed int range: %d to %d\n", INT_MIN, INT_MAX);
    printf("Unsigned int range: 0 to %u\n", UINT_MAX);
    printf("Signed long range: %ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("Unsigned long range: 0 to %lu\n", ULONG_MAX);
    printf("\n");

    printf("Using direct computation:\n");

    long long min, max;
    unsigned long long umax;

    // Char
    compute_signed_range(8, &min, &max);
    printf("Signed char range: %lld to %lld\n", min, max);
    compute_unsigned_range(8, &umax);
    printf("Unsigned char range: 0 to %llu\n", umax);

    // Short
    compute_signed_range(16, &min, &max);
    printf("Signed short range: %lld to %lld\n", min, max);
    compute_unsigned_range(16, &umax);
    printf("Unsigned short range: 0 to %llu\n", umax);

    // Int
    compute_signed_range(32, &min, &max);
    printf("Signed int range: %lld to %lld\n", min, max);
    compute_unsigned_range(32, &umax);
    printf("Unsigned int range: 0 to %llu\n", umax);

    // Long
    compute_signed_range(sizeof(long) * 8, &min, &max);
    printf("Signed long range: %lld to %lld\n", min, max);
    compute_unsigned_range(sizeof(long) * 8, &umax);
    printf("Unsigned long range: 0 to %llu\n", umax);

    printf("\nFloating-point ranges using <float.h>:\n");
    printf("Float range: %.10e to %.10e\n", FLT_MIN, FLT_MAX);
    printf("Double range: %.10e to %.10e\n", DBL_MIN, DBL_MAX);
    printf("Long double range: %.10Le to %.10Le\n", LDBL_MIN, LDBL_MAX);

    return 0;
}
