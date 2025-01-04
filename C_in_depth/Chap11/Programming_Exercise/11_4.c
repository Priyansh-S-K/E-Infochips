//Write a program to remove all comments from the file. Assume that a comment starts with double
//slash ( // ) and continues till the end of the line.

#include <stdio.h>

int main() {
    FILE *source, *destination;
    char ch, prev_ch = '\0';

    source = fopen("comment.txt", "r");
    if (source == NULL) {
        perror("Error opening source file");
        return 1;
    }

    destination = fopen("uncomment.txt", "w");
    if (destination == NULL) {
        perror("Error opening destination file");
        fclose(source);
        return 1;
    }

    while ((ch = fgetc(source)) != EOF) {
        if (prev_ch == '/' && ch == '/') {
            // Skip the rest of the line after "//"
            while ((ch = fgetc(source)) != EOF && ch != '\n');
        } else {
            fputc(prev_ch, destination);
        }
        prev_ch = ch;
    }

    // Write the last character (if it's not part of a comment)
    if (prev_ch != '\0') {
        fputc(prev_ch, destination);
    }

    fclose(source);
    fclose(destination);

    printf("Comments removed successfully.\n");

    return 0;
}
