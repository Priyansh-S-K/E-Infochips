/*Write a program to encode text and to decode the encoded text.
 (i)

 Perform the encoding so that every character is replaced by its next character. For example
 replace a by b, b by c and so on. Replace z by a.

 (ii)

 Perform the encoding according to these replacements
abcdefghijklmnopqrstuvwxyz 
 mnkghdtabwvuprqczjvieyflos
Plain text: program
 Encoded text :cjqtjmp
 Decoded text :program
*/

#include <stdio.h>
#include <string.h>

// Function to encode the text by shifting each character to the next one
void encodeShiftByOne(char *text) {
    while (*text) {
        if (*text == 'z') {
            *text = 'a';
        } else if (*text == 'Z') {
            *text = 'A';
        } else if ((*text >= 'a' && *text < 'z') || (*text >= 'A' && *text < 'Z')) {
            (*text)++;
        }
        text++;
    }
}

// Function to decode the encoded text by shifting each character back to the previous one
void decodeShiftByOne(char *text) {
    while (*text) {
        if (*text == 'a') {
            *text = 'z';
        } else if (*text == 'A') {
            *text = 'Z';
        } else if ((*text > 'a' && *text <= 'z') || (*text > 'A' && *text <= 'Z')) {
            (*text)--;
        }
        text++;
    }
}

// Function to encode text based on custom character mapping
void encodeCustom(char *text, char *map) {
    while (*text) {
        if (*text >= 'a' && *text <= 'z') {
            *text = map[*text - 'a'];
        } else if (*text >= 'A' && *text <= 'Z') {
            *text = map[*text - 'A'] - 32; // convert to lowercase
        }
        text++;
    }
}

// Function to decode text based on custom character mapping
void decodeCustom(char *text, char *map) {
    char reverseMap[26];
    for (int i = 0; i < 26; i++) {
        reverseMap[map[i] - 'a'] = 'a' + i;
    }

    while (*text) {
        if (*text >= 'a' && *text <= 'z') {
            *text = reverseMap[*text - 'a'];
        } else if (*text >= 'A' && *text <= 'Z') {
            *text = reverseMap[*text - 'A'] - 32; // convert to lowercase
        }
        text++;
    }
}

int main() {
    char text[100], encodedText[100], decodedText[100];
    char map[26] = {'m', 'n', 'k', 'g', 'h', 'd', 't', 'a', 'b', 'w', 'v', 'u', 'p', 'r', 'q', 'c', 'z', 'j', 'v', 'i', 'e', 'y', 'f', 'l', 'o', 's'};

    // Get the text for encoding
    printf("Enter plain text for shift encoding: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0'; // Remove newline character

    strcpy(encodedText, text);
    encodeShiftByOne(encodedText);
    printf("Encoded text (shift by one): %s\n", encodedText);
    decodeShiftByOne(encodedText);
    printf("Decoded text (shift by one): %s\n", encodedText);

    // Get the text for custom encoding
    printf("\nEnter plain text for custom encoding: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0'; // Remove newline character

    strcpy(encodedText, text);
    encodeCustom(encodedText, map);
    printf("Encoded text (custom mapping): %s\n", encodedText);

    strcpy(decodedText, encodedText);
    decodeCustom(decodedText, map);
    printf("Decoded text (custom mapping): %s\n", decodedText);

    return 0;
}
