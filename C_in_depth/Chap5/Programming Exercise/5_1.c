//Write a program to print prime numbers from 1 to 99.
#include<stdio.h>
#include<math.h>
main()
{
    for(int i=2;i<100;i++)
    {
        int flag=0;
        for(int j=2;j<=sqrt(i);j++)
        {
            if(i%j==0)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            printf("%d ",i);
        }
    }
}