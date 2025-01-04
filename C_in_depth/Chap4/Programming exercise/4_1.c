//Enter the temperature in Celsius and convert that into Fahrenheit.
#include<stdio.h>
int main()
{
    float c,f;
    printf("Enter temp in celsius:");
    scanf("%f",&c);
    f=1.8*c+32;
    printf("Temp in fahrenheit: %f",f);
}