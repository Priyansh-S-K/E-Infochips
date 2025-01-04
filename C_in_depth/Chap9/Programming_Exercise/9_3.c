//Write a function that searches for a character in the string and returns the number ofoccurrences
// of that character in the string. It should take two arguments, first a string and then a character.

#include <stdio.h>

int countOccurrences(const char *str, char ch) {
    int count = 0;

    while (*str) {
        if (*str == ch) {
            count++;
        }
        str++;
    }

    return count;
}

int main() {
    char str[200], ch;

    // Input the string
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove the trailing newline character
    str[strcspn(str, "\n")] = '\0';

    // Input the character to search for
    printf("Enter the character to search for: ");
    scanf(" %c", &ch);

    // Count occurrences of the character
    int occurrences = countOccurrences(str, ch);

    // Display the result
    printf("The character '%c' occurs %d times in the string.\n", ch, occurrences);

    return 0;
}
