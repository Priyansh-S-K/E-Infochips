// Write a functi9n sumdiv( ) that finds the sum ofdivisors ofa number. (Divisors ofa number are
//those numbers by which the number is divisible). For example divisors of 36 are 1, 2, 3, 4, 6,
//9, 18. A number is called perfect if the sum of divisors of that number is equal to the number.
//For example 28 is a perfect number, since 1+2+4+7+14 =28. Write a programto print all the perfect
//numbers in·a given range.

#include <stdio.h>

// Function to calculate the sum of divisors of a number
int sumdiv(int n) 
{
    int sum = 0;
    for (int i = 1; i <= n / 2; i++) 
    {
        if (n % i == 0) 
        { // If 'i' is a divisor
            sum += i;
        }
    }
    return sum;
}

// Function to print all perfect numbers in a given range
void printPerfectNumbers(int start, int end) 
{
    printf("Perfect numbers between %d and %d are:\n", start, end);
    for (int i = start; i <= end; i++) 
    {
        if (i == sumdiv(i)) 
        { // Check if the number is perfect
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() 
{
    int start, end;

    // Input range
    printf("Enter the starting number of the range: ");
    scanf("%d", &start);
    printf("Enter the ending number of the range: ");
    scanf("%d", &end);

    // Print perfect numbers in the range
    printPerfectNumbers(start, end);

    return 0;
}
