// Write a program'to accept the principal, rate, and number ofyears and find out the simple interest.
#include<stdio.h>
main()
{
    float p,r,n,si;
    printf("Enter the principal amount:");
    scanf("%f",&p);
    printf("Enter the rate of interest:");
    scanf("%f",&r);
    printf("Enter the number of years:");
    scanf("%f",&n);
    si=(p*r*n)/100;
    printf("The simple interest is:%f",si);
}