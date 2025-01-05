//Write a program entab that replaces strings of blanks by the minimum number of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab. When either a tab or a single blank would suffice to reach a tab stop, which should be given preference? 

/*
Tabs are preferred when they can align the position to a tab stop.
Remaining spaces are used when a tab stop cannot be perfectly aligned with a tab.
*/

#include <stdio.h>

#define TABSTOP 8  // Tab stop size; can be adjusted or made a variable

void entab(int tabstop);

int main() {
    printf("Enter text :\n");
    entab(TABSTOP);
    return 0;
}

// Replaces spaces with tabs and spaces based on tab stops
void entab(int tabstop) {
    int c, pos = 0, space_count = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            space_count++;
            if ((pos + space_count) % tabstop == 0) {
                putchar('\t');  // Insert a tab when a tab stop is reached
                space_count = 0;
            }
        } else {
            // Print remaining spaces
            for (int i = 0; i < space_count; i++) {
                putchar(' ');
            }
            space_count = 0;

            putchar(c);  // Print the non-space character
            pos++;

            if (c == '\n') {
                pos = 0;  // Reset position at the start of a new line
            }
        }

        // Update the current position
        if (c != '\n') {
            pos = (pos + space_count) % tabstop;
        }
    }
}
