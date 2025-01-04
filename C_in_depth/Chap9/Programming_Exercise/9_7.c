//Write a function to remove all the leading and trailing blanks from a string.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void trimBlanks(char *str) {
    char *start = str;
    char *end;

    // Move the start pointer to the first non-blank character
    while (*start && isspace(*start)) {
        start++;
    }

    // If the string is all blanks
    if (*start == '\0') {
        *str = '\0';
        return;
    }

    // Move the end pointer to the last non-blank character
    end = start + strlen(start) - 1;
    while (end > start && isspace(*end)) {
        end--;
    }

    // Null-terminate the string after the last non-blank character
    *(end + 1) = '\0';

    // Shift the trimmed string to the beginning of the array
    memmove(str, start, end - start + 2);
}

int main() {
    char str[200];

    // Input the string
    printf("Enter a string with leading and trailing blanks: ");
    fgets(str, sizeof(str), stdin);

    // Remove the trailing newline character
    str[strcspn(str, "\n")] = '\0';

    // Trim the leading and trailing blanks
    trimBlanks(str);

    // Display the trimmed string
    printf("Trimmed string: \"%s\"\n", str);

    return 0;
}
