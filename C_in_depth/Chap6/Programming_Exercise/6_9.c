//Write a recursive function to find the combinations of n objects taken l' at a time
#include <stdio.h>

// Recursive function to calculate combinations
int combinations(int n, int r) {
    // Base cases
    if (r == 0 || r == n) {
        return 1;
    }
    // Recursive case
    return combinations(n - 1, r - 1) + combinations(n - 1, r);
}

int main() {
    int n, r;

    // Input values for n and r
    printf("Enter the total number of objects (n): ");
    scanf("%d", &n);
    printf("Enter the number of objects to select (r): ");
    scanf("%d", &r);

    // Input validation
    if (r > n || n < 0 || r < 0) {
        printf("Invalid input! Ensure that 0 <= r <= n.\n");
        return 1;
    }

    // Calculate and display the result
    printf("C(%d, %d) = %d\n", n, r, combinations(n, r));

    return 0;
}
