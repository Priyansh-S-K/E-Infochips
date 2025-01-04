// Input a string and change it so that the characters are placed in alphabetical order. For example
// the string "motivate" should be changed to "aeimotv"

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to sort the characters of the string in alphabetical order
void sortStringAlphabetically(char *str) {
    int length = strlen(str);

    // Simple Bubble Sort algorithm for sorting the characters
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (str[j] > str[j + 1]) {
                // Swap the characters if they are in the wrong order
                char temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
}

int main() {
    char str[200];

    // Input the string
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove the trailing newline character
    str[strcspn(str, "\n")] = '\0';

    // Sort the string alphabetically
    sortStringAlphabetically(str);

    // Display the sorted string
    printf("Sorted string: %s\n", str);

    return 0;
}
