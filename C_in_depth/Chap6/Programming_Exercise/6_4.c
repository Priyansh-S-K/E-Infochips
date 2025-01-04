//Write a program to find the sum of this series upto n terms.
//1 + 1 / 2 + 1 / 4 + 1 / 9 + 1 / 16 +

#include <stdio.h>

int main() 
{
    int n;
    double sum = 0.0;

    // Input the number of terms
    printf("Enter the number of terms (n): ");
    scanf("%d", &n);

    // Calculate the sum of the series
    for (int i = 1; i <= n; i++) 
    {
        sum += 1.0 / (i * i); // Add 1 / i^2 to the sum
    }

    // Output the result
    printf("The sum of the series up to %d terms is: %.6f\n", n, sum);

    return 0;
}

 