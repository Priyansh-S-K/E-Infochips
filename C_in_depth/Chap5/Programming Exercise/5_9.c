//Write a program to enter a number and test whether it is a fibonacci number or not.
#include<stdio.h>
main()
{
    int num;
    printf("Enter a number:");
    scanf("%d",&num);
    if(chkfib(num))
        printf("The number is fibonacci");
    else
        printf(" The number is not fibonacci");
}

int chkfib(int n)
{
    if(n==0 || n==1)
        return 1;
    int t1=1, t2=1, t3=1;
    
    while(t3<n)
    {
        t3=t1+t2;
        t1=t2;
        t2=t3;
        if(n==t3)
            return 1;
    }
    return 0;
}