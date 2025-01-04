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
        n=10*n+1;
    }
    printf("\nSum=%d",sum);
}