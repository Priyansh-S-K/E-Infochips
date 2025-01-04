// Write a program mult() that accepts two integers and returns their product. Don't use the * operator.
//Similarly make two more functions quo( ) and rem( ) that accept two integers and return the quotient
//and remainder respectively, without the use of / and % operators.
#include <stdio.h>

// Function to calculate the product of two integers without using '*'
int mult(int a, int b) {
    int result = 0;
    int isNegative = (a < 0) ^ (b < 0); // Check if the result should be negative
    a = (a < 0) ? -a : a; // Make 'a' positive
    b = (b < 0) ? -b : b; // Make 'b' positive

    for (int i = 0; i < b; i++) {
        result += a;
    }

    return isNegative ? -result : result; // Apply the sign
}

// Function to calculate the quotient of two integers without using '/'
int quo(int dividend, int divisor) {
    if (divisor == 0) {
        printf("Division by zero is not allowed.\n");
        return 0;
    }

    int quotient = 0;
    int isNegative = (dividend < 0) ^ (divisor < 0); // Check if the result should be negative
    dividend = (dividend < 0) ? -dividend : dividend; // Make 'dividend' positive
    divisor = (divisor < 0) ? -divisor : divisor; // Make 'divisor' positive

    while (dividend >= divisor) {
        dividend -= divisor;
        quotient++;
    }

    return isNegative ? -quotient : quotient; // Apply the sign
}

// Function to calculate the remainder of two integers without using '%'
int rem(int dividend, int divisor) {
    if (divisor == 0) {
        printf("Division by zero is not allowed.\n");
        return 0;
    }

    int isNegative = dividend < 0; // Check if the remainder should be negative
    dividend = (dividend < 0) ? -dividend : dividend; // Make 'dividend' positive
    divisor = (divisor < 0) ? -divisor : divisor; // Make 'divisor' positive

    while (dividend >= divisor) {
        dividend -= divisor;
    }

    return isNegative ? -dividend : dividend; // Apply the sign
}

int main() {
    int a, b;

    // Test the mult() function
    printf("Enter two integers for multiplication: ");
    scanf("%d %d", &a, &b);
    printf("Product of %d and %d is: %d\n", a, b, mult(a, b));

    // Test the quo() function
    printf("Enter two integers for division (dividend and divisor): ");
    scanf("%d %d", &a, &b);
    printf("Quotient of %d and %d is: %d\n", a, b, quo(a, b));

    // Test the rem() function
    printf("Enter two integers for remainder (dividend and divisor): ");
    scanf("%d %d", &a, &b);
    printf("Remainder of %d and %d is: %d\n", a, b, rem(a, b));

    return 0;
}
