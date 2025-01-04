#include<stdio.h>
main()
{
    int i, suml=0, sum2=0;
    for(i=1;i<5;i++)
        suml+=i;
    i=1;
    while(i<5)
    {
        i++;
        sum2+=i;
    }
    printf ("%d %d\n",i,suml,sum2) ;
}