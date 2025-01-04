//Write a program to find out the roots of quadratic equation ax2 + bx + c = O.
#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c; // Coefficients of the quadratic equation
    double discriminant, root1, root2, realPart, imaginaryPart;

    // Input coefficients
    printf("Enter coefficients a, b, and c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    // Check if it's a valid quadratic equation
    if (a == 0) {
        printf("This is not a quadratic equation.\n");
        return 1;
    }

    // Calculate the discriminant
    discriminant = b * b - 4 * a * c;

    // Find roots based on the discriminant
    if (discriminant > 0) {
        // Two real and distinct roots
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("The roots are real and distinct:\n");
        printf("Root 1 = %.2lf\n", root1);
        printf("Root 2 = %.2lf\n", root2);
    } else if (discriminant == 0) {
        // Two real and equal roots
        root1 = -b / (2 * a);
        printf("The roots are real and equal:\n");
        printf("Root 1 = Root 2 = %.2lf\n", root1);
    } else {
        // Complex roots
        realPart = -b / (2 * a);
        imaginaryPart = sqrt(-discriminant) / (2 * a);
        printf("The roots are complex and distinct:\n");
        printf("Root 1 = %.2lf + %.2lfi\n", realPart, imaginaryPart);
        printf("Root 2 = %.2lf - %.2lfi\n", realPart, imaginaryPart);
    }

    return 0;
}
