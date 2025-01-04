//Write a program to accept a line oftext and display the number ofconsonants and spaces in that line of text.

#include <stdio.h>
#include <ctype.h>

void countConsonantsAndSpaces(const char *line, int *consonants, int *spaces) {
    *consonants = 0;
    *spaces = 0;

    while (*line) {
        if (isalpha(*line)) {
            char ch = tolower(*line);
            if (ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u') {
                (*consonants)++;
            }
        } else if (*line == ' ') {
            (*spaces)++;
        }
        line++;
    }
}

int main() {
    char line[200];
    int consonants, spaces;

    // Input the line of text
    printf("Enter a line of text: ");
    fgets(line, sizeof(line), stdin);

    // Remove the trailing newline character
    line[strcspn(line, "\n")] = '\0';

    // Count consonants and spaces
    countConsonantsAndSpaces(line, &consonants, &spaces);

    // Display the results
    printf("Number of consonants: %d\n", consonants);
    printf("Number of spaces: %d\n", spaces);

    return 0;
}
