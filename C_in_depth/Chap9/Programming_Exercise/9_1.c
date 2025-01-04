//Write a function for performing case insensitive string comparison.
#include <stdio.h>
#include <ctype.h>

// Function for case-insensitive string comparison
int caseInsensitiveCompare(const char *str1, const char *str2) {
    while (*str1 && *str2) {
        if (tolower(*str1) != tolower(*str2)) {
            return tolower(*str1) - tolower(*str2);
        }
        str1++;
        str2++;
    }
    return tolower(*str1) - tolower(*str2);
}

int main() {
    char str1[100], str2[100];

    // Input two strings
    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);

    // Remove trailing newline characters
    str1[strcspn(str1, "\n")] = '\0';
    str2[strcspn(str2, "\n")] = '\0';

    // Compare the strings
    int result = caseInsensitiveCompare(str1, str2);
    if (result == 0) {
        printf("The strings are equal (case insensitive).\n");
    } else if (result < 0) {
        printf("The first string is less than the second (case insensitive).\n");
    } else {
        printf("The first string is greater than the second (case insensitive).\n");
    }

    return 0;
}
