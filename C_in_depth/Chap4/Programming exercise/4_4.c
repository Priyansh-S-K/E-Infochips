//Accept any five digit number and print the value of remainder after dividing by 3.
#include<stdio.h>

main()
{
    int n;
    printf("Enter a five digit number: ");
    scanf("%d", &n);
    printf("Remainder after dividing by 3 is: %d", n%3);
    return 0;
}