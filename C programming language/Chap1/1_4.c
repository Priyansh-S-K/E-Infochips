//Write a program to print the corresponding Celsius to Fahrenheit table. 

#include <stdio.h> 
  
main() 
{ 
    float fahr, celsius; 
    float lower, upper, step; 
    lower = 0;      /* lower limit of temperatuire scale */ 
    upper = 300;    /* upper limit */ 
    step = 20;      /* step size */ 
    celsius = lower; 
    printf("Fahrenheit\tCelsius\n");
    while (celsius <= upper) 
    { 
        fahr = (9.0/5.0) * celsius + 32; 
        printf("%3.0f\t\t%6.1f\n", celsius, fahr); 
        celsius = celsius + step; 
    } 
}