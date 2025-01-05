//Write a program to remove trailing blanks and tabs from each line of input, and to delete entirely blank lines. 

#include <stdio.h>

#define MAXLINE 1000  // Maximum input line size

int get_line(char line[], int maxline);
void remove_trailing_blanks(char line[]);

int main() {
    char line[MAXLINE];

    printf("Enter text :\n");

    while (get_line(line, MAXLINE) > 0) {
        remove_trailing_blanks(line);
        if (line[0] != '\0') {  // Skip entirely blank lines
            printf("%s\n", line);
        }
    }

    return 0;
}

// Reads a line into `s` and returns its length
int get_line(char s[], int maxline) {
    int c, i = 0;

    while (i < maxline - 1 && (c = getchar()) != EOF && c != '\n') {
        s[i++] = c;
    }

    if (c == '\n') {
        s[i++] = c;
    }

    s[i] = '\0';  // Null-terminate the string
    return i;
}

// Removes trailing blanks and tabs from a line
void remove_trailing_blanks(char s[]) {
    int i = 0;

    // Find the end of the string
    while (s[i] != '\0') {
        i++;
    }

    // Move backward to remove trailing blanks and tabs
    i--;
    while (i >= 0 && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')) {
        s[i] = '\0';
        i--;
    }
}
