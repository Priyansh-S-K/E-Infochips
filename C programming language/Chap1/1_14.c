//Write a program to print a histogram of the frequencies of different characters in its input. 

#include <stdio.h>

#define NUM_CHARS 128  // Number of ASCII characters to consider

int main() {
    int c;
    int char_freq[NUM_CHARS] = {0};  // Array to store character frequencies

    // Read input and count character frequencies
    while ((c = getchar()) != EOF) {
        if (c >= 0 && c < NUM_CHARS) {
            char_freq[c]++;
        }
    }

    // Print the histogram
    printf("\nHistogram of Character Frequencies:\n");
    for (int i = 0; i < NUM_CHARS; i++) {
        if (char_freq[i] > 0) {  // Only print characters with non-zero frequency
            if (i == '\n') {
                printf("\\n: ");
            } else if (i == '\t') {
                printf("\\t: ");
            } else if (i == ' ') {
                printf("sp: ");  // Represent spaces as "sp"
            } else {
                printf(" %c: ", i);
            }

            // Print a bar for the character's frequency
            for (int j = 0; j < char_freq[i]; j++) {
                putchar('#');
            }
            putchar('\n');
        }
    }

    return 0;
}
