// Write a program to ``fold'' long input lines into two or more shorter lines after the last non-blank character that occurs before the n-th column of input. Make sure your program does something intelligent with very long lines, and if there are no blanks or tabs before the specified column. 

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXLINE 1000  // Maximum input line size
#define FOLDLIMIT 80  // Column width to fold lines at

void fold_line(char line[], int fold_limit);

int main() {
    char line[MAXLINE];
    int len;

    printf("Enter text :\n");

    while (fgets(line, MAXLINE, stdin)) {
        fold_line(line, FOLDLIMIT);
    }

    return 0;
}

// Fold a single line into shorter lines
void fold_line(char line[], int fold_limit) {
    int len = strlen(line);
    int pos = 0, last_space = -1, start = 0;

    while (pos < len) {
        // Track the last space or tab before the fold limit
        if (line[pos] == ' ' || line[pos] == '\t') {
            last_space = pos;
        }

        // If we've reached the fold limit or the end of the line
        if ((pos - start >= fold_limit && last_space != -1) || pos == len - 1) {
            if (last_space == -1 || pos == len - 1) {
                // If no spaces or tabs were found, break at the fold limit
                last_space = pos == len - 1 ? pos + 1 : start + fold_limit;
            }

            // Print up to the last space/tab or the fold limit
            for (int i = start; i < last_space; i++) {
                putchar(line[i]);
            }
            putchar('\n');

            // Move to the next line
            start = (line[last_space] == ' ' || line[last_space] == '\t') ? last_space + 1 : last_space;
            last_space = -1;
        }

        pos++;
    }
}
