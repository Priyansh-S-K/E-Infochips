//Write a loop equivalent to the for loop above without using && or ||.  

/*
Original for loop
for (int i = 0; i < 10 && i != 5; i++) {
    printf("%d\n", i);
}
*/
main()
{
    int i = 0;
    while (i < 10) 
    {
        if (i == 5) 
        {
           break; // Exit the loop if i equals 5
        }
        printf("%d\n", i);
        i++;
    }
}