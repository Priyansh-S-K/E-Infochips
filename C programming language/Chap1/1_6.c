//Verify that the expression getchar() != EOF is 0 or 1.
 #include <stdio.h> 
   /* copy input to output;  2nd version  */ 
main() 
{ 
   int c; 
   while (c = getchar() != EOF) 
           putchar(c); 
}