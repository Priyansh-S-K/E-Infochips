//Experiment to find out what happens when prints's argument string contains \c, where c is some character not listed above.

#include <stdio.h> 
main() 
{ 
    printf("hello, "); 
    printf("world\c"); 
    printf("\n"); 
} 