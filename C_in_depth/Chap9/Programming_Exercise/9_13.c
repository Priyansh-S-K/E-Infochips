//Write a program to abbreviate input text. For example ifthe input is "World Health Organization",
// then the output should be WHO.
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void abbreviate(char *text) {
    // Print the first character of the string in uppercase
    printf("%c", toupper(text[0]));

    // Loop through the string and print the first letter of each word
    for (int i = 1; text[i] != '\0'; i++) {
        if (text[i-1] == ' ' && text[i] != ' ') {
            printf("%c", toupper(text[i]));
        }
    }

    printf("\n");
}

int main() {
    char text[200];

    // Input the text
    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);

    // Remove the trailing newline character
    text[strcspn(text, "\n")] = '\0';

    // Call the abbreviation function
    abbreviate(text);

    return 0;
}
