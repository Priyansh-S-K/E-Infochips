//Write a program to accept a line oftext and print that text after removing all sI?aces and delimiters.

#include <stdio.h>
#include <ctype.h>

void removeSpacesAndDelimiters(char *str) {
    char *src = str, *dst = str;

    while (*src) {
        if (!isspace(*src) && !ispunct(*src)) {
            *dst = *src;
            dst++;
        }
        src++;
    }
    *dst = '\0'; // Null-terminate the modified string
}

int main() {
    char text[1000];

    // Input the text
    printf("Enter a line of text: ");
    fgets(text, sizeof(text), stdin);

    // Remove the trailing newline character
    text[strcspn(text, "\n")] = '\0';

    // Remove spaces and delimiters
    removeSpacesAndDelimiters(text);

    // Display the modified text
    printf("Text after removing spaces and delimiters: %s\n", text);

    return 0;
}
