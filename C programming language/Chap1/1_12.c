//Write a program that prints its input one word per line. 

#include <stdio.h>
#include <ctype.h>

int main() {
    int c;

    while ((c = getchar()) != EOF) {
        if (isspace(c)) {
            putchar('\n');  // Print newline for each whitespace
        } else {
            putchar(c);     // Print the character
        }
    }

    return 0;
}
