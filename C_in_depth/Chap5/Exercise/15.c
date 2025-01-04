#include<stdio.h>
main()
{
    int i=1;
    while(i<10)
    {
        if(i==3)
            continue;
        printf("%d   ",i);
        i++;
    }
}