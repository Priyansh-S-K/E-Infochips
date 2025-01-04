//Write a program to findout the value ofx raised to the power y, where x and y are positive integers.
#include<stdio.h>
main()
{
    int x,y,result=1;
    printf("Enter x:");
    scanf("%d",&x);
    printf("Enter y:");
    scanf("%d",&y);
    for(int i=0;i<y;i++)
    {
        result*=x;
    }
    printf("x raised to the power of y: %d",result);
}