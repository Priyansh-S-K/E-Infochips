//Write an alternative version of squeeze(s1,s2) that deletes each character in s1 that matches any character in the string s2.  

#include <stdio.h>

// Function to check if a character exists in a string
int char_in_string(char c, const char s[]) {
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == c) {
            return 1; // Character found
        }
    }
    return 0; // Character not found
}

// Alternative squeeze function
void squeeze_alt(char s1[], const char s2[]) {
    int i, j;

    // Iterate through s1 and remove characters that are in s2
    for (i = j = 0; s1[i] != '\0'; i++) {
        if (!char_in_string(s1[i], s2)) { // Keep if not in s2
            s1[j++] = s1[i];
        }
    }
    s1[j] = '\0'; // Null-terminate the modified string
}

int main() {
    char s1[] = "hello world";
    const char s2[] = "aeiou"; // Characters to remove

    printf("Original: %s\n", s1);
    squeeze_alt(s1, s2);
    printf("Modified: %s\n", s1);

    return 0;
}
