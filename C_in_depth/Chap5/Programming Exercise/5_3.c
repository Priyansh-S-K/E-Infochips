//Input a number and a digit and find whether the digit is present in the number or not, if present
//then count the number of times it occurs in the number.
#include<stdio.h>
main()
{
    int num,n,temp,count=0;
    printf("Enter a number:");
    scanf("%d",&num);
    printf("Enter a digit:");
    scanf("%d",&n);
    while(num!=0)
    {
        temp=num%10;
        if(temp==n)
            count++;
        num/=10;
    }
    if(count==0)
        printf("Digit not found in the given number.");
    else
        printf("Digit found %d times in the given number.",count);
}