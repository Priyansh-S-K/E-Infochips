//Accept any two numbers, if the first number is greater than second then print the sum of these
//two numbers, otherwise print their difference. Write this program using ternary operator.
#include<stdio.h>
int main()
{
    int a,b;
    printf("Enter first number: ");
    scanf("%d",&a);
    printf("Enter second number: ");
    scanf("%d",&b);
    printf("%d",a>b?a+b:b-a);
    return 0;
}