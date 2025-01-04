// Write a function to extract a substring from a string. Assume that the substring stallS at the ith
// character and is n characters long.

#include <stdio.h>
#include <string.h>

void extractSubstring(char *str, int i, int n, char *substring) {
    // Ensure that i is within the bounds of the string
    if (i >= 0 && i < strlen(str)) {
        int j = 0;
        // Extract n characters starting from the ith position
        while (j < n && str[i + j] != '\0') {
            substring[j] = str[i + j];
            j++;
        }
        substring[j] = '\0'; // Null-terminate the substring
    } else {
        substring[0] = '\0'; // If the starting index is out of bounds, return an empty string
    }
}

int main() {
    char str[200], substring[200];
    int i, n;

    // Input the string
    printf("Enter the string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove the trailing newline character

    // Input the starting index and length of the substring
    printf("Enter the starting index (i): ");
    scanf("%d", &i);
    printf("Enter the length of the substring (n): ");
    scanf("%d", &n);

    // Extract the substring
    extractSubstring(str, i, n, substring);

    // Display the extracted substring
    printf("Extracted substring: %s\n", substring);

    return 0;
}
