// Write a program to copy a file to another file such that blank lines are not written to the new file..

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int is_blank_line(const char *line) {
    while (*line) {
        if (*line != ' ' && *line != '\t' && *line != '\n') {
            return 0;
        }
        line++;
    }
    return 1;
}

int main() {
    FILE *source, *destination;
    char line[MAX_LINE_LENGTH];

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

    while (fgets(line, sizeof(line), source)) {
        if (!is_blank_line(line)) {
            fputs(line, destination);
        }
    }

    fclose(source);
    fclose(destination);

    printf("File copied successfully, excluding blank lines.\n");

    return 0;
}
