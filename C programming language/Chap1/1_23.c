//Write a program to remove all comments from a C program. Don't forget to handle quoted strings and character constants properly. C comments don't nest.  

#include <stdio.h>

#define IN_COMMENT 1
#define OUT_COMMENT 0

void remove_comments();

int main() {
    printf("Enter the C program :\n");
    remove_comments();
    return 0;
}

// Function to remove comments from a C program
void remove_comments() {
    int c, prev;
    int state = OUT_COMMENT;
    int in_string = 0, in_char = 0;

    prev = 0;  // Store previous character

    while ((c = getchar()) != EOF) {
        if (state == OUT_COMMENT) {
            // Check for start of a comment
            if (c == '/' && prev == '/') {
                state = IN_COMMENT;  // Line comment starts
            } else if (c == '*' && prev == '/') {
                state = IN_COMMENT;  // Block comment starts
            } else {
                // Handle quoted strings
                if (c == '"' && !in_char) {
                    in_string = !in_string;
                }
                // Handle character constants
                if (c == '\'' && !in_string) {
                    in_char = !in_char;
                }
                // Print character unless part of a comment
                if (prev && !(prev == '/' && (c == '/' || c == '*'))) {
                    putchar(prev);
                }
            }
        } else if (state == IN_COMMENT) {
            // Handle end of block comments
            if (c == '/' && prev == '*') {
                state = OUT_COMMENT;
                c = 0;  // Suppress printing the end of the comment
            }
            // Handle end of line comments
            if (c == '\n' && prev != '*') {
                state = OUT_COMMENT;
                putchar('\n');  // Add newline after line comment
            }
        }

        prev = c;  // Update previous character
    }

    // Print the last character if not part of a comment
    if (state == OUT_COMMENT && prev && !in_string && !in_char) {
        putchar(prev);
    }
}
