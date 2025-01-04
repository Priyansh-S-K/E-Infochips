// Write a function which deletes all the occurrences of a character from a string. It should take
// two arguments, a string and a character.

#include <stdio.h>

void deleteCharacter(char *str, char delChar) {
    char *src = str, *dst = str;

    while (*src) {
        if (*src != delChar) {
            *dst = *src;
            dst++;
        }
        src++;
    }
    *dst = '\0'; // Null-terminate the modified string
}

int main() {
    char str[200], delChar;

    // Input the string
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove the trailing newline character
    str[strcspn(str, "\n")] = '\0';

    // Input the character to delete
    printf("Enter the character to delete: ");
    scanf(" %c", &delChar);

    // Delete occurrences of the character
    deleteCharacter(str, delChar);

    // Display the modified string
    printf("Modified string: %s\n", str);

    return 0;
}
