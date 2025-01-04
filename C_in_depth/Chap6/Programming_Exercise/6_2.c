//Write a function that inputs a number and returns the product of digits of that number until the
//product is reduced to one digit ( like P5.25). The number of times digits need to be multiplied
//to reach one digit is called the persistence of the number. Write another function pers( )to input
//a number and return its persistence
#include<stdio.h>
int prod(int n)
{
    int s=1, dig;
    while(n!=0)
    {
        dig=n%10;
        s*=dig;
        n/=10;
    }       
    return s;
}
int pers(int num)
{
    int count=0;
    while (num >= 10) 
    {
        num = prod(num);
        count++;
    }
    return count;     
}
main()
{
    int num,temp;
    printf ("Enter a number:");
    scanf("%d",&num);
    printf("%d->",num);
    temp=num;
    while(temp>10)
    {
      temp=prod(temp);
      printf("%d\t",temp); 
    }
    printf("\n");
    printf("Persistence of %d is %d\n",num,pers(num));
}