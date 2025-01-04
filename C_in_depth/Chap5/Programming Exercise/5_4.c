//Write a program to accept any number n and print the sum of square of all numbers from 1 to
//n.
#include<stdio.h>
main()
{
    int n,sum=0;
    printf("Enter a number:");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        sum+=i*i;
    }
    //sum={n*(n+1)*(2*n+1)}/6;
    printf("Sum of squares:%d",sum);
}