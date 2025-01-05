//Write a program to print all input lines that are longer than 80 characters.

#include <stdio.h>

#define MAXLINE 1000   // Maximum input line size
#define THRESHOLD 80   // Minimum line length to print

int get_line(char line[], int maxline);

int main() {
    char line[MAXLINE];

    printf("Enter text :\n");

    while (get_line(line, MAXLINE) > 0) {
        if (strlen(line) > THRESHOLD) {
            printf("%s", line);
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
