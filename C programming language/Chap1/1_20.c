// Write a program detab that replaces tabs in the input with the proper number of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns. Should n be a variable or a symbolic parameter? 

/*
Should n Be a Variable or Symbolic Parameter?
Symbolic Parameter (#define):
Use when the tab stop is fixed and consistent across the program.
Variable:
Use when the tab stop needs to be dynamic or configurable by the user.
*/

#include <stdio.h>

#define TABSTOP 8  // Tab stop size; can be adjusted or made a variable

void detab(int tabstop);

int main() {
    printf("Enter text (Ctrl+D to end on Unix/Linux/Mac or Ctrl+Z on Windows):\n");
    detab(TABSTOP);
    return 0;
}

// Replaces tabs with spaces based on the tab stop
void detab(int tabstop) {
    int c, pos = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            int spaces = tabstop - (pos % tabstop);  // Calculate spaces to next tab stop
            for (int i = 0; i < spaces; i++) {
                putchar(' ');
                pos++;
            }
        } else {
            putchar(c);
            pos++;
            if (c == '\n') {
                pos = 0;  // Reset position at the start of a new line
            }
        }
    }
}
