// Write a function cubesum( ) that accepts an integer and returns the sum ofthe cubes of individual
//digits of that number. Use this program to print Armstrong numbers in a given range. (See program
//P5.24)
#include<stdio.h>
int cubesum(int n)
{
    int sum=0;
    while(n>0)
    {
        int r=n%10;
        sum=sum+r*r*r;
        n=n/10;
    }
    return sum;
}

main( )
{
    int num,sum;
    printf ("Armstrong numbers are :\n") ;
    for(num=100;num<=999;num++)
    {
        sum=cubesum(num);
        if (num==sum)
            printf("%d\n",num);
    }
    
} 
