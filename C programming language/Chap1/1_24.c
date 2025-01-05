//Write a program to check a C program for rudimentary syntax errors like unmatched parentheses, brackets and braces. Don't forget about quotes, both single and double, escape sequences, and comments. (This program is hard if you do it in full generality.) 

#include <stdio.h>

#define MAXSTACK 1000

// Stack to track opening symbols
char stack[MAXSTACK];
int top = -1;

// Push a character onto the stack
void push(char c) {
    if (top < MAXSTACK - 1) {
        stack[++top] = c;
    }
}

// Pop a character from the stack
char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return '\0';  // Return null if stack is empty
}

// Check for matching pairs
int is_matching_pair(char opening, char closing) {
    return (opening == '(' && closing == ')') ||
           (opening == '{' && closing == '}') ||
           (opening == '[' && closing == ']');
}

void check_syntax();

int main() {
    printf("Enter the C program :\n");
    check_syntax();
    return 0;
}

// Function to check syntax errors
void check_syntax() {
    int c, prev = 0;
    int line = 1, error = 0;
    int in_comment = 0, in_string = 0, in_char = 0;

    while ((c = getchar()) != EOF) {
        // Track line numbers
        if (c == '\n') {
            line++;
        }

        // Handle comments
        if (!in_string && !in_char) {
            if (prev == '/' && c == '*') {
                in_comment = 1;
            }
            if (prev == '*' && c == '/' && in_comment) {
                in_comment = 0;
                c = 0;  // Ignore closing comment symbol
            }
        }

        // Handle strings
        if (!in_comment && !in_char && c == '"' && prev != '\\') {
            in_string = !in_string;
        }

        // Handle character constants
        if (!in_comment && !in_string && c == '\'' && prev != '\\') {
            in_char = !in_char;
        }

        // Process symbols for syntax checking
        if (!in_comment && !in_string && !in_char) {
            if (c == '(' || c == '{' || c == '[') {
                push(c);
            } else if (c == ')' || c == '}' || c == ']') {
                char opening = pop();
                if (!is_matching_pair(opening, c)) {
                    printf("Syntax error: Unmatched '%c' at line %d\n", c, line);
                    error = 1;
                }
            }
        }

        prev = c;  // Update previous character
    }

    // Check for unclosed symbols
    while (top >= 0) {
        printf("Syntax error: Unmatched '%c' at end of input\n", stack[top--]);
        error = 1;
    }

    if (!error) {
        printf("No syntax errors detected.\n");
    }
}
