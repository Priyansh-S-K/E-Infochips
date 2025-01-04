//not working
#include<stdio.h>

main()
{
    int num;
    float n,n1,sum=0;
    printf("Enter a limit:");
    scanf("%f",&num);
    printf("Enter x:");
    scanf("%f",&n1);
    n=1/n1;
    for(int i=1;i<=num;i++)
    {
        sum+=n;
        printf("%f\t",n);
        n/=(-n1);
    }
    printf("\nSum=%d",sum);
}