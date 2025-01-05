//Write the function any(s1,s2), which returns the first location in a string s1 where any character from the string s2 occurs, or -1 if s1 contains no characters from s2. (The standard library function strpbrk does the same job but returns a pointer to the location.) 

#include <stdio.h>

// Function to find the first location in s1 where any character from s2 occurs
int any(const char s1[], const char s2[]) {
    for (int i = 0; s1[i] != '\0'; i++) { // Traverse s1
        for (int j = 0; s2[j] != '\0'; j++) { // Traverse s2
            if (s1[i] == s2[j]) { // Check for a match
                return i; // Return the first index of the match in s1
            }
        }
    }
    return -1; // Return -1 if no characters from s2 are found in s1
}

int main() {
    const char s1[] = "hello world";
    const char s2[] = "aeiou"; // Characters to search for

    int result = any(s1, s2);
    if (result != -1) {
        printf("First occurrence of any character from '%s' in '%s' is at index %d.\n", s2, s1, result);
    } else {
        printf("No characters from '%s' found in '%s'.\n", s2, s1);
    }

    return 0;
}
