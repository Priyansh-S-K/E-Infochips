#include<stdio.h>
main()
{
    int n,sum=0;
    for(;;)
    {
        scanf("%d", &n);
        sum+=n;
        if(sum>100)
            break;
    }
}