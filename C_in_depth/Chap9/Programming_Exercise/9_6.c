// Write a program to accept a line of text and a word. Display the number of occurrences of that
// word in the text.

#include <stdio.h>
#include <string.h>

int countWordOccurrences(const char *text, const char *word) {
    int count = 0;
    int wordLen = strlen(word);
    const char *ptr = text;

    while ((ptr = strstr(ptr, word)) != NULL) {
        // Check if the match is a whole word
        if ((ptr == text || *(ptr - 1) == ' ') && (*(ptr + wordLen) == ' ' || *(ptr + wordLen) == '\0')) {
            count++;
        }
        ptr += wordLen; // Move past the current match
    }

    return count;
}

int main() {
    char text[500], word[50];

    // Input the line of text
    printf("Enter a line of text: ");
    fgets(text, sizeof(text), stdin);

    // Remove the trailing newline character
    text[strcspn(text, "\n")] = '\0';

    // Input the word to search for
    printf("Enter the word to search for: ");
    fgets(word, sizeof(word), stdin);

    // Remove the trailing newline character
    word[strcspn(word, "\n")] = '\0';

    // Count occurrences of the word
    int occurrences = countWordOccurrences(text, word);

    // Display the result
    printf("The word '%s' occurs %d times in the text.\n", word, occurrences);

    return 0;
}
