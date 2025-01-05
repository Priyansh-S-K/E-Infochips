//Write a function reverse(s) that reverses the character string s. Use it to write a program that reverses its input a line at a time.  

#include <stdio.h>
#include <string.h>

#define MAXLINE 1000  // Maximum input line size

void reverse(char s[]);
int get_line(char line[], int maxline);

int main() {
    char line[MAXLINE];

    printf("Enter text :\n");

    while (get_line(line, MAXLINE) > 0) {
        reverse(line);
        printf("%s\n", line);
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
        s[i++] = c;  // Include the newline character in the string
    }

    s[i] = '\0';  // Null-terminate the string
    return i;
}

// Reverses the string `s`
void reverse(char s[]) {
    int start = 0, end = strlen(s) - 1;

    // Exclude the newline character if present
    if (s[end] == '\n') {
        end--;
    }

    // Swap characters from both ends until the middle
    while (start < end) {
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }
}
