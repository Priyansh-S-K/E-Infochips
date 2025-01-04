//Write a program to input text and replace all the occurrences of word "Calcutta" by "Kolkata"
// in that text.

#include <stdio.h>
#include <string.h>

void replaceWord(char *text, const char *oldWord, const char *newWord) {
    char buffer[1000];
    char *pos, *temp = text;
    int oldLen = strlen(oldWord);
    int newLen = strlen(newWord);

    buffer[0] = '\0'; // Initialize buffer as empty

    while ((pos = strstr(temp, oldWord)) != NULL) {
        // Copy characters from the current position to the word occurrence
        strncat(buffer, temp, pos - temp);
        // Append the new word to the buffer
        strcat(buffer, newWord);
        // Move the temp pointer beyond the old word
        temp = pos + oldLen;
    }

    // Append the remaining text after the last occurrence
    strcat(buffer, temp);

    // Copy the modified text back to the original string
    strcpy(text, buffer);
}

int main() {
    char text[1000];

    // Input the text
    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);

    // Remove the trailing newline character
    text[strcspn(text, "\n")] = '\0';

    // Replace "Calcutta" with "Kolkata"
    replaceWord(text, "Calcutta", "Kolkata");

    // Display the modified text
    printf("Modified text: %s\n", text);

    return 0;
}
