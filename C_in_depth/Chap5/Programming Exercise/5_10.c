//Write a program to print all the pythagorean triplets less than 50. Any three numbers x, y, z are
//called pythagorean triplets if x < y < z and x2+y2 = z2
#include<stdio.h>

main()
{
    int a,b,c=0;
    int m=2;
    while(c<50)
    {
        for(int n=1;n<m;n++)
        {
            a=m*m-n*n;
            b=2*m*n;
            c=m*m+n*n;
            if(c>50)
                break;
            printf("%d %d %d\n",a,b,c);
        }
        m++;
    }
}