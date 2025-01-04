#include<stdio.h>

main()
{
    int num,n,n1,sum=0;
    printf("Enter a number:");
    scanf("%d",&num);
    printf("Enter x:");
    scanf("%d",&n1);
    n=n1;
    for(int i=1;i<=num;i++)
    {
        sum+=n;
        printf("%d\t",n);
        n*=n1;
    }
    printf("\nSum=%d",sum);
}