//Write a program to enter a number and find the reverse of that number.
#include<stdio.h>
main()
{
    int a, inv=0,temp;
    printf("Enter a number:");
    scanf("%d",&a);
    while(a!=0)
    {
        temp=a%10;
        inv=inv*10+temp;
        a/=10;
    }
    printf("Inversed number:%d",inv);
}