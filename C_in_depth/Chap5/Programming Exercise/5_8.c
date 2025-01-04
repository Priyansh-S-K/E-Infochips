// Write a program to accept any number up to six digits and print that in words.
// For example- 1265 = one two six five
#include<stdio.h>
main()
{
    int num,n=100000;
    printf("Enter a number:");
    scanf("%d",&num);
    while(num/n==0)
    {
        n/=10;
    }
    while(n!=0)
    {
        dig2word(num/n);
        num-=n*(num/n);
        n/=10; 
    }
}

void dig2word(int n)
{
    switch(n)
    {
        case 0:
        printf("Zero\t");
        break;
        case 1:
        printf("One\t");
        break;
        case 2:
        printf("Two\t");
        break;
        case 3:
        printf("Three\t");
        break;
        case 4:
        printf("Four\t");
        break;
        case 5:
        printf("Five\t");
        break;
        case 6:
        printf("Six\t");
        break;
        case 7:
        printf("Seven\t");
        break;
        case 8:
        printf("Eight\t");
        break;
        case 9:
        printf("Nine\t");
        break;
    }
}