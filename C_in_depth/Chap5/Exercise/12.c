#include<stdio.h>
main()
{
    int i,j,x=0;
    for(i=0;i<5;i++)
        for(j=i;j>0;j--)
            x=i+j+1;
    printf("x=%d\n",x);
}