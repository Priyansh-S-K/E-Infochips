// Write a program to accept the number in decimal and print the number in octal and hexadecimal
#include <stdio.h>
int main()
{
    int a;
    printf("Enter a number in decimal: ");
    scanf("%d", &a);
    printf("The number in octal is: %o\n", a);
    printf("The number in hexadecimal is: %x\n", a);
    return 0;
}
