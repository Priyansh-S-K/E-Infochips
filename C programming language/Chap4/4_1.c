//Write the function strindex(s,t) which returns the position of the rightmost occurrence of t in s, or -1 if there is none. 

#include <stdio.h>
#include <string.h>

int strindex(const char s[], const char t[]) {
    int i, j, k;

    // Get the length of s and t
    int len_s = strlen(s);
    int len_t = strlen(t);

    // Start from the end of s and move backwards
    for (i = len_s - len_t; i >= 0; i--) {
        // Check if substring starting at i matches t
        for (j = 0; j < len_t; j++) {
            if (s[i + j] != t[j]) {
                break;
            }
        }

        // If we have matched all characters of t, return the position
        if (j == len_t) {
            return i;
        }
    }

    // If no match is found, return -1
    return -1;
}

int main() {
    const char s[] = "This is a simple test string for testing.";
    const char t[] = "test";

    int position = strindex(s, t);
    if (position != -1) {
        printf("Rightmost occurrence of '%s' is at index %d\n", t, position);
    } else {
        printf("'%s' not found in '%s'\n", t, s);
    }

    return 0;
}
