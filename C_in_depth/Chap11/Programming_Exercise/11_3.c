//Write a program to display the total number of alphabets and numeric characters in file.

#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *file;
    char ch;
    int alphabets = 0, digits = 0;

    file = fopen("source.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    while ((ch = fgetc(file)) != EOF) {
        if (isalpha(ch)) {
            alphabets++;
        } else if (isdigit(ch)) {
            digits++;
        }
    }

    fclose(file);

    printf("Total alphabets: %d\n", alphabets);
    printf("Total numeric characters: %d\n", digits);

    return 0;
}
