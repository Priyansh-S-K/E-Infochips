//Write a program to accept any six digit number and print the sum ofall evendigits ofthat number
//and multiplication of all odd digits.
#include<stdio.h>
main()
{
    int num,mul=1,sum=0;
    printf("Enter a six digit number:");
    scanf("%d",&num);
    for(int i=0;i<3;i++)
    {
        mul*=(num%10);
        num/=10;
        sum+=(num%10);
        num/=10;
    }
    printf("Sum=%d   Mul=%d",sum,mul);
}