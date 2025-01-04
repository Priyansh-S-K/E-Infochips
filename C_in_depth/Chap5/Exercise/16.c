#include<stdio.h>
main()
{
    int i, sum;
    for(i=0;i<10;i+=3)
        sum +=i*i;
    printf("%d",sum);
}