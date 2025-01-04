//Write a function which replaces all the occurrences of a character from a string with another
// character. It should take three arguments, a string and two characters.

#include <stdio.h>

void replaceCharacter(char *str, char oldChar, char newChar) {
    while (*str) {
        if (*str == oldChar) {
            *str = newChar;
        }
        str++;
    }
}

int main() {
    char str[200], oldChar, newChar;

    // Input the string
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove the trailing newline character
    str[strcspn(str, "\n")] = '\0';

    // Input the characters
    printf("Enter the character to replace: ");
    scanf(" %c", &oldChar);
    printf("Enter the replacement character: ");
    scanf(" %c", &newChar);

    // Replace occurrences of oldChar with newChar
    replaceCharacter(str, oldChar, newChar);

    // Display the modified string
    printf("Modified string: %s\n", str);

    return 0;
}
