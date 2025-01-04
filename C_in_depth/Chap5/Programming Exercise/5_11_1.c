//Find the sum of these series up to n terms where x is an integer entered by the user.
#include<stdio.h>

main()
{
    int num,n=1,sum=0;
    printf("Enter a number:");
    scanf("%d",&num);
    for(int i=1;i<=num;i++)
    {
        sum+=n;
        printf("%d\t",n);
        n+=i;
    }
    printf("\nSum=%d",sum);
}