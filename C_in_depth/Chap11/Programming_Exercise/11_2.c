//Write a program to convert all the lower case characters of a file to upper case.

#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *source, *destination;
    char ch;

    source = fopen("source.txt", "r");
    if (source == NULL) {
        perror("Error opening source file");
        return 1;
    }

    destination = fopen("destination.txt", "w");
    if (destination == NULL) {
        perror("Error opening destination file");
        fclose(source);
        return 1;
    }

    while ((ch = fgetc(source)) != EOF) {
        fputc(toupper(ch), destination);
    }

    fclose(source);
    fclose(destination);

    printf("File converted successfully to uppercase.\n");

    return 0;
}
