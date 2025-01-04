//Accept the radius of the circle and calculate the area and perimeter of the circle.
#include<stdio.h>
main()
{
    float r;
    printf("Enter radius:");
    scanf("%f",&r);
    printf("Area of circle = %.2f\n",3.14*r*r);
    printf("Perimeter of circle = %.2f\n",2*3.14*r);

}