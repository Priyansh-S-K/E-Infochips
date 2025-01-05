//Write a program to print a histogram of the lengths of words in its input. It is easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging. 

#include <stdio.h>
#include <ctype.h>

int main() {
    int c, word_length = 0;
    int word_lengths[20] = {0};  // Array to store word length counts (up to 20 characters)

    while ((c = getchar()) != EOF) 
    {
        if (isspace(c)) 
        {
            if (word_length > 0) 
            {
                if (word_length < 20)
                    word_lengths[word_length]++;
                else
                    word_lengths[19]++;  // Count very long words as 19+
                word_length = 0;  // Reset for the next word
            }
        } 
        else 
        {
            word_length++;
        }
    }

    // Print horizontal histogram
    printf("Horizontal Histogram of Word Lengths:\n");
    for (int i = 1; i < 20; i++) 
    {
        printf("%2d: ", i);
        for (int j = 0; j < word_lengths[i]; j++) 
        {
            printf("#");
        }
        printf("\n");
    }

    return 0;
}
