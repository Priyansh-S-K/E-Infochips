//Accepts marks in five subject and calculate the total percentage marks.
#include<stdio.h>
main()
{
    int marks[5],i,sum=0;
    float per;
    printf("Enter marks in five subjects:\n");
    for(i=0;i<5;i++)
    {
        printf("Subject %d: ",i+1);
        scanf("%d",&marks[i]);
    }
    for(i=0;i<5;i++)
    {
        sum=sum+marks[i];
    }
    per=((float)sum/500)*100;
    printf("Total percentage marks: %.2f\n",per);
}