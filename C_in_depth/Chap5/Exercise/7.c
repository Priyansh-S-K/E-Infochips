#include<stdio.h>
main()
{
    int a=5;
    begin:
    if(a)
        printf("%d\t",a);
    a--;
    goto begin;
}