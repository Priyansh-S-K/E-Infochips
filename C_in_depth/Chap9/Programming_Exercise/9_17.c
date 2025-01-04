//Write a program to input 5 lines of text and then store them as separate strings using array (
// pointers to strings

#include <stdio.h>

int main() {
    // Array of pointers to store 5 lines of text
    char *lines[5];
    char buffer[200];  // Buffer to read input

    // Input 5 lines of text
    for (int i = 0; i < 5; i++) {
        printf("Enter line %d: ", i + 1);
        fgets(buffer, sizeof(buffer), stdin);

        // Allocate memory for each line dynamically and store it in the array
        lines[i] = malloc(strlen(buffer) + 1);
        if (lines[i] != NULL) {
            strcpy(lines[i], buffer);  // Store the input string in the array
        }
    }

    // Display the stored lines
    printf("\nStored lines of text:\n");
    for (int i = 0; i < 5; i++) {
        printf("Line %d: %s", i + 1, lines[i]);
    }

    // Free dynamically allocated memory
    for (int i = 0; i < 5; i++) {
        free(lines[i]);
    }

    return 0;
}
