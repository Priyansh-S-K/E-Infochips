//Write a function expand(s1,s2) that expands shorthand notations like a-z in the string s1 into the equivalent complete list abc...xyz in s2. Allow for letters of either case and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing - is taken literally. 

#include <stdio.h>
#include <ctype.h>

// Function to expand shorthand notations
void expand(char s1[], char s2[]) {
    int i = 0, j = 0;
    
    while (s1[i] != '\0') {
        // If the current character is a dash '-'
        if (s1[i] == '-') {
            // Handle cases like leading or trailing '-'
            if (i == 0 || s1[i+1] == '\0') {
                s2[j++] = '-'; // Take '-' literally
            }
            // Handle ranges like a-z, 0-9
            else if (isalnum(s1[i-1]) && isalnum(s1[i+1])) {
                char start = s1[i-1];
                char end = s1[i+1];
                
                // Ensure that the range is valid (start should be <= end)
                if (start <= end) {
                    for (char c = start + 1; c < end; c++) {
                        s2[j++] = c; // Add the characters in the range
                    }
                }
            }
            i++; // Skip over the dash for next iteration
        } else {
            s2[j++] = s1[i++]; // Copy other characters as they are
        }
    }

    s2[j] = '\0'; // Null-terminate the result string
}

int main() {
    char s1[] = "a-z0-9";
    char s2[100]; // Buffer for expanded result
    expand(s1, s2);
    printf("Expanded: %s\n", s2);

    // Test cases with different ranges
    char s3[] = "a-b-c";
    expand(s3, s2);
    printf("Expanded: %s\n", s2);

    char s4[] = "-a-z";
    expand(s4, s2);
    printf("Expanded: %s\n", s2);

    char s5[] = "1-5-9";
    expand(s5, s2);
    printf("Expanded: %s\n", s2);

    return 0;
}
