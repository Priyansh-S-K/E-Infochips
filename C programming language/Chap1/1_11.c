//How would you test the word count program? What kinds of input are most likely to uncover bugs if there are any?

/*To test a word count program, you need to consider various types of input that test its ability to accurately count words, lines, and characters under different scenarios. Here’s a systematic approach:

Key Areas to Test
Basic Functionality:
Input with standard sentences, spaces, and newlines.
Edge Cases:
Empty input.
Input with only spaces, tabs, or newlines.
Boundary Conditions:
Single word input.
Input with one character or one line.
Complex Input:
Input with multiple spaces, tabs, and newlines between words.
Input with special characters or punctuation.
Non-ASCII Characters:
Input with Unicode characters, such as emojis or accented letters.
Large Input:
Very large text files to test performance and memory handling.
Irregular Spacing:
Consecutive spaces, tabs, or a combination of spaces and tabs.
Specific Test Inputs
1. Basic Input
Input: Hello world
Expected Output: Words: 2, Lines: 1, Characters: 11
2. Empty Input
Input: ``
Expected Output: Words: 0, Lines: 0, Characters: 0
3. Input with Only Spaces
Input:
Expected Output: Words: 0, Lines: 0, Characters: 4
4. Single Word
Input: Word
Expected Output: Words: 1, Lines: 1, Characters: 4
5. Punctuation
Input: Hello, world!
Expected Output: Words: 2, Lines: 1, Characters: 13
6. Irregular Spacing
Input: Hello world\n\nThis\tis\ta\ttest
Expected Output: Words: 5, Lines: 3, Characters: 26
7. Unicode Input
Input: Hello 🌍 世界
Expected Output: Words: 3, Lines: 1, Characters: 14 (depending on encoding).
8. Large Input
Input: Text file with millions of lines and words.
Expected Output: Correct count and reasonable performance.
9. Newlines Only
Input: \n\n\n
Expected Output: Words: 0, Lines: 3, Characters: 3
10. Mixed Whitespace
Input: \t \n \t
Expected Output: Words: 0, Lines: 1 (or more depending on interpretation), Characters: 5
Debugging with Test Cases
Write test cases as input files or direct input for interactive programs.
Compare program output against expected results.
Use tools like diff or scripting languages (e.g., Python) to automate validation for large-scale tests.
Tools for Testing
Shell Scripting: Automate input-output comparison.
Mock Input Files: Test diverse cases.
Memory Profiling Tools: Check for leaks or inefficiencies with large inputs.*/

#include <stdio.h> 
#define IN   1  /* inside a word */ 
#define OUT  0  /* outside a word */ 
   /* count lines, words, and characters in input */ 
main() 
{  
    int c, nl, nw, nc, state; 
    state = OUT; 
    nl = nw = nc = 0; 
    while ((c = getchar()) != EOF) 
    { 
        ++nc; 
        if (c == '\n') 
           ++nl; 
        if (c == ' ' || c == '\n' || c == '\t') 
           state = OUT; 
        else if (state == OUT) 
        { 
           state = IN; 
           ++nw; 
        } 
    } 
       printf("%d %d %d\n", nl, nw, nc); 
}