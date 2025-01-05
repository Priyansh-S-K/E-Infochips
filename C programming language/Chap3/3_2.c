//Write a function escape(s,t) that converts characters like newline and tab into visible escape sequences like \n and \t as it copies the string t to s. Use a switch. Write a function for the other direction as well, converting escape sequences into the real characters.

#include <stdio.h>

// Function to escape special characters like newline and tab
void escape(char s[], char t[]) {
    int i = 0, j = 0;
    while (t[i] != '\0') {
        switch (t[i]) {
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
            case '\\':
                s[j++] = '\\';
                s[j++] = '\\';
                break;
            default:
                s[j++] = t[i];
                break;
        }
        i++;
    }
    s[j] = '\0'; // Null-terminate the result string
}

// Function to unescape escape sequences like \n and \t
void unescape(char s[], char t[]) {
    int i = 0, j = 0;
    while (t[i] != '\0') {
        if (t[i] == '\\' && (t[i+1] == 'n' || t[i+1] == 't' || t[i+1] == '\\')) {
            switch (t[i+1]) {
                case 'n':
                    s[j++] = '\n';
                    break;
                case 't':
                    s[j++] = '\t';
                    break;
                case '\\':
                    s[j++] = '\\';
                    break;
            }
            i++; // Skip the next character after the escape
        } else {
            s[j++] = t[i];
        }
        i++;
    }
    s[j] = '\0'; // Null-terminate the result string
}

int main() {
    // Example for escape function
    char original[] = "Hello\nWorld\t!";
    char escaped[100];
    escape(escaped, original);
    printf("Escaped: %s\n", escaped);

    // Example for unescape function
    char unescaped[100];
    unescape(unescaped, escaped);
    printf("Unescaped: %s\n", unescaped);

    return 0;
}
